/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** QueueMessage
*/

#include "throw/QueueMessage.hpp"

Plazza::Throw::QueueMessage::QueueMessage(std::string const &message)
    : message(message)
{}

const char *Plazza::Throw::QueueMessage::what() const throw()
{
    return (message.c_str());
}