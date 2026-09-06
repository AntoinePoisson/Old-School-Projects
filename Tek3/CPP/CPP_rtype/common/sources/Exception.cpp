/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Exception
*/

#include "AException.hpp"
#include "components/Exception.hpp"

rtype::AException::AException(const std::string &str_error, const std::string &componentName, unsigned int valueThrow)
{
    std::stringstream s1;

    if (valueThrow) {
        s1 << "[" << componentName << "]: " <<  str_error << " (Throw Value: " << std::to_string(valueThrow) << ")." << std::endl;
    } else {
        s1 << "[" << componentName << "]: " <<  str_error << "." << std::endl;
    }
    _str_error = s1.str();
    _value = valueThrow;
}

const char *rtype::AException::what() const noexcept
{
    return _str_error.c_str();
}

int rtype::AException::getValue() const noexcept
{
    return _value;
}

rtype::NetworkException::NetworkException(const std::string &str_error, const std::string &componentName, unsigned int valueThrow):
AException(str_error, componentName, valueThrow) {}

rtype::GameIsFinish::GameIsFinish(const std::string &str_error, const std::string &componentName, unsigned int valueThrow):
AException(str_error, componentName, valueThrow) {}
