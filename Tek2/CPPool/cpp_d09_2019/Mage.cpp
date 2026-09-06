/*
** EPITECH PROJECT, 2020
** Mage
** File description:
** Priest
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->_class = "Mage";
    this->_race = "Gnome";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;

    std::cout << name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 10;
    this->Range = Character::RANGE;
    std::cout << this->_name << " blinks\n";
    return (0);
}

int Mage::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 25;
    std::cout << this->_name << " launches a fire ball\n";
    return (20 + this->_spirit);
}

void Mage::RestorePower()
{
    this->_power += 50 + this->_intelligence;
    if (this->_power > 100)
        this->_power = 100;
    std::cout << this->_name << " takes a mana potion\n";
}
