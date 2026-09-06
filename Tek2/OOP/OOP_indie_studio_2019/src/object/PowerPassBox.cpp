/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerPassBox
*/

#include "PowerPassBox.hpp"

indie::PowerPassBox::PowerPassBox(const int &x, const int &y, const int &z)
{
    setObject("./ressources/assets/power/source/Bomb.obj");
    setTexture("./ressources/assets/power/textures/ghost.png");
    _texture->setScale(irr::core::vector3df(5, 5, 5));
    setPosition(x, y, z);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));

}

indie::ObjectType indie::PowerPassBox::getType() const
{
    return indie::ObjectType::POWER_PASSBOX;
}