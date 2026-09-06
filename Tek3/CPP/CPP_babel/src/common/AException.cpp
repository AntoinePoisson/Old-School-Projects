/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** AException
*/

#include "AException.hpp"

const char *babel::AException::what() const throw()
{
    return (_messageVoid) ? nullptr : _message.c_str();
}

std::string const &babel::AException::getComponent(void) const
{
    return (_component);
}

std::string const &babel::AException::getMessage(void) const
{
    return (_message);
}

int babel::AException::getValue(void) const
{
    return (_returnValue);
}

void babel::AException::print(void) const
{
    std::cout << _component << ": " << _message << "." << std::endl;
}