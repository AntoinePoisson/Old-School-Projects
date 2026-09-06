/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** SocketUDP
*/

#include "SocketUDP.h"

babel::SocketUDP::SocketUDP(QObject *test)
{
    _sock = new QUdpSocket(test);
}

void babel::SocketUDP::connectSocket(const DataClient &info)
{
//     QHostAddress addr;
//     for (const QHostAddress &testAddr: QNetworkInterface::allAddresses()) {
//         if (testAddr.protocol() == QAbstractSocket::IPv4Protocol && testAddr != QHostAddress::LocalHost) {
//             addr = testAddr;
//             break;
//         }
//     }
    _port = info.getPort();
    _sock->bind(QHostAddress::LocalHost, info.getPort());
}

void babel::SocketUDP::setSocket(QUdpSocket *socket)
{
    _sock = socket;
}

QUdpSocket *babel::SocketUDP::getSocket() const
{
    return _sock;
}

uint16_t babel::SocketUDP::getPort() const
{
    return _port;
}


void babel::SocketUDP::setPortDist(uint16_t a)
{
    _portDist = a;
}
void babel::SocketUDP::setAddrDist(std::string a)
{
    QHostAddress b(QString::fromStdString(a));
    _addrDist = b;
}
void babel::SocketUDP::sendAudio(dataUdp_t audio)
{
    if (_addrDist.isNull())
        return;
    char a[sizeof(dataUdp_t)] = {0};
    memcpy(a, &audio, sizeof(dataUdp_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(dataUdp_t));
    _sock->writeDatagram(byteArray, _addrDist, _portDist);
}

babel::dataUdp_t babel::SocketUDP::receivAudio()
{
    char a[sizeof(dataUdp_t)] = {0};
    dataUdp_t audio = {};

    if (_portDist == 0)
        _sock->readDatagram(a, sizeof(dataUdp_t), &_addrDist, &_portDist);
    else
        _sock->readDatagram(a, sizeof(dataUdp_t));
    memcpy(&audio, a, sizeof(dataUdp_t));
    return audio;
}