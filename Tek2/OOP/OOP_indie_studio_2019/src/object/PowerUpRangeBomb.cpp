/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUpRangeBomb
*/

#include "PowerUpRangeBomb.hpp"

indie::PowerUpRangeBomb::PowerUpRangeBomb(const int &x, const int &y, const int &z)
{
    setObject("./ressources/assets/power/source/Bomb.obj");
    setTexture("./ressources/assets/power/textures/extrabomb.png");
    _texture->setScale(irr::core::vector3df(5, 5, 5));
    setPosition(x, y, z);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));

}

indie::ObjectType indie::PowerUpRangeBomb::getType() const
{
    return indie::ObjectType::POWER_UPRANGEBOMB;
}