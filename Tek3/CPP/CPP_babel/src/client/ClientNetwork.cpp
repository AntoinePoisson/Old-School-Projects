/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** main
*/

#include "ClientUi.h"

babel::ClientNetwork::ClientNetwork(int argc, char **argv)
{
    QApplication app(argc, argv);

    ClientUi window(this);
    window.show();
    app.exec();
}

void babel::ClientNetwork::setSocketTcp(SocketTCP *socket)
{
    sockTcp = socket;
}

void babel::ClientNetwork::setSocketUdp(babel::SocketUDP *socket)
{
    sockUdp = socket;
}

void babel::ClientNetwork::logout()
{
    TransfertData trans;
    transfertData_t strct = trans.transcriptData(232,  std::vector<std::string>());
    char a[sizeof(transfertData_t)] = {0};

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::login(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(std::to_string(info.getFirstParam().length()));
    data.push_back(info.getFirstParam());
    data.push_back(std::to_string(info.getSecondParam().length()));
    data.push_back(info.getSecondParam());
    strct = trans.transcriptData(231, data);

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::registered(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(std::to_string(info.getFirstParam().length()));
    data.push_back(info.getFirstParam());
    data.push_back(std::to_string(info.getSecondParam().length()));
    data.push_back(info.getSecondParam());
    std::cout << "DATA : ";
        for (auto el : data) {
            std::cout << " " << el.data();
        }
    std::cout << std::endl;

    strct = trans.transcriptData(230, data);
    std::cout << "AVANT" << strct.opcode << std::endl;
    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray tete = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(tete);
}

void babel::ClientNetwork::listRelation()
{
    TransfertData trans;
    transfertData_t strct = trans.transcriptData(223,  std::vector<std::string>());
    char a[sizeof(transfertData_t)] = {0};

    memcpy(a, &strct, sizeof(transfertData_t));
    std::cout << "tester:" << strct.opcode << std::endl;
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::askingAddRelation(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(std::to_string(info.getFirstParam().length()));
    data.push_back(info.getFirstParam());
    strct = trans.transcriptData(220,  data);

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::answerCalledSomeone(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(info.getFirstParam());
    strct = trans.transcriptData(211,  data);

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::askingCallSomeone(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(info.getFirstParam());
    data.push_back(std::to_string(sockUdp->getPort()));
    strct = trans.transcriptData(210,  data);

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::removeRelation(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(info.getFirstParam());
    strct = trans.transcriptData(222,  data);

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::answerAddedRelation(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(info.getFirstParam());
    strct = trans.transcriptData(221,  data);

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}

void babel::ClientNetwork::hangUpCall(const IData &info)
{
    TransfertData trans;
    transfertData_t strct = {};
    std::vector<std::string> data;
    char a[sizeof(transfertData_t)] = {0};

    data.push_back(info.getFirstParam());
    strct = trans.transcriptData(212,  data);

    memcpy(a, &strct, sizeof(transfertData_t));
    QByteArray byteArray = QByteArray::fromRawData(a, sizeof(transfertData_t));
    sockTcp->getSocket()->write(byteArray);
}