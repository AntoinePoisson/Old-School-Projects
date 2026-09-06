/*
** EPITECH PROJECT, 2020
** Toy.cpp
** File description:
** Rush2
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string str) : Toy(str)
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}