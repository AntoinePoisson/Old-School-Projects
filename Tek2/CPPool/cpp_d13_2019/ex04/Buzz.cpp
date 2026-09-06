/*
** EPITECH PROJECT, 2020
** Buzz
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string const & name, std::string const & ascii)
: Toy(BUZZ, name, ascii)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(std::string statement)
{
    std::cout << "BUZZ: " << name << " \"" << statement << "\"" << std::endl;
}