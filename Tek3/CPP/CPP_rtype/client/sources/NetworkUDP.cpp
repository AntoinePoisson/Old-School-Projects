/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** SystemNetwork
*/

#include "systems/NetworkUDP.hpp"
#include "systems/Exception.hpp"
#include "singleton/ECManager.hpp"
#include "systems/NetworkClient.hpp"
#include "MediatorClient.hpp"

// #include "components/TempComponents.hpp"
#include "Mediator.hpp"

/* Network Reader */

rtype::system::NetworkUDPReader::NetworkUDPReader()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPREADER]: CTOR" << std::endl;
    auto &ecMan = rtype::singleton::ECManager::get();
    bool is_created = true;

    //tcp socket
    try {
        auto s = ecMan._cMan.getComponentFromType<rtype::component::Socket>();
        _s = s.second;    
    } catch (rtype::component::Exception &e) {
        is_created = false;
    }
    if (!is_created) {
        //create
        std::cout << "socketCreation" << std::endl;
        auto io = ecMan._cMan.getComponentFromType<rtype::component::IOService>();
        auto _newSock = std::shared_ptr<rtype::component::Socket>(new rtype::component::Socket(io.second->_ioService));
        ecMan.createEntity(Signature(rtype::idBitset::idSocket), _newSock);
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
        _queueId = ecMan.createEntity(Signature(rtype::idBitset::idQueueMessageRecvClient), queue);
        _queue_mssg = queue;
    }

    std::string a = "okokokokokokokokokokkkokookokokokoko";

    openAsyncRead(a);


    // try {
    //     std::cout << "get udp endpoint..." << std::endl;
    //     auto servEdp = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
    //     std::cout << servEdp.second->_udp_addr<< "@" <<servEdp.second->_udp_port << std::endl;
    //     _serverEdp = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(servEdp.second->_udp_addr), servEdp.second->_udp_port);
    // } catch (rtype::component::Exception &e) {
    //     std::cerr << "component server's endpoint not created!!" << std::endl;
    // }

    //get ioService
}

void rtype::system::NetworkUDPReader::update(const Entity &id)
{
    // std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPREADER]: update" << std::endl;
    auto &ecMan = rtype::singleton::ECManager::get();

    // std::cout << "set up thread call" << std::endl;
    auto scene = ecMan._cMan.getComponentFromType<rtype::component::Scene>();

    if (!_s->_socket.is_open() 
        && scene.second->_scene == rtype::client::scenes::GAME) {
        std::cout << "socket closed in game, back to menu..." << std::endl;
        scene.second->_scene = rtype::client::scenes::MENU;
        return;
    }

    if (_serverEdp.port() == 0) {
        auto servEdp = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
        std::cout << servEdp.second->_udp_addr<< "@" <<servEdp.second->_udp_port << std::endl;
        _serverEdp = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(servEdp.second->_udp_addr), servEdp.second->_udp_port);
    }

    if (_s->_socket.is_open() == false)
        return;
    if (!_s->_socket.available()) {
        return;
    }

    // openAsyncRead(id);

    auto service = ecMan._cMan.getComponentFromType<rtype::component::IOService>();
    std::cout << "un" <<_s->_socket.available() << std::endl;
    service.second->_ioService.run_one();
    return;
}

void rtype::system::NetworkUDPReader::openAsyncRead(const Entity &id)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPREADER]: openAsyncRead" << std::endl;
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();


    if (_s->_socket.is_open() == false) {
        std::cout << "[Warning]: Can't Read because of Socket Close." << std::endl;
        throw rtype::system::Exception("Can't Read because of Socket Close.");
    }

    // std::cout << "Available " << _s->_socket.available() << std::endl;
    std::string *_buff(new std::string());
    _buff->resize(50000);
    boost::asio::ip::udp::endpoint *_endpoint(new boost::asio::ip::udp::endpoint);

    std::cout << "bef" << std::endl;

    _s->_socket.async_receive_from(
        boost::asio::buffer(*_buff),
        *_endpoint,
        boost::bind(&NetworkUDPReader::handlerRead,
        this, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred, id, _endpoint, _buff));
    std::cout << "here" << std::endl;
}

