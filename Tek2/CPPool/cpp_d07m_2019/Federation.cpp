/*
** EPITECH PROJECT, 2020
** Federation
** File description:
** Federation
*/

#include "Federation.hpp"

    // StartFleet

    // Ship

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_photonTorpedo = torpedo;

    std::cout << "The ship USS " << name << " has been finished.\n";
    std::cout << "It is " << length << " m in length and " << width << " m in width.\n";
    std::cout << "It can go to Warp " << maxWarp << "!\n";
    if (torpedo != 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready.\n";
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *Core)
{
    std::cout << "USS " << this->_name << ": The core is set.\n";
    this->_core = Core;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    WarpSystem::QuantumReactor *reactor= this->_core->checkReactor();

    if (reactor->isStable())
        std::cout << "USS " << this->_name << ": The core is " << "stable" << " at the time.\n";
    else
        std::cout << "USS " << this->_name << ": The core is " << "unstable" << " at the time.\n";
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    this->_captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << ".\n";
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
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

bool Federation::Starfleet::Ship::move(int warp)
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

bool Federation::Starfleet::Ship::move(Destination d)
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

bool Federation::Starfleet::Ship::move()
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

int Federation::Starfleet::Ship::getShield()
{
    return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    int shield = target->getShield();

    if (this->_photonTorpedo - 1 >= 0) {
        this->_photonTorpedo -= 1;
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining.\n";
        if (this->_photonTorpedo == 0) {
            std::cout << this->_name << ": No more torpedo to fire , " << this->_captain->getName() << "!\n";
        }
        target->setShield(shield - 50);
        if (target->getShield() < 0)
            target->setShield(0);
    } else {
        std::cout << this->_name << ": No enough torpedoes to fire , " << this->_captain->getName() << "!\n";
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    int shield = target->getShield();

    if (this->_photonTorpedo - torpedoes >= 0) {
        this->_photonTorpedo -= torpedoes;
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining.\n";
        if (this->_photonTorpedo <= 0) {
            this->_photonTorpedo = 0;
            std::cout << this->_name << ": No more torpedo to fire , " << this->_captain->getName() << "!\n";
        }
        target->setShield(shield - 50 * torpedoes);
        if (target->getShield() < 0)
            target->setShield(0);
    } else {
        std::cout << this->_name << ": No enough torpedoes to fire , " << this->_captain->getName() << "!\n";
    }
}

    // Captain

Federation::Starfleet::Captain::Captain(std:: string captain)
{
    this->_name = captain;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}
int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}
void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

    // Ensign

Federation::Starfleet::Ensign::Ensign(std:: string name)
{
    this->_name = name;
    std::cout << "Ensign " << name << ", awaiting orders.\n";
}

Federation::Starfleet::Ensign::~Ensign()
{
}


    // Indépendant

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;

    std::cout << "The independent ship " << name << " just finished its construction.\n";
    std::cout << "It is " << length << " m in length and " << width << " m in width.\n";
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *Core)
{
    std::cout << this->_name << ": The core is set.\n";
    this->_core = Core;
}

void Federation::Ship::checkCore(void)
{
    WarpSystem::QuantumReactor *reactor= this->_core->checkReactor();

    if (reactor->isStable())
        std::cout << this->_name << ": The core is " << "stable" << " at the time.\n";
    else
        std::cout << this->_name << ": The core is " << "unstable" << " at the time.\n";
}

bool Federation::Ship::move(int warp, Destination d)
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

bool Federation::Ship::move(int warp)
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

bool Federation::Ship::move(Destination d)
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

bool Federation::Ship::move()
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

WarpSystem::Core *Federation::Ship::getCore()
{
    return (this->_core);
}

// int Federation::Ship::getShield()
// {
//     return (this->_shield);
// }

// void Federation::Ship::setShield(int shield)
// {
//     this->_shield = shield;
// }

// int Federation::Ship::getTorpedo()
// {
//     return (this->_photonTorpedo);
// }

// void Federation::Ship::setTorpedo(int torpedo)
// {
//     this->_photonTorpedo = torpedo;
// }