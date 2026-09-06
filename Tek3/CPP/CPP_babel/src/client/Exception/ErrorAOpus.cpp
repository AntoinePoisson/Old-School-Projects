/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** ErrorAOpus
*/

#include "ErrorAOpus.hpp"

babel::ErrorAOpus::ErrorAOpus(std::string component, std::string message, int returnValue)
{
    this->_component = component;
    this->_message = message;
    this->_returnValue = returnValue;
}
