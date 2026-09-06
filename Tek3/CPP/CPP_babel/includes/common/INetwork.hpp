/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** INetwork
*/

#ifndef INETWORK_HPP_
#define INETWORK_HPP_

#include "QueuePacket.hpp"

namespace babel {

    class INetwork {
        public:
            virtual ~INetwork() = default;

            virtual void start(void) = 0;
            virtual void disconnect(void) = 0;
            virtual babel::Package receiveMsg(void) = 0;
            virtual void sendMsg(babel::Package pack) = 0;
    };

}

#endif /* !INETWORK_HPP_ */
