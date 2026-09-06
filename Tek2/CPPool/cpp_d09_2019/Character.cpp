/*
** EPITECH PROJECT, 2020
** Character
** File description:
** std::string name
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->_name = name;
    this->_level = level;
    this->_race = "Human";
    this->_class = "Character";
    this->_pv = 100;
    this->_power = 100;
    this->_intelligence = 5;
    this->_stamina = 5;
    this->_spirit = 5;
    this->_strength = 5;
    this->_agility = 5;
    std::cout << this->_name << " Created\n";
}

Character::~Character()
{
}

const std::string &Character::getName() const
{
    return (this->_name);
}

int Character::getLvl() const
{
    return (this->_level);
}

int Character::getPv() const
{
    return (this->_pv);
}

int Character::getPower() const
{
    return (this->_power);
}

int Character::getStamina() const
{
    return (this->_stamina);
}

int Character::getSpirit() const
{
    return (this->_spirit);
}

int Character::getAgility() const
{
    return (this->_agility);
}

int Character::getStrength() const
{
    return (this->_strength);
}

std::string Character::getRace() const
{
    return (this->_race);
}

std::string Character::getClass() const
{
    return (this->_class);
}


int Character::CloseAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 10;
    std::cout << this->_name << " strikes with a wooden stick\n";
    return (10 + this->_strength);
}

void Character::Heal()
{
    this->_pv += 50;
    if (this->_pv > 100)
        this->_pv = 100;
    std::cout << this->_name << " takes a potion\n";
}

int Character::RangeAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power\n";
        return (0);
    }
    this->_power -= 10;
    std::cout << this->_name << " tosses a stone\n";
    return (5 + this->_strength);
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats\n";
}

void Character::TakeDamage(int damage)
{
    if (damage == 0)
        return;
    this->_pv -= damage;
    if (this->_pv <= 0) {
        std::cout << this->_name << " out of combat\n";
        this->_pv = 0;
        return;
    }
    std::cout << this->_name << " takes " << damage << " damage\n";
}