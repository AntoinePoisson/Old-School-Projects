/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** QuitServer
*/

#include "QuitServer.hpp"

babel::QuitServer::QuitServer(std::string component, std::string message, int returnValue)
{
    this->_component = component;
    this->_message = message;
    this->_returnValue = returnValue;
}
