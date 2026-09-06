#include "systems/NetworkTCP.hpp"
#include "components/Exception.hpp"
#include "components/Unremovable.hpp"
#include "Network.hpp"
#include "AException.hpp"
#include "entities/ComponentManager.hpp"
#include "singleton/ECManager.hpp"
#include "MediatorClient.hpp"

rtype::system::NetworkTCPReader::NetworkTCPReader()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKTCPREADER]: CTOR" << std::endl;
    auto &ecMan = rtype::singleton::ECManager::get();
    bool is_created = true;

    //tcp socket
    try {
        auto s = ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>();
        _s = s.second;    
    } catch (rtype::component::Exception &e) {
        is_created = false;
    }
    if (!is_created) {
        //create
        std::cout << "socketCreation" << std::endl;
        auto io = ecMan._cMan.getComponentFromType<rtype::component::IOService>();
        auto _newSock = std::shared_ptr<rtype::component::SocketTCP>(new rtype::component::SocketTCP(io.second->_ioService));
        ecMan.createEntity(Signature(rtype::idBitset::idSocketTCP), _newSock);
        _s = _newSock;
    }

    is_created = true;
    
    //queue
    try {
        auto s = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();
        _queue_mssg = s.second;    
        _queueId = s.first;
    } catch (rtype::component::Exception &e) {
        is_created = false;
    }
    if (!is_created) {
        //create
        std::cout << "queueCreation" << std::endl;
        auto queue = std::shared_ptr<rtype::component::QueueMessageRecvClient>(new rtype::component::QueueMessageRecvClient());
        std::string id = ecMan.createEntity(Signature(rtype::idBitset::idQueueMessageRecvClient), queue);
        _queue_mssg = queue;
        _queueId = id;

        auto pair = ecMan._cMan.getComponentFromType<rtype::component::Unremovable>();
        pair.second->entities.push_back(id);
    }

    std::cout << "after ctor" << std::endl;

    //throw if not exists
}

int rtype::system::NetworkTCPReader::readHeader()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKTCPREADER]: readHeader" << std::endl;
    boost::system::error_code ec;
    std::array<int, 1> array;
    size_t read_bytes = _s->_socket.read_some(boost::asio::buffer(array, sizeof(int)), ec); //size in byte

    if (ec || read_bytes != sizeof(int)) {
        throw rtype::NetworkException("TCP read header: error occured");
    }
    int val = *(array.data());

    return val;
}

bool rtype::system::NetworkTCPReader::readMessage()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKTCPREADER]: readMessage" << std::endl;
    if (!_s->_socket.available())
        return false;
    
    boost::system::error_code ec;
    boost::asio::streambuf receive_buffer;

    int message_type = readHeader();
    size_t size_to_read = 0;

    // std::cout << "messageType: " << message_type <<  std::endl;

    if (message_type == rtype::network::MessageTypeServer::ENDPOINT_S) {
        size_to_read = sizeof(rtype::network::EndpointMssg) - sizeof(int);
    }
    if (message_type == rtype::network::MessageTypeServer::ENDGAME) {
        size_to_read = sizeof(rtype::network::EndGameMssg) - sizeof(int);
    }
    

    //maybe have to handle quit
    std::vector<char> message(size_to_read);

    size_t read_bytes = _s->_socket.read_some(boost::asio::buffer(message.data(), size_to_read), ec); //size in byte

    if (read_bytes != size_to_read) {
        //throw 
        throw rtype::NetworkException("TCP read message: bytes has not been read");
    }
    
    _queue_mssg->_messages.push({message_type, std::string(message.data(), read_bytes)});
    
    return true;
}

void rtype::system::NetworkTCPReader::update(const Entity &id)
{
    // std::cout << "update window" << std::endl;
    //check if socket is open
    if (!_s->_socket.is_open()) //or add a boolean
        return;
    
    if (!_s->_socket.available())
        return;
    // std::cout << "something to read in tcp" << std::endl;
    while (this->readMessage());
    auto &med = rtype::client::Mediator::get();

    if (id.size() == 36)
        med.mediate(_queueId);
}

rtype::subsystem::NetworkTCPWriter::NetworkTCPWriter()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKTCPWRITER]: CTOR" << std::endl;
    auto ecMan = rtype::singleton::ECManager::get();

    bool is_created = true;
    try {
        auto s = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageSendClient>();
        _queue_mssg = s.second;    
    } catch (rtype::component::Exception &e) {
        is_created = false;
    }
    if (!is_created) {
        //create
        std::cout << "queueCreation" << std::endl;
        auto queue = std::shared_ptr<rtype::component::QueueMessageSendClient>(new rtype::component::QueueMessageSendClient());
        std::string id = ecMan.createEntity(Signature(rtype::idBitset::idQueueMessageSendClient), queue);
        _queue_mssg = queue;

        auto pair = ecMan._cMan.getComponentFromType<rtype::component::Unremovable>();

        pair.second->entities.push_back(id);
    }
    auto s = ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>();
    _s = s.second;
}

void rtype::subsystem::NetworkTCPWriter::update(const Entity &id)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKTCPWRITER]: update" << std::endl;
    if (!_s->_socket.is_open()) //or add a boolean
        return;
    while (_queue_mssg->_messages.size()) {
        _s->_socket.send(boost::asio::buffer(_queue_mssg->_messages.front()));
        _queue_mssg->_messages.pop();
    }
}
