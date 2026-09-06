/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** ClientNetwork
*/

#ifndef ClientNetwork_HPP_
#define ClientNetwork_HPP_

#include "SocketTCP.h"
#include "SocketUDP.h"
#include "INetwork.h"
#include "APortAudio.hpp"
#include "portaudio.h"

namespace babel
{
    class ClientNetwork : public babel::INetwork
    {
        public:
            ClientNetwork(int ac, char **argv);
            virtual ~ClientNetwork() = default;

            void logout() final;
            void login(const IData &) final;
            void registered(const IData &) final;
            void listRelation() final;
            void askingAddRelation(const IData &) final;
            void answerCalledSomeone(const IData &) final;
            void askingCallSomeone(const IData &) final;

            void removeRelation(const IData &);
            void answerAddedRelation(const IData &);
            void hangUpCall(const IData &);


            void setSocketTcp(SocketTCP *sock);
            void setSocketUdp(SocketUDP *sock);

        public:
            SocketTCP *sockTcp;
            SocketUDP *sockUdp;
};
}
#endif /* !ClientNetwork_HPP_ */
