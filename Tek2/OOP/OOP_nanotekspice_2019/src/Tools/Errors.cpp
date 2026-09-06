/*
** EPITECH PROJECT, 2020
** Error
** File description:
** Error
*/

#include "Errors.hpp"

Errors::Errors(std::string const &message, std::string const &component)
: _message(message), _component(component)
{
}

std::string const & Errors::getComponent() const
{
    return (_component);
}

const char *Errors::what() const throw()
{
    return (_message.c_str());
}

// Exemple::Exemple(std::string const &message, std::string const &component)
// : Errors(message, component)
// {}