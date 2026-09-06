/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <iostream>
#include <vector>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>

#include "Exception.hpp"

class Client {

    int _sockFd;
    char _breakCharacter = '\n';
    public:
        Client(unsigned short portNb);
        Client(unsigned short portNb, char breakCharacter);
        virtual ~Client();

        int getFd();
        template<typename T>
        T listenToServer()
        {
            T fillstruct;
            size_t readBytes = 0;
            size_t sizeToRead = sizeof(T);

            while (sizeToRead) {
                if (serverIsWriting() == true) {
                    unsigned char *addr = (unsigned char *) &fillstruct;
                    addr += readBytes;
                    size_t tmp = read(_sockFd, addr, sizeToRead);
                    // perror("laa");
                    readBytes += tmp;
                    sizeToRead -= tmp;
                }
            }
            return fillstruct;
        }
        std::string listenToServerStr();
        bool serverIsWriting();
        template<typename T>
        bool sendRequest(T message)
        {
            fd_set set;
            struct timeval timeout = {1, 500};

            while (1) {
                FD_ZERO(&set);
                FD_SET(_sockFd, &set);
                timeout.tv_sec = 0;
                timeout.tv_usec = 500;
                if (select(_sockFd + 1, NULL, &set, NULL, &timeout) > 0)
                    break;
            }
            if (write(_sockFd, &message, sizeof(T)) < 0) {
                throw NetworkException("Client send template method: Can't write on socket");
            }
            return (true);
        }
        bool sendStrRequest(const std::string &message);
};

#endif