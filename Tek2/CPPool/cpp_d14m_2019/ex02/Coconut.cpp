/*
** EPITECH PROJECT, 2020
** Coconut
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut()
: Fruit("coconut", 15)
{
}

Coconut::~Coconut()
{
}

std::string Coconut::getName() const
{
    return (this->_name);
}

int Coconut::getVitamins() const
{
    return (this->_vitamins);
}