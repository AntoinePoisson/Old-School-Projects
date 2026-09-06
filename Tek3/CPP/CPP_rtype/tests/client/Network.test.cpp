#include <gtest/gtest.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "singleton/ECManager.hpp"
#include "Network.hpp"
// #include "systems/NetworkTCP.hpp"
// #include "systems/NetworkUDP.hpp"
#include "scene/SceneManager.hpp"

TEST(NETWORK_TEST, NETWORK_TCP_READER) {
  //https://stackoverflow.com/questions/601763/how-to-get-ip-address-of-boostasioiptcpsocket
  // https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio/reference/basic_stream_socket/local_endpoint/overload2.html
    rtype::client::SceneManager sc; //125.0.0.1 4242 => create server endpoint within the ctor
    auto &ecMan = rtype::singleton::ECManager::get();
    
    auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 4211);
    // boost::asio::ip::tcp::acceptor _acceptor(io, endpoint);
    char addr[13] = "127.0.0.1";
    struct rtype::network::EndpointMssg mssg{.type = rtype::network::MessageTypeServer::ENDPOINT_S, .port = 4211};
    // mssg.addr = "127.0.0.1";

    std::memcpy(addr, mssg.addr, sizeof(10));

    void *value = static_cast<void *>(&mssg);
    char *value2 = static_cast<char *>(value);

    std::string serialized_message(value2, sizeof(rtype::network::EndpointMssg));

    // std::cout << serialized_message.size() << std::endl;

    if (fork() == 0) {
        
        boost::asio::io_service io2;
        boost::asio::ip::tcp::socket sock1(io2);
        boost::asio::ip::tcp::acceptor _acceptor(io2, endpoint);

        // std::cout << "bef acc" << std::endl;
        _acceptor.accept(sock1);
        // std::cout << "af acc" << std::endl;


        sock1.send(boost::asio::buffer(serialized_message, sizeof(rtype::network::EndpointMssg)));
        // std::cout << "quit" << std::endl;
        exit(0);
    }
    rtype::system::NetworkTCPReader nreader; //socket tcp created but not open
    //connect your socket to the endpoint
    auto pairSock = ecMan._cMan.getComponentFromType<rtype::component::SocketTCP>();
    sleep(1);
    
    pairSock.second->_socket.connect(endpoint);

    sleep(1);

    nreader.update("rien");
    while (waitpid(-1, 0, WUNTRACED) == -1);

    // std::cout << "before" << std::endl;
    auto pair = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();
    // std::cout << "after" << std::endl;

    // check queue.message
    EXPECT_EQ(pair.second->_messages.front().first, rtype::network::MessageTypeServer::ENDPOINT_S);
    pair.second->_messages.pop();
}

//add test to check if is_open works
TEST(NETWORK_TEST, NETWORK_TCPR_IS_OPEN_TEST) {
  //https://stackoverflow.com/questions/601763/how-to-get-ip-address-of-boostasioiptcpsocket
    rtype::client::SceneManager sc; //125.0.0.1 4242 => create server endpoint within the ctor
    auto &ecMan = rtype::singleton::ECManager::get();
    
    auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 4242);
    // boost::asio::ip::tcp::acceptor _acceptor(io, endpoint);

    rtype::system::NetworkTCPReader nreader; //socket tcp created but not open

    nreader.update("rien");

    // std::cout << "before" << std::endl;
    auto pair = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();
    // std::cout << "after" << std::endl;

    // check queue.message
    EXPECT_EQ(pair.second->_messages.size(), 0);
}

TEST(NETWORK_TEST, NETWORK_UDP_READ)
{
    auto &ecMan = rtype::singleton::ECManager::get();
    ecMan = rtype::entity::ComponentManager(); //reset ecMan
    rtype::client::SceneManager sc; //125.0.0.1 4242 => create server endpoint within the ctor
    
    /*init coordinate udp server*/
    auto senderEdp = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
    senderEdp.second->_udp_addr = "127.0.0.1";
    senderEdp.second->_udp_port = 9993;
    // auto str = ecMan.createEntity(Signature(rtype::idBitset::idServerEndpoints), senderEdp);
    rtype::system::NetworkUDPReader nr;
    // rtype::network::CodeActionMssg mssg1 = {.timestamp = 0, .nb_player = 2, .action = rtype::network::CodeAction::PLAY};
    rtype::network::EndGameMssg mssg1 = {.has_won = true};
    
    /*build message*/
    void *value = static_cast<void *>(&mssg1);
    char *value2 = static_cast<char *>(value);
    std::string mssg(value2, sizeof(rtype::network::EndGameMssg));
    /*endbuild message*/

    auto sockUdp =  ecMan._cMan.getComponentFromType<rtype::component::Socket>();

    /*SOCKET's PEER WRITER*/
    // auto pairIO = ecMan._cMan.getComponentFromType<rtype::component::IOService>();
    if (fork() == 0) {
        boost::system::error_code error;
        boost::asio::ip::udp::endpoint edpRecvr = sockUdp.second->_socket.local_endpoint(error);
        
        std::cout << edpRecvr.port()<< std::endl;
        std::cout << edpRecvr.address().to_string() << std::endl;
        
        boost::asio::io_service io_service2;
        boost::asio::ip::udp::socket sender(io_service2);

        sender.open(boost::asio::ip::udp::v4());
        sender.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 9993));

        sockUdp.second->_socket.send_to(boost::asio::buffer(mssg.data(), mssg.size()), edpRecvr);
        exit(0);
    }
    sleep(1);
    
    nr.update("noIdNeeded");
    // pairIO.second->_ioService.run_one();

    auto pairQueue = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();

    std::string recvd_mssg = pairQueue.second->_messages.front().second;
    std::string mssg_shifted(mssg.data() + sizeof(int), mssg.size() - sizeof(int));
    
    EXPECT_EQ(recvd_mssg, mssg_shifted);
    while (waitpid(-1, 0, WUNTRACED) == -1); //delete zombie
}

