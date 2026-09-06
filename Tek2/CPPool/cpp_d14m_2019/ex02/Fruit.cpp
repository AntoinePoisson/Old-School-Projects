/*
** EPITECH PROJECT, 2020
** Fruit
** File description:
** Banana
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string const &name, int _vitamins)
: _name(name), _vitamins(_vitamins)
{
}

Fruit::~Fruit()
{
}

std::string Fruit::getName() const
{
    return (this->_name);
}

int Fruit::getVitamins() const
{
    return (this->_vitamins);
}