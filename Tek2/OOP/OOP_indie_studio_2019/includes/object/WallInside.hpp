/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WallInside
*/

#ifndef WALLINSIDE_HPP_
#define WALLINSIDE_HPP_

#include "AObject.hpp"

namespace indie
{
    class WallInside : public indie::AObject{
        public:
            WallInside(const int &x, const int &y, const int &z);
            virtual ~WallInside() = default;
            ObjectType getType() const final;
    };
}

#endif /* !WALLINSIDE_HPP_ */
