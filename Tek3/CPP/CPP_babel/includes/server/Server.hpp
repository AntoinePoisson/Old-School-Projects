/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "AsioNetwork.hpp"
#include "Babel.hpp"
#include "Client.hpp"
#include "HandleCtrlC.hpp"
#include "QuitServer.hpp"
#include "DataBase.hpp"
#include "HandleCommande.hpp"

namespace babel {

    class Server {
        public:
            Server(std::string ip, int port);
            ~Server();

            void run(void);
        private:
            void acceptConnection(void);
            void addClient(boost::shared_ptr<babel::Client> connect, const boost::system::error_code& err);

            std::string _ip;
            int _port;
            boost::asio::io_service _io_service;
            boost::asio::ip::tcp::acceptor _accept;
            std::vector<boost::shared_ptr<babel::Client>> _listClient;
            babel::DataBase _db;
            babel::HandleCommande _cmd;
    };

}

#endif /* !SERVER_HPP_ */
