/*
** EPITECH PROJECT, 2020
** Admiral
** File description:
** Admiral
*/

#include "Admiral.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name)
{
    this->_name = name;
    std::cout << "Admiral " << name << " ready for action.\n";
    this->movePtr = &Federation::Starfleet::Ship::move;
    this->firePtr = &Federation::Starfleet::Ship::fire;
}

Federation::Starfleet::Admiral::~Admiral()
{
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship* ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << this->_name << ":\n";
    (ship->*firePtr)(target);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship* ship, Destination dest)
{
    
    return ((ship->*movePtr)(dest));
}