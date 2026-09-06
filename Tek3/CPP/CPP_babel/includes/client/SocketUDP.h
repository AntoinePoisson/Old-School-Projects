/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** SocketUDP
*/

#ifndef SOCKETUDP_H_
#define SOCKETUDP_H_

#include "ISocket.h"

#define SIZE_MAX_AUDIO 480


namespace babel
{
    typedef struct dataUdp_s {
        long time;
        unsigned char audio[SIZE_MAX_AUDIO];
    } dataUdp_t;

    class SocketUDP : public babel::ISocket
    {
        public:
            SocketUDP(QObject *test);
            virtual ~SocketUDP() = default;
            void connectSocket(const DataClient &);
            void setSocket(QUdpSocket *sock);
            QUdpSocket *getSocket() const;
            uint16_t getPort() const;
            void setPortDist(uint16_t a);
            void setAddrDist(std::string a);
            void sendAudio(dataUdp_t audio);
            dataUdp_t receivAudio();

        private:
        QUdpSocket *_sock;
        uint16_t _port = 0;
        uint16_t _portDist = 0;
        QHostAddress _addrDist;
    };
}

#endif /* !SOCKETUDP_H_ */
