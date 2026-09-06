/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleBoostNetwork
*/

#ifndef HANDLEBOOSTNETWORK_HPP_
#define HANDLEBOOSTNETWORK_HPP_

#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/asio.hpp>

#include "Babel.hpp"
#include "AsioNetwork.hpp"
#include "Package.hpp"
#include "QueuePacket.hpp"
#include "INetwork.hpp"
#include "TransfertData.hpp"

namespace babel {

    class HandleBoostNetwork : public INetwork {
        public:
            HandleBoostNetwork(boost::asio::io_service &io_service);
            ~HandleBoostNetwork();

            void start(void);
            babel::Package receiveMsg(void);
            void sendMsg(babel::Package pack);
            void disconnect(void);
            boost::asio::ip::tcp::socket &getSocket(void);
        private:
            void openAsyncRead(void);
            void openAsyncWrite(void);
            void handlerRead(const boost::system::error_code& error, std::size_t size);
            void handlerWrite(const boost::system::error_code& error, std::size_t size);

            boost::asio::ip::tcp::socket _sock;
            std::vector<char> _buffRead;
            std::vector<char> _buffWrite;
            QueuePacket _receiveQueue;
            QueuePacket _sendQueue;
            babel::TransfertData _transfer;
            bool _turnOn;
    };

}

#endif /* !HANDLEBOOSTNETWORK_HPP_ */
