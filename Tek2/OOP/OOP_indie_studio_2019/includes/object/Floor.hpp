/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Floor
*/

#ifndef FLOOR_HPP_
#define FLOOR_HPP_

#include "AObject.hpp"

namespace indie
{
    class Floor : public indie::AObject{
        public:
            Floor(const int &x, const int &y, const int &z);
            virtual ~Floor() = default;
            ObjectType getType() const final;
    };
}
#endif /* !FLOOR_HPP_ */
