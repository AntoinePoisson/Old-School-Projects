/*
** EPITECH PROJECT, 2020
** BorgQueen
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"

/*
movePtr : points to the move(Destination) method of the Borg::Ship class
firePtr : points to the fire(Federation::Starfleet::Ship *) method of the same class
destroyPtr : points to the fire(Federation::Ship *) method of the same class
*/

Borg::BorgQueen::BorgQueen()
{
    this->movePtr = &Borg::Ship::move;
    this->firePtr = &Borg::Ship::fire;
    this->destroyPtr = &Borg::Ship::fire;

}

Borg::BorgQueen::~BorgQueen()
{
}

bool Borg::BorgQueen::move(Borg::Ship* ship, Destination dest)
{
    return ((ship->*movePtr)(dest));
}

void Borg::BorgQueen::fire(Borg::Ship* ship, Federation::Starfleet::Ship* target)
{
    (ship->*firePtr)(target);
}

void Borg::BorgQueen::destroy(Borg::Ship* ship, Federation::Ship* target)
{
    (ship->*destroyPtr)(target);
}
