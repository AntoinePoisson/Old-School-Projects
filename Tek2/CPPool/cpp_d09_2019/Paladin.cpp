/*
** EPITECH PROJECT, 2020
** Paladin
** File description:
** Paladin
*/

#include "Paladin.hpp"


Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_race = "Human";
    this->_class = "Paladin";
    this->_strength = 9;
    this->_intelligence = 10;
    this->_stamina = 10;
    this->_spirit = 10;
    this->_agility = 2;
    this->_weaponName = "hammer";

    std::cout << "the light falls on " << this->_name << "\n";
}

Paladin::~Paladin()
{
}


int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}