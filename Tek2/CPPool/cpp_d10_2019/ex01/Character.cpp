/*
** EPITECH PROJECT, 2020
** Character
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string & name)
: name(name)
{
	ap = 40;
    weapon = nullptr;
}

Character::~Character()
{
}

void Character::recoverAP()
{
    ap += 10;
    if (ap > 40)
        ap = 40;
}

int Character::getAp() const
{
    return (ap);
}

AWeapon *Character::getWeapon() const
{
    return (weapon);
}

void Character::equip(AWeapon *weapon)
{
    this->weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (!weapon || !enemy)
        return;
    int cost = weapon->getAPCost();
    if (ap - cost < 0)
        return;
    int dmg = weapon->getDamage();
    ap -= cost;
    enemy->takeDamage(dmg);
    std::cout << name << " attacks " << enemy->getType() << " with a " << weapon->getName() << std::endl;
    weapon->attack();
    if (enemy->getHP() < 0)
        delete(enemy);
}

std::string const & Character::getName() const
{
    return (name);
}

std::ostream & operator<<(std::ostream & os, const Character & character) {
    if (character.getWeapon()) {
        std::cout << character.getName() << " has " << character.getAp() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
    } else {
        std::cout << character.getName() << " has " << character.getAp() << " AP and is unarmed" << std::endl;
    }
    return (os);
}