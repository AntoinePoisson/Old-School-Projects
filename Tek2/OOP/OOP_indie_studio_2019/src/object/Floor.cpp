/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Floor
*/

#include "Floor.hpp"

indie::Floor::Floor(const int &x, const int &y, const int &z)
{
    static int change = 0;

    setObject("./ressources/assets/box1/source/cubeBoxLI.obj");
    setTexture(change % 2 ? "./ressources/assets/floor/textures/GroundGrassAstroTurfRealistic001_COL_1K.jpeg" :
        "./ressources/assets/floor/textures/GroundGrassFieldGreen001_COL_1K.jpeg");
    setPosition(x, y, z);
    this->_texture->setScale(irr::core::vector3df(1.05, 1.05, 1.05));
    setObject("./ressources/assets/box1/source/cubeBoxLI.obj");
    setTexture(change % 2 ? "./ressources/assets/floor/textures/GroundGrassAstroTurfRealistic001_COL_1K.jpeg" :
        "./ressources/assets/floor/textures/GroundGrassFieldGreen001_COL_1K.jpeg");
    setPosition(x + 1, y, z);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));
    change++;
}

indie::ObjectType indie::Floor::getType() const
{
    return indie::ObjectType::FLOOR;
}