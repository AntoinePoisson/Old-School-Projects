/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** FataleErrorSql
*/

#include "FataleErrorSql.hpp"

babel::FataleErrorSql::FataleErrorSql(std::string component, std::string message, int returnValue)
{
    this->_component = component;
    this->_message = message;
    this->_returnValue = returnValue;
}