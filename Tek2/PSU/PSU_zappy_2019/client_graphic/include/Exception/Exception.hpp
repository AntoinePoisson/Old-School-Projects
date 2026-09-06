/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <iostream>
#include <sstream>

class CliGraphException: public std::exception
{
    public:
        CliGraphException(std::string const &message,
        std::string const &componentName = "Unknown");
        const char *what() const noexcept override;
    protected:
        std::string _message;
};

class NetworkException: public CliGraphException
{
    public:
        NetworkException(std::string const &message, 
        std::string const &componentName = "NetworkException");
};

class UserException: public CliGraphException
{
    public:
        UserException(std::string const &message,
        std::string const &componentName = "UserException");
};


class GraphicException: public CliGraphException
{
    public:
        GraphicException(std::string const &message, 
        std::string const &componentName = "GraphicException");
};

class ControllerException: public CliGraphException
{
    public:
        ControllerException(std::string const &message, 
        std::string const &componentName = "ControlllerException");
};


#endif