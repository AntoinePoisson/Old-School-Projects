/*
** EPITECH PROJECT, 2020
** Banana
** File description:
** Fruit
*/

#include "Banana.hpp"

Banana::Banana()
: Fruit("banana", 5)
{
}

Banana::~Banana()
{
}

std::string Banana::getName() const
{
    return (this->_name);
}

int Banana::getVitamins() const
{
    return (this->_vitamins);
}