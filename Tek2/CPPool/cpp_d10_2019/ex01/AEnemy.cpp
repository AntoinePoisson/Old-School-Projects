/*
** EPITECH PROJECT, 2020
** AEnemy
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string & type)
: hp(hp), type(type)
{
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage <= 0)
        return;
    hp -= damage;
}

std::string const & AEnemy::getType() const
{
    return (type);
}

int AEnemy::getHP() const
{
    return (hp);
}