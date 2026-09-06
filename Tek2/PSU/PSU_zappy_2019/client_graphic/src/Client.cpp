/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(unsigned short portNb)
{
    _sockFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;

    if (_sockFd == -1) {
        throw NetworkException("(Client) Socket creation failed");
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(portNb);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    if (connect(_sockFd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        throw NetworkException("(Client) failed to connect");
    } else {
        std::cout << "Connection to server succeed" << std::endl;
    }
}

Client::Client(unsigned short portNb, char breakCharacter): 
_breakCharacter(breakCharacter)
{
    _sockFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;

    if (_sockFd == -1) {
        throw NetworkException("(Client) Socket creation failed");
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(portNb);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    if (connect(_sockFd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        throw NetworkException("(Client) failed to connect");
    } else {
        std::cout << "Connection to server succeed" << std::endl;
    }
}


int Client::getFd()
{
    return _sockFd;
}

Client::~Client()
{
    close(_sockFd);
}

std::string Client::listenToServerStr()
{
    char c;
    std::string message = "";
    int readBytes = 0;
    fd_set set;

    while (true) {
        readBytes = read(_sockFd, &c, 1);
        if (c == _breakCharacter) {
            // std::cout << "Received from client" << message << "done." << std::endl;
            break;
        }
        message += c;
    }
    return (message);
}

bool Client::sendStrRequest(const std::string &message)
{
    fd_set set;
    struct timeval timeout = {0, 500};
    std::string fmtMssg(message);

    while (1) {
        FD_ZERO(&set);
        FD_SET(_sockFd, &set);
        timeout.tv_sec = 0;
        timeout.tv_usec = 500;
        if (select(_sockFd + 1, NULL, &set, NULL, &timeout) > 0)
            break;
    }
    fmtMssg += _breakCharacter;
    if (write(_sockFd, fmtMssg.c_str(), fmtMssg.length()) < 0) {
        throw NetworkException("Can't write on socket");
    }
    return (true);
}

bool Client::serverIsWriting()
{
    fd_set set;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);
    struct timeval timeout = {0, 500};

    FD_ZERO(&set);
    FD_SET(_sockFd, &set);
    if (select(_sockFd + 1, &set, NULL, NULL, &timeout) > 0) {
        return (true);
    }
    return (false);
}