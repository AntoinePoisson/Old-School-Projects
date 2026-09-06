/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(unsigned short portNb, char breakCharacter)
: _breakCharacter(breakCharacter)
{
    _portNb = portNb;
    _sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in address;
    int reuse = 1;

    if (_sockFd == -1) {
        throw NetworkException("Socket creation failed");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(portNb);
    // fcntl(_sockFd, F_SETFD, O_NONBLOCK);
    if (setsockopt(_sockFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEADDR, (int *) &reuse, sizeof(reuse)) == -1) {
        throw NetworkException("Setting socket option failed");
    }
    if (bind(_sockFd, ((struct sockaddr *) &address), sizeof(address)) < 0) {
        close(_sockFd);
        throw NetworkException("Bind failed");
    }
    listen(_sockFd, 30);
}

Server::~Server()
{
    close(_sockFd);
}

unsigned short Server::getPortNumber()
{
    return _portNb;
}

int Server::checkIncommingConnection()
{
    fd_set set;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);
    FD_ZERO(&set);
    FD_SET(_sockFd, &set);
    struct timeval timeout = {1, 500};

    if (select(_sockFd + 1, &set, NULL, NULL, &timeout) > 0) {
        int newSock = accept(_sockFd, ((struct sockaddr *) &address), &addr_len);
        // std::cout << "New client is connected " << inet_ntoa(address.sin_addr) ;//<< std::endl;
        // std::cout << " port = "  << ntohs(address.sin_port) << std::endl;
        clientsSocket.push_back(newSock);
        return (newSock);

    }
    return (-1);
}

int Server::checkClientRequest()
{
    fd_set set;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);
    struct timeval timeout = {1, 500};

    FD_ZERO(&set);
    for (auto client = clientsSocket.begin(); 
            client != clientsSocket.end(); client++) {
             FD_SET(*client, &set);
    }
    if (clientsSocket.size() 
        && select((*clientsSocket.rbegin()) + 1, &set, NULL, NULL, &timeout) > 0) {
        for (auto client = clientsSocket.begin();
            client != clientsSocket.end(); client++) {
                if (FD_ISSET(*client, &set)) {
        // std::cout << "rentre" << std::endl;
                // sd::cout << "client"
                    return *client;
                }
        }
    }
    return (-1);
}

std::string Server::readClientRequestStr(int fd)
{
    std::string message = "";
    // int readBytes = 0;
    char c;

    while (true) {
        read(fd, &c, 1);
        if (c == _breakCharacter) {
            std::cout << "Received from server" << message << "done." << std::endl;
            break;
        }
        message += c;
}
    return (message);
}

bool Server::sendStrRequest(int fd, const std::string &message)
{
    fd_set set;
    struct timeval timeout = {0, 500};
    std::string fmtMssg(message);

    while (1) {
        FD_ZERO(&set);
        FD_SET(fd, &set);
        timeout.tv_sec = 0;
        timeout.tv_usec = 500;
        if (select(fd + 1, NULL, &set, NULL, &timeout) > 0)
            break;
    }
    fmtMssg += _breakCharacter;
    if (write(fd, fmtMssg.c_str(), fmtMssg.length()) < 0) {
        throw NetworkException("Can't write on socket");
        // return (false);
    }
    return (true);
}

int Server::getFdOfTheLastConnectedClient()
{      
    return (*clientsSocket.rbegin());
}
