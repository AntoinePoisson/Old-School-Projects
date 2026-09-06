/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "AObject.hpp"
#include "Clock.hpp"

namespace indie
{
    template<typename T>
    class Player : public APlayer {
        public:
            Player(const T &x = 0, const T &y = 0, const T &z = 0, const int8_t &color = 0);
            virtual ~Player() = default;
            void setBinding(const T &left = 0, const T &up = 0, const T &right = 0, const T &down = 0, const T &bomb = 0) final;
            direction_t checkCanMove(const int &input) const final;
            ObjectType getType() const final;
    };
}

template<typename T>
indie::Player<T>::Player(const T &x, const T &y, const T &z, const int8_t &color)
{
    _nbr_bomb = DEFAULT_NBR_BOMB;
    setObject("./ressources/assets/player/bomberman.md3");
    _color = color;
    setTexture(std::string("./ressources/assets/player/body" + std::to_string(color) + ".png"));
    setPosition(x, y, z);
    _texture->setAnimationSpeed(50);
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));
}

template<typename T>
void indie::Player<T>::setBinding(const T &left, const T &up, const T &right, const T &down, const T &bomb)
{
    _left = left;
    _up = up;
    _right = right;
    _down = down;
    _bomb = bomb;
}

template<typename T>
indie::direction_t indie::Player<T>::checkCanMove(const int &input) const
{
    if (input == _left) {
        return indie::Left;
    }
    if (input == _up) {
        return indie::Up;
    }
    if (input == _right) {
        return indie::Right;
    }
    if (input == _down) {
        return indie::Down;
    }
    if (input == _bomb) {
        return indie::Bomber;
    }
    return indie::None;
}

template<typename T>
indie::ObjectType indie::Player<T>::getType() const
{
    return indie::ObjectType::PLAYER;
}

#endif /* !PLAYER_HPP_ */
