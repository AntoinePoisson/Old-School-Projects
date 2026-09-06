/*
** EPITECH PROJECT, 2020
** Sorcerer
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title <<  ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const
{
    return (this->_name);
}

std::string Sorcerer::getTitle() const
{
    return (this->_title);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(const Peon &peon) const
{
    peon.getPolymorphed();
}

std::ostream & operator<<(std::ostream & os, Sorcerer & sorcerer) {
	return (os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl);
}