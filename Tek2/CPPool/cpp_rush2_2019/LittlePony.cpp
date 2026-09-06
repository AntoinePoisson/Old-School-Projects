/*
** EPITECH PROJECT, 2020
** LittlePony
** File description:
** rush2
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string str) : Toy(str)
{
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}