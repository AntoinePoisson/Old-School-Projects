/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string const &component, std::string const &message, int returnValue)
    : message(message), component(component), returnValue(returnValue)
{
    if (message == "")
        messageVoid = true;
    else
        messageVoid = false;
}

std::string const & Error::getComponent() const
{
    return (component);
}

int Error::getValue() const
{
    return (returnValue);
}

const char *Error::what() const throw()
{
    if (messageVoid)
        return (nullptr);
    return (message.c_str());
}