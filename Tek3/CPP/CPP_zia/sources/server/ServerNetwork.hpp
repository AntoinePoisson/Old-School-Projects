/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** ServerNetwork
*/

#ifndef SERVERNETWORK_HPP_
#define SERVERNETWORK_HPP_

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>
#include <memory>

#include "../api/io/IConnection.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
    * @class ServerNetwork
    * Represents a server connecting at a specific ip and port
    * The server is threaded and listen a specifique port
    * He return new client
    */
    class ServerNetwork
    {
        private:
            boost::mutex _mutex;
            std::string _ip;
            unsigned int _port;
            boost::asio::io_context _ioContext;
            boost::asio::ip::tcp::acceptor _accept;
            std::vector<std::shared_ptr<Zia::IConnection>> _listConnected;
            boost::asio::signal_set _signals;
            std::shared_ptr<Zia::ILogger> _logger;
            const bool _secure;

            void acceptConnection();
            void handlerAddConnection(const std::shared_ptr<Zia::IConnection> newConnect, const boost::system::error_code& err);
        public:
            /**
             * @fn Construct a new Server Network object
             * Setup server on port and ip
             * @param ip ip of server
             * @param port port of server
             */
            ServerNetwork(const std::string ip = "127.0.0.1", unsigned int port = 80, std::shared_ptr<Zia::ILogger> log = nullptr, const bool &secure = false);
            ~ServerNetwork();

            /**
             * @fn run
             * Launch server on thread
             * @return std::shared_ptr<boost::asio::io_context::work> return a work (link to _ioContext) in order to stop server
             */
            std::shared_ptr<boost::asio::io_context::work> run();
            /**
             * @fn receiveNewConnection
             * Return new connection to server or nullptr if there is no client
             * @return std::shared_ptr<Zia::IConnection> New client
             */
            std::shared_ptr<Zia::IConnection> receiveNewConnection();
    };
} // namespace zia


#endif /* !SERVERNETWORK_HPP_ */
