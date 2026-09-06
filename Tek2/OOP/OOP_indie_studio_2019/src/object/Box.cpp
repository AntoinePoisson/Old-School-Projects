/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Box
*/

#include "Box.hpp"

indie::Box::Box(const int &x, const int &y, const int &z)
{
    if (indie::irrlicht->quality == 0) {
        setObject("./ressources/assets/box1/source/cubeBoxLP.obj");
        setTexture("./ressources/assets/box1/textures/coatCubeBoxColors.png");
    } else {
        setObject("./ressources/assets/box1/source/cubeBoxLV.obj");
        setTexture("./ressources/assets/box1/textures/cubeBoxLV.png");
    }
    setPosition(x, y, z);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));
    type = indie::ObjectType::BOX;
}

void indie::Box::ExplosionBox(void)
{
    int isBox = rand() % 4;

    if (type != indie::ObjectType::BOX) {
        return;
    }
    if (rand() % 2 == 1) {
        switch (isBox) {
            case 0:
                power = std::move(std::make_shared<indie::PowerMoreBomb>(this->getX(), this->getY(), this->getZ()));
                type = indie::ObjectType::POWER_MOREBOMB;
                break;
            case 1:
                power = std::move(std::make_shared<indie::PowerPassBox>(this->getX(), this->getY(), this->getZ()));
                type = indie::ObjectType::POWER_PASSBOX;
                break;
            case 2:
                power = std::move(std::make_shared<indie::PowerUpRangeBomb>(this->getX(), this->getY(), this->getZ()));
                type = indie::ObjectType::POWER_UPRANGEBOMB;
                break;
            case 3:
                power = std::move(std::make_shared<indie::PowerSpeedUp>(this->getX(), this->getY(), this->getZ()));
                type = indie::ObjectType::POWER_SPEED;
                break;
            default:
                power = std::move(std::make_shared<indie::PowerMoreBomb>(this->getX(), this->getY(), this->getZ()));
                type = indie::ObjectType::POWER_MOREBOMB;
                break;
        }
    } else {
        type = indie::ObjectType::NONE;
    }
    getNode()->remove();
    setState(false);
}

void indie::Box::setType(indie::ObjectType tipe)
{
    type = tipe;
}

void indie::Box::deletBox()
{
    getNode()->remove();
    setState(false);
    type = indie::ObjectType::NONE;
}

void indie::Box::OffPower(void)
{
    if (type == indie::ObjectType::BOX)
        return;
    power->getNode()->remove();
    power->setState(false);
    type = indie::ObjectType::NONE;
}

indie::ObjectType indie::Box::getType() const
{
    return type;
}
