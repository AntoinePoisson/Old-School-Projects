/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <vector>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>//gethostbyname
#include <stdio.h>
#include <netinet/in.h>// Internet address manipulation routines
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "Exception.hpp"

class Server {
    unsigned short _portNb;
    int _sockFd;
    std::vector<int> clientsSocket;
    char _breakCharacter;

    public:
        Server(unsigned short portNb, char breakCharacter = '\n');
        ~Server();
        unsigned short getPortNumber();
        int checkIncommingConnection();
        int checkClientRequest();
        std::string readClientRequestStr(int fd);
        bool sendStrRequest(int fd, const std::string &message);
        int getFdOfTheLastConnectedClient();
        template<typename T>
        T readClientRequest(int fd)
        {
            T fillstruct;
            bzero(&fillstruct, sizeof(fillstruct));
            read(fd, &fillstruct, sizeof(fillstruct));
            return fillstruct;
        }
        template<typename T>
        bool sendRequest(int fd, T message)
        {
            fd_set set;
            struct timeval timeout = {0, 500};
            int send = 0;

            while (1) {
                FD_ZERO(&set);
                FD_SET(fd, &set);
                timeout.tv_sec = 0;
                timeout.tv_usec = 500;
                if (select(fd + 1, NULL, &set, NULL, &timeout) > 0)
                    break;
            }
            if ((send = write(fd, &message, sizeof(T))) < 0) {

                throw NetworkException("Server send template method: Can't write on socket");
            }
            return (true);
        }
};

#endif