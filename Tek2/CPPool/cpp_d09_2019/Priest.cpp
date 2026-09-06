/*
** EPITECH PROJECT, 2020
** Priest
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    this->_class = "Priest";
    this->_race = "Orc";
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    std::cout << this->_name << " enters in the order\n";
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 10;
    this->Range = Character::RANGE;
    std::cout << this->_name << " uses a spirit explosion\n";
    return (10 + this->_spirit);
}

void Priest::Heal()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power\n";
        return;
    }
    this->_power -= 10;
    this->_pv += 70;
    if (this->_pv > 100)
        this->_pv = 100;
    std::cout << this->_name << " casts a little heal spell\n";
}