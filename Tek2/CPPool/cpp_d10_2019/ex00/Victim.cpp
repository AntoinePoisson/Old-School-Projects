/*
** EPITECH PROJECT, 2020
** Victim
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getName() const
{
    return (this->_name);
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream & operator<<(std::ostream & os, Victim & victim)
{
    return (os << "I'm " << victim.getName() << " and I like otters!" << std::endl);
}