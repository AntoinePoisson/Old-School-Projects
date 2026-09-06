/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Wall
*/

#include "Wall.hpp"

indie::Wall::Wall(const int &x, const int &y, const int &z)
{
    if (indie::irrlicht->quality != 2) {
        setObject("./ressources/assets/box1/source/cubeBoxLP.obj");
        setTexture("./ressources/assets/box1/textures/coatCubeBoxColors2.png");
    } else {
        setObject("./ressources/assets/box1/source/cubeBoxLV.obj");
        setTexture("./ressources/assets/box1/textures/cubeBoxLV_brick.png");
    }
    setPosition(x, y, z);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));
}

indie::ObjectType indie::Wall::getType() const
{
    return indie::ObjectType::WALL;
}