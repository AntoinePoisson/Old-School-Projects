/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Error
*/

#include "Error.hpp"

indie::error::Error::Error(std::string const &component, std::string const &message, int returnValue)
    : message(message), component(component), returnValue(returnValue)
{
    if (message.empty())
        messageVoid = true;
    else
        messageVoid = false;
}

std::string const &indie::error::Error::getComponent() const
{
    return (component);
}

int indie::error::Error::getValue() const
{
    return (returnValue);
}

const char *indie::error::Error::what() const throw()
{
    return (messageVoid) ? nullptr : message.c_str();
}