/*
** EPITECH PROJECT, 2020
** AWeapon
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
: name(name), apcost(apcost), damage(damage) {
}

AWeapon::~AWeapon()
{
}

std::string const & AWeapon::getName() const
{
    return (name);
}

int AWeapon::getAPCost() const
{
    return (apcost);
}

int AWeapon::getDamage() const
{
    return (damage);
}
