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

Toy::Error::Error()
: type(UNKNOWN)
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
    error.setType(Error::PICTURE);
    return (false);
}

void Toy::Error::setType(ErrorType type)
{
    this->type = type;
}

Toy & Toy::operator=(Toy const & toy)
{
   	type = toy.type;
	name = toy.name;
	picture = toy.picture;
	return (*this); 
}

void Toy::speak(std::string statement)
{
    std::cout << name << " \"" << statement << "\"" << std::endl;
}

bool Toy::speak_es(std::string statement)
{
	error.setType(Error::SPEAK);
    (void)statement;
    return (false);
}

Toy & Toy::operator<<(std::string const & ascii)
{
    picture.data = ascii;
    return (*this);
}

std::ostream & operator<<(std::ostream & os, Toy const & toy)
{
    return (os << toy.getName() << std::endl << toy.getAscii() << std::endl);
}

std::string Toy::Error::what() const
{
    if (type == PICTURE)
        return ("bad new illustration");
    if (type == SPEAK)
        return ("wrong mode");
    return ("");
}

std::string Toy::Error::where() const
{
    if (type == PICTURE)
        return ("setAscii");
    if (type == SPEAK)
        return ("speak_es");
    return ("");
}

Toy::Error const & Toy::getLastError() const
{
    return (this->error);
}