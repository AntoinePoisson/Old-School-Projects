/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Wall
*/

#include "PlayerModel.hpp"

indie::PlayerModel::PlayerModel(const int &x, const int &y, const int &z)
{
    setObject("./ressources/assets/player/bomberman.md3");
    setTexture("./ressources/assets/player/body.png");
    setPosition(x, y, z);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));
}

indie::ObjectType indie::PlayerModel::getType() const
{
    return static_cast<indie::ObjectType>(0);
}