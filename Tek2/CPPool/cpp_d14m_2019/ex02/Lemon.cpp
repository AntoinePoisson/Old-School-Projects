/*
** EPITECH PROJECT, 2020
** Lemon
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon()
: Fruit("lemon", 3)
{
}

Lemon::~Lemon()
{
}

std::string Lemon::getName() const
{
    return (this->_name);
}

int Lemon::getVitamins() const
{
    return (this->_vitamins);
}