/*
** EPITECH PROJECT, 2020
** Warrior
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
    this->_class = "Warrior";
    this->_race = "Dwarf";
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
    this->_weaponName = "hammer";

    std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n";
}

Warrior::~Warrior()
{
}

std::string Warrior::getweaponName()
{
    return (this->_weaponName);
}
std::string Warrior::getWeaponname()
{
    return (this->_weaponName);
}
std::string Warrior::getWeaponName()
{
    return (this->_weaponName);
}



int Warrior::CloseAttack()
{
    if (this->_power < 30) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 30;
    std::cout << this->_name << " strikes with his " << this->_weaponName << "\n";
    return (20 + this->_strength);
}

int Warrior::RangeAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 10;
    this->Range = Character::CLOSE;
    std::cout << this->_name << " intercepts\n";
    return (0);
}