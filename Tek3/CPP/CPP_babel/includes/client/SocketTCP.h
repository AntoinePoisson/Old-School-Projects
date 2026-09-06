/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** SocketTCP
*/

#ifndef SOCKETTCP_H_
#define SOCKETTCP_H_

#include "ISocket.h"
#include "TransfertData.hpp"

namespace babel
{
    class SocketTCP : public babel::ISocket
    {
        public:
        SocketTCP(QObject *test);
        virtual ~SocketTCP() = default;
        void connectSocket(const DataClient &) final;
        void setSocket(QTcpSocket *sock);
        bool getDataFromSocket();
        QTcpSocket *getSocket() const;

        // quint16 getMsgSize() const;
        // std::string getServMsg() const;
        std::vector<std::string> getCmdParsed() const;

        void clearCmdParsed();

        // void setMsgSize(quint16 size);
        // void setServMsg(std::string msg);
        void setCmdParsed(std::string cmd);
        void setCmdParsed(std::vector<std::string> allCmd);

        private:
        QTcpSocket *socket;
        // quint16 msgSize;
        // std::string serverMsg;
        std::vector<std::string> cmdParsed;

    };
}

#endif /* !SOCKETTCP_H_ */
