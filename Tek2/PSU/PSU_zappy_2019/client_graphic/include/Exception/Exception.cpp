/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Exception
*/

#include "Exception.hpp"

CliGraphException::CliGraphException(std::string const &message, 
            std::string const &componentName) {
                std::ostringstream ss;
                ss << componentName << ": " << message << "." << std::endl;
                _message = ss.str();
            }

const char *CliGraphException::what()
const
noexcept
{
    return (_message.c_str());
}

NetworkException::NetworkException(
    std::string const &message,
    std::string const &componentName): CliGraphException(message, componentName)
{}

UserException::UserException(
    std::string const &message,
    std::string const &componentName): CliGraphException(message, componentName)
{}

GraphicException::GraphicException(
    std::string const &message,
    std::string const &componentName): CliGraphException(message, componentName)
{}

ControllerException::ControllerException(
    std::string const &message,
    std::string const &componentName): CliGraphException(message, componentName)
{}