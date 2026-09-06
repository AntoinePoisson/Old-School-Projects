/*
** EPITECH PROJECT, 2020
** Toy
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    type = BASIC_TOY;
    name = "toy";
    picture = Picture();
}

Toy::Toy(ToyType type, std::string const & name, std::string const & ascii)
: type(type), name(name), picture(ascii)
{
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return (this->type);
}

std::string const & Toy::getName() const
{
    return (this->name);
}

std::string const & Toy::getAscii() const
{
    return (this->picture.data);
}

void Toy::setName(std::string const &name)
{
    this->name = name;
}

bool Toy::setAscii(std::string const &name)
{
    if (picture.getPictureFromFile(name)) {
        return (true);
    }
    return (false);
}
