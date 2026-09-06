/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** IPC
*/

#ifndef IPC_HPP_
#define IPC_HPP_

#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include "Exception.hpp"
#include <string>

class IPC {
    public:
        IPC() {};
        virtual ~IPC() = default;
        void setFd(int fd);
        bool operator<<(const std::string &newStr);
        bool operator>>(std::string &newStr);
    protected:
    int _fd;
};


#endif