/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** SocketTCP
*/

#include "SocketTCP.h"

babel::SocketTCP::SocketTCP(QObject *test)
{
    socket = new QTcpSocket(test);
}

void babel::SocketTCP::connectSocket(const DataClient &info)
{
    socket->abort();
    std::cout << info.getPort() << " " << info.getFirstParam() << std::endl;
    socket->connectToHost(QString::fromStdString(info.getFirstParam()), info.getPort());
}

void babel::SocketTCP::setSocket(QTcpSocket *sock)
{
    socket = sock;
}

bool babel::SocketTCP::getDataFromSocket()
{
    TransfertData trans;

    if ((unsigned long)socket->bytesAvailable() >= sizeof(transfertData_t)) {
        clearCmdParsed();
        QByteArray data = socket->readAll();
        setCmdParsed(trans.extractData(data.toStdString()));
        std::cout << "CMD PARSED :";
        for (auto el : cmdParsed) {
            std::cout << " " << el.data();
        }
        std::cout << std::endl;
        return true;
    }
    return false;
}

QTcpSocket *babel::SocketTCP::getSocket() const
{
    return socket;
}

std::vector<std::string> babel::SocketTCP::getCmdParsed() const
{
    return cmdParsed;
}

void babel::SocketTCP::clearCmdParsed()
{
    cmdParsed.clear();
}

void babel::SocketTCP::setCmdParsed(std::string cmd)
{
    cmdParsed.push_back(cmd);
}

void babel::SocketTCP::setCmdParsed(std::vector<std::string> allCmd)
{
    cmdParsed = allCmd;
}
