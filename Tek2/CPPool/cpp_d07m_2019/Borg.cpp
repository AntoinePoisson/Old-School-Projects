/*
** EPITECH PROJECT, 2020
** Borg
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    this->_maxWarp = 9;
    this->_maxWarp = 300;

    this->_weaponFrequency = weaponFrequency;
    this->_repair = repair;
    this->_shield = 100;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n";
    std::cout << "Your biological characteristics and technologies will be assimilated.\n";
    std::cout << "Resistance is futile.\n";
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *Core)
{
    this->_core = Core;
}

void Borg::Ship::checkCore(void)
{
    WarpSystem::QuantumReactor *reactor= this->_core->checkReactor();

    if (reactor->isStable())
        std::cout << "Everything is in order.\n";
    else
        std::cout << "Critical failure imminent.\n";
}

bool Borg::Ship::move(int warp, Destination d)
{
    WarpSystem::QuantumReactor *reactor= this->_core->checkReactor();

    if (warp <= this->_maxWarp) {
        if (d != this->_location) {
            if (reactor->isStable() == true) {
                this->_location = d;
                return (true);
            }
        }
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    WarpSystem::QuantumReactor *reactor= this->_core->checkReactor();

    if (warp <= this->_maxWarp) {
        if (this->_home != this->_location) {
            if (reactor->isStable() == true) {
                this->_location = this->_home;
                return (true);
            }
        }
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    WarpSystem::QuantumReactor *reactor= this->_core->checkReactor();

    if (d != this->_location) {
        if (reactor->isStable() == true) {
            this->_location = d;
            return (true);
        }
    }
    return (false);
}

bool Borg::Ship::move()
{
    WarpSystem::QuantumReactor *reactor= this->_core->checkReactor();

    if (this->_home != this->_location) {
        if (reactor->isStable() == true) {
            this->_location = this->_home;
            return (true);
        }
    }
    return (false);
}



int Borg::Ship::getShield()
{
    return (this->_shield);
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return (this->_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return (this->_repair);
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}


void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    int shield = target->getShield();

    if (shield > 0) {
        target->setShield(shield - this->_weaponFrequency);
        if (target->getShield() < 0)
            target->setShield(0);   
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency.\n";
    }
}

void Borg::Ship::fire(Federation::Ship *target)
{
    WarpSystem::Core *Core = target->getCore();
    WarpSystem::QuantumReactor *react = Core->checkReactor();

    if (react->isStable()) {
        react->setStability(false);
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency.\n";
    }
}

void Borg::Ship::repair()
{
    if (this->_repair > 0) {
        this->_repair -= 1;
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation...  Done. Awaiting further instructions.\n";
    } else {
        std::cout << "Energy cells depleted, shield weakening.\n";
    }
}