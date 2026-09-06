/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include "AObject.hpp"

namespace indie
{
    class Wall : public indie::AObject{
        public:
            Wall(const int &x, const int &y, const int &z);
            virtual ~Wall() = default;
            ObjectType getType() const final;
    };
}

#endif /* !WALL_HPP_ */
