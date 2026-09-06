/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** ErrorSql
*/

#include "ErrorSql.hpp"

babel::ErrorSql::ErrorSql(std::string component, std::string message, int returnValue)
{
    this->_component = component;
    this->_message = message;
    this->_returnValue = returnValue;
}