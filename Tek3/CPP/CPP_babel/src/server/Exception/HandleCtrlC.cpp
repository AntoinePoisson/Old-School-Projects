/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** HandleCtrlC
*/

#include "HandleCtrlC.hpp"

babel::HandleCtrlC::HandleCtrlC(std::string component, std::string message, int returnValue)
{
    this->_component = component;
    this->_message = message;
    this->_returnValue = returnValue;
}
