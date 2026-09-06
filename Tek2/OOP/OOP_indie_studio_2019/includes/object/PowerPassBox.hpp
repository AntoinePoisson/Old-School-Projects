/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerPassBox
*/

#ifndef POWERPASSBOX_HPP_
#define POWERPASSBOX_HPP_

#include "AObject.hpp"

namespace indie {

    class PowerPassBox : public indie::AObject {
        public:
            PowerPassBox(const int &x, const int &y, const int &z);
            virtual ~PowerPassBox() = default;
            ObjectType getType() const final;
    };

}

#endif /* !POWERPASSBOX_HPP_ */
