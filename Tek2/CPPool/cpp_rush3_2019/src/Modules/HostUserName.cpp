/*
** EPITECH PROJECT, 2020
** cpp_rush_2
** File description:
** santa.hpp
*/

#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <iostream>
#include <sys/utsname.h>
#include "Modules/HostUserName.hpp"

HostUserName::HostUserName(std::string const &name)
{
    char hostname[HOST_NAME_MAX];
    char username[LOGIN_NAME_MAX];

    gethostname(hostname, HOST_NAME_MAX);
    getlogin_r(username, LOGIN_NAME_MAX);
    this->_data.push_back(hostname);
    this->_data.push_back(username);
    _name = name;
}

void HostUserName::refreshData()
{
    char hostname[HOST_NAME_MAX];
    char username[LOGIN_NAME_MAX];

    gethostname(hostname, HOST_NAME_MAX);
    getlogin_r(username, LOGIN_NAME_MAX);
    this->_data.clear();
    this->_data.push_back(hostname);
    this->_data.push_back(username);
}
