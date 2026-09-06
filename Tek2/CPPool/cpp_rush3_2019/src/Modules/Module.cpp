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
#include "Modules/Module.hpp"

std::vector<std::string> const &Module::getData()
{
    return (this->_data);
}

std::vector<std::string> const &Module::getRefreshData()
{
    this->refreshData();
    return (this->_data);
}

std::string const &Module::getName()
{
    return (this->_name);
}

void Module::setName(std::string const &name)
{
    this->_name = name;
}
