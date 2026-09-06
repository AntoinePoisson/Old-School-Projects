/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Network
*/

#ifndef COMMONCOMPONENTNETWORK_HPP_
#define COMMONCOMPONENTNETWORK_HPP_

#include <boost/asio.hpp>
#include <queue>
#include <iostream>
#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        struct IOService : public AComponent
        {
            IOService() = default;
            ~IOService() = default;

            boost::asio::io_service _ioService;
        };

        struct Socket : public AComponent
        {
            Socket(boost::asio::io_service &ioService): _socket(ioService) {};
            Socket(boost::asio::io_service &ioService, boost::asio::ip::udp::endpoint endpoint): _socket(ioService, endpoint) {};
            ~Socket() {
                std::cout << "destroy" << std::endl;
            }

            boost::asio::ip::udp::socket _socket;
        };

        struct SocketTCP : public AComponent
        {
            SocketTCP(boost::asio::io_service &ioService): _socket(ioService) {};
            SocketTCP(boost::asio::io_service &ioService, boost::asio::ip::tcp::endpoint endpoint): _socket(ioService, endpoint) {};
            ~SocketTCP() = default;

            boost::asio::ip::tcp::socket _socket;
        };

        struct MyNetworkInfo : public AComponent
        {
            MyNetworkInfo(boost::asio::ip::udp::endpoint endpoint): _endpoint(endpoint) {};
            ~MyNetworkInfo() = default;

            boost::asio::ip::udp::endpoint _endpoint;
        };

        struct OpponentNetworkInfo : public AComponent
        {
            OpponentNetworkInfo(boost::asio::ip::udp::endpoint endpoint): _endpoint(endpoint) {};
            ~OpponentNetworkInfo() = default;

            boost::asio::ip::udp::endpoint _endpoint;
        };

        struct QueueMessageReceive : public AComponent
        {
            QueueMessageReceive() = default;
            ~QueueMessageReceive() = default;

            std::queue<std::pair<std::string, rtype::component::OpponentNetworkInfo>> _queue;
        };

        struct QueueMessageSend : public AComponent
        {
            QueueMessageSend() = default;
            ~QueueMessageSend() = default;

            std::queue<std::pair<std::string, rtype::component::OpponentNetworkInfo>> _queue;
        };

        struct QueueMessageSendClient: public AComponent
        {
            QueueMessageSendClient() = default;
            ~QueueMessageSendClient() = default;

            std::queue<std::string> _messages;
        };

        struct QueueMessageRecvClient: public AComponent
        {
            QueueMessageRecvClient() = default;
            ~QueueMessageRecvClient() = default;

            std::queue<std::pair<int, std::string>> _messages;
        };

        struct ServerEndpoints : public AComponent
        {
            ServerEndpoints(const std::string &tcp_addr, const short &tcp_port): 
            _tcp_addr(tcp_addr), _tcp_port(tcp_port) {};
            ~ServerEndpoints() = default;

            std::string _tcp_addr;
            unsigned short _tcp_port;

            std::string _udp_addr;
            unsigned short _udp_port = 0;
        };

        struct NetworkId: public AComponent
        {
            NetworkId(int id) : _id(id) {};
            ~NetworkId() = default;

            int _id;
        };

        // struct ItsServer: public AComponent
        // {
        //     ItsServer() = default;
        //     ~ItsServer() = default;
        // };
    }
}

#endif /* !COMMONCOMPONENTNETWORK_HPP_ */
