/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Logger
*/

#include "Logger.hpp"
#include "../../exception/AException.hpp"

    //! Public
Zia::Logger::Logger(const std::string &nameFile)
: _file(nameFile)
{
    if (!_file.is_open()) {
        throw AException("Logger", "Can't create or read in file:" + nameFile);
    }
}

Zia::Logger::~Logger()
{
    _file.close();
}

void Zia::Logger::log(const std::string &str)
{
    _mutex.lock();
    _file << str << std::endl;
    _mutex.unlock();
}