/*
** EPITECH PROJECT, 2020
** Peon
** File description:
** Peon
*/

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;

}

std::ostream & operator<<(std::ostream & os, Peon & peon)
{
    return (os << "I'm " << peon.getName() << " and I like otters!" << std::endl);
}