void rtype::system::NetworkUDPReader::handlerRead(const boost::system::error_code& err, std::size_t size, Entity _idEntity, boost::asio::ip::udp::endpoint *_endpoint, std::string *_buff)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPREADER]: handlerRead" << std::endl;
    if (err) {
        std::cerr << "[Error]: Can't Read Package (" << err.message() << ")." << std::endl;
        return;
    }



    //maybe check endpoint here to ensure that it is the server that send you the message

    // std::cout << "\n/======== Package =========\\" << std::endl;
    // std::cout << " - Size transfere byte: '" << size << "'." << std::endl;
    // std::cout << " - Entity id: " << _idEntity << std::endl;
    // std::cout << " - Data("<< size << "): '" << _buff->data() << "'." << std::endl;
    // std::cout << "\\===========================/\n" << std::endl;
    rtype::entity::ComponentManager &handler = rtype::singleton::ECManager::get();

    // size_t cur_size = _buff->size();
    // std::cout << "jai lu ça " << size << std::endl;

    if (rtype::network::paquetParser(std::string(_buff->data(), size)) != -1 
        && _idEntity.size() == 36) {
            auto &med = rtype::client::Mediator::get();
            med.mediate(_queueId);
        }

    delete _buff;
    delete _endpoint;
    openAsyncRead(_idEntity);
}

/* Network Writer */

rtype::subsystem::NetworkUDPWriter::NetworkUDPWriter()
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPWRITER]: CTOR" << std::endl;
    auto &ecMan = rtype::singleton::ECManager::get();

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
        ecMan.createEntity(Signature(rtype::idBitset::idQueueMessageSendClient), queue);
        _queue_mssg = queue;
    }
    auto s = ecMan._cMan.getComponentFromType<rtype::component::Socket>();
    _s = s.second;

    // try {
    //     std::cout << "get udp endpoint..." << std::endl;
    //     auto servEdp = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
    //     _serverEdp = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(servEdp.second->_udp_addr), servEdp.second->_udp_port);
    // } catch (rtype::component::Exception &e) {
    //     std::cerr << "component server's endpoint not created!!" << std::endl;
    // }
}

void rtype::subsystem::NetworkUDPWriter::update(const Entity &id)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPWRITER]: update" << std::endl;
    auto ecMan = rtype::singleton::ECManager::get();

    openAsyncWrite("noId");

    // auto service = ecMan._cMan.getComponentFromType<rtype::component::IOService>();
    // service.second->_ioService.run_one();
    auto service = ecMan._cMan.getComponentFromType<rtype::component::IOService>();
    service.second->_ioService.run_one();
}

void rtype::subsystem::NetworkUDPWriter::openAsyncWrite(const Entity &id)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPWRITER]: openAsyncWrite" << std::endl;
    auto ecMan = rtype::singleton::ECManager::get();

    if (_s->_socket.is_open() == false 
        || _queue_mssg->_messages.size() == 0) {
        return;
    }

    if (_serverEdp.port() == 0) {
        auto servEdp = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
        _serverEdp = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(servEdp.second->_udp_addr), servEdp.second->_udp_port);
    }

    auto res = _queue_mssg->_messages.front();
    _queue_mssg->_messages.pop();

    _s->_socket.async_send_to(
        boost::asio::buffer(res),
        this->_serverEdp,
        boost::bind(&NetworkUDPWriter::handlerWrite,
        this, boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred, id));
}

void rtype::subsystem::NetworkUDPWriter::handlerWrite(const boost::system::error_code& err, std::size_t size, Entity _idEntity)
{
    std::cerr << "[CLIENT]: [SYSTEM]: [NETWORKUDPWRITER]: handleWrite" << std::endl;
    if (err) {
        std::cerr << "[Error]: Can't Write Package (" << err.message() << ")." << std::endl;
        return;
    } else if (size == 0) {
        std::cerr << "[Warning]: Nothing Send." << std::endl;
        return;
    }
    std::cout << "Client udp send packet: Packetage successfully send." << std::endl;
    openAsyncWrite(_idEntity);
}
