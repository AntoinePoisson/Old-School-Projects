/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <iostream>
#include "boost/asio.hpp"
#include "boost/bind.hpp"
#include "boost/enable_shared_from_this.hpp"
#include "HandleBoostNetwork.hpp"
#include "Package.hpp"
#include "TableElement.hpp"

namespace babel {

    class Client {
        public:
            Client(boost::asio::io_service &io_service);
            ~Client();

            static boost::shared_ptr<babel::Client> createClient(boost::asio::io_service &io_service);
            void connection(void);
            babel::Package receivePacket(void);
            void sendPacket(babel::Package packet);
            boost::asio::ip::tcp::socket &getSocket(void);
            void setTable(babel::TableUser table);
            babel::TableUser getTable(void) const;
            void disconnect(void);
        private:
            babel::HandleBoostNetwork _network;
            babel::TableUser _table;
            bool _turnOn;
    };

}

#endif /* !CLIENT_HPP_ */
