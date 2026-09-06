/*
** EPITECH PROJECT, 2020
** Phaser
** File description:
** Phaser
*/

#include "Phaser.hpp"
#include "Sounds.hpp"


Phaser::Phaser(int maxAmmo, AmmoType type)
{
    this->_maxAmmo = maxAmmo;
    this->_type = type;
    this->_ammo[0] = maxAmmo;
    this->_ammo[1] = maxAmmo;
    this->_ammo[2] = maxAmmo;
}

Phaser::~Phaser()
{
}

void Phaser::fire()
{
    if (this->_ammo[this->_type] == 0) {
        std::cout << "Clip empty, please reload\n";
    } else {
        this->_ammo[this->_type] -= 1;
        if (this->_type == REGULAR)
            std::cout << Sounds::Regular << "\n";
        if (this->_type == PLASMA)
            std::cout << Sounds::Plasma << "\n";
        if (this->_type == ROCKET)
            std::cout << Sounds::Rocket << "\n";
    }
}

void Phaser::ejectClip()
{
    this->_ammo[this->_type] = 0;
}

void Phaser::changeType(AmmoType newType)
{
    if (newType == REGULAR) {
        std::cout << "Switching ammo to type: " << "regular" << "\n";
        this->_type = newType;
    } else if (newType == PLASMA) {
        std::cout << "Switching ammo to type: " << "plasma" << "\n";
        this->_type = newType;    
    } else if (newType == ROCKET) {
        std::cout << "Switching ammo to type: " << "rocket" << "\n";
        this->_type = newType;    
    }
}

void Phaser::reload()
{
    std::cout << "Reloading...\n";
    this->_ammo[this->_type] = this->_maxAmmo;
}

void Phaser::addAmmo(AmmoType type)
{
    int current = this->_ammo[type];

    if (current != this->_maxAmmo) {
        this->_ammo[type] += 1;
    } else {
        std::cout << "Clip full\n";
    }
}

int Phaser::getCurrentAmmos()
{
    return (this->_ammo[this->_type]);
}