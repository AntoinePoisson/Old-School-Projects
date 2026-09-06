/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Error
*/

#include "throw/Error.hpp"

Plazza::Throw::Error::Error(std::string const &component, std::string const &message, int returnValue)
    : message(message), component(component), returnValue(returnValue)
{
    if (message == "")
        messageVoid = true;
    else
        messageVoid = false;
}

std::string const & Plazza::Throw::Error::getComponent() const
{
    return (component);
}

int Plazza::Throw::Error::getValue() const
{
    return (returnValue);
}

const char *Plazza::Throw::Error::what() const throw()
{
    if (messageVoid)
        return (nullptr);
    return (message.c_str());
}