TEST(NETWORK_TEST, QUEUECONCATMSSG_TEST)
{
    auto &ecMan = rtype::singleton::ECManager::get();
    ecMan = rtype::entity::ComponentManager(); //reset ecMan

    rtype::client::SceneManager sc; //125.0.0.1 4242 => create server endpoint within the ctor

    auto senderEdp = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
    senderEdp.second->_udp_addr = "127.0.0.1";
    senderEdp.second->_udp_port = 9993;
    rtype::system::NetworkUDPReader nr;
    
    //2Messages
    rtype::network::EndGameMssg mssg1 = {.has_won = true};
    rtype::network::EndGameMssg mssg2 = {.has_won = false};

    /*build message*/
    void *value = static_cast<void *>(&mssg1);
    char *value2 = static_cast<char *>(value);
    value = static_cast<void *>(&mssg2);
    char *value3 = static_cast<char *>(value);
    std::string mssg(value2, sizeof(rtype::network::EndGameMssg));
    mssg += std::string(value3, sizeof(rtype::network::EndGameMssg));
    /*build message*/


    /*SOCKET's PEER WRITER*/
    if (fork() == 0) {
        auto pairIO = ecMan._cMan.getComponentFromType<rtype::component::IOService>();
        boost::asio::ip::udp::socket sender(pairIO.second->_ioService);

        sender.open(boost::asio::ip::udp::v4());
        sender.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 9993));

        auto sockUdp =  ecMan._cMan.getComponentFromType<rtype::component::Socket>();
        boost::asio::ip::udp::endpoint edpRecvr = sockUdp.second->_socket.local_endpoint();

        sockUdp.second->_socket.send_to(boost::asio::buffer(mssg), edpRecvr);
        exit(0);
    }
    /**/
    sleep(1);

    nr.update("noIdNeeded");

    auto pairQueue = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageRecvClient>();

    std::string recvd_mssg = pairQueue.second->_messages.front().second;
    std::string mssg_shifted(value2 + sizeof(int), sizeof(rtype::network::EndGameMssg) - sizeof(int));

    EXPECT_EQ(recvd_mssg, mssg_shifted);
    while (waitpid(-1, 0, WUNTRACED) == -1); //delete zombie

}

TEST(NETWORK_TEST, NETWORK_UDPW_QUEUE_TEST)
{
    boost::asio::io_service _ioService;
    boost::asio::ip::udp::socket reader(_ioService);

    reader.open(boost::asio::ip::udp::v4());
    reader.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 9993));

    if (fork() == 0) {

        auto &ecMan = rtype::singleton::ECManager::get();
        ecMan = rtype::entity::ComponentManager(); //reset ecMan
    
        rtype::client::SceneManager sc; //125.0.0.1 4242 => create server endpoint within the ctor

        auto senderEdp = ecMan._cMan.getComponentFromType<rtype::component::ServerEndpoints>();
        senderEdp.second->_udp_addr = "127.0.0.1";
        senderEdp.second->_udp_port = 9993;

        rtype::subsystem::NetworkUDPWriter nw;

        std::cout << "la" << std::endl;
        auto queue = ecMan._cMan.getComponentFromType<rtype::component::QueueMessageSendClient>();
        std::cout << "la2" << std::endl;

        queue.second->_messages.push("salut");


        nw.update("noId");
        exit(0);
    }
    sleep(1);

    std::vector<char> buff(5);

    reader.receive(boost::asio::buffer(buff.data(), 5));
    std::string res(buff.data(), 5);

    EXPECT_EQ(res, "salut");
    while (waitpid(-1, 0, WUNTRACED) == -1); //delete zombie

}
