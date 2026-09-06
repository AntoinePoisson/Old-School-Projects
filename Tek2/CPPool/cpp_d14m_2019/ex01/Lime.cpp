/*
** EPITECH PROJECT, 2020
** Lime
** File description:
** Lime
*/

#include "Lime.hpp"
#include "Fruit.hpp"

Lime::Lime()
{
    this->_name = "lime";
    this->_vitamins = 2;
}

Lime::~Lime()
{
}

std::string Lime::getName() const
{
    return (this->_name);
}

int Lime::getVitamins() const
{
    return (this->_vitamins);
}