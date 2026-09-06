/*
** EPITECH PROJECT, 2020
** Hunter
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_race = "Elf";
    this->_class = "Hunter";
    this->_strength = 9;
    this->_intelligence = 5;
    this->_stamina = 9;
    this->_spirit = 6;
    this->_agility = 25;
    this->_agility = 25;
    this->_weaponName = "sword";

    std::cout << this->_name << " is born from a tree\n";
}

Hunter::~Hunter()
{
}

int Hunter::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 25;
    std::cout << this->_name << " uses his bow\n";
    return (20 + this->_agility);
}

void Hunter::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " meditates\n";
}
