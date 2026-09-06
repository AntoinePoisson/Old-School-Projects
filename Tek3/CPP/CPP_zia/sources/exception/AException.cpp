/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** AException
*/

#include <sstream>

#include "AException.hpp"

//! Public:
Zia::AException::AException(const std::string &component, const std::string &messageError, unsigned int value)
{
    std::stringstream s1;

    if (value) {
        s1 << "[" << component << "]: " <<  messageError << " (Throw Value: " << std::to_string(value) << ")." << std::endl;
    } else {
        s1 << "[" << component << "]: " <<  messageError << "." << std::endl;
    }
    _messageError = s1.str();
    _returnValue = value;
}

const char *Zia::AException::what() const noexcept
{
    return _messageError.c_str();
}

int Zia::AException::getValue() const noexcept
{
    return _returnValue;
}
