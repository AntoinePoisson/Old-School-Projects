/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerMoreBomb
*/

#ifndef POWERMOREBOMB_HPP_
#define POWERMOREBOMB_HPP_

#include "AObject.hpp"

namespace indie {

    class PowerMoreBomb : public indie::AObject {
        public:
            PowerMoreBomb(const int &x, const int &y, const int &z);
            virtual ~PowerMoreBomb() = default;
            ObjectType getType() const final;
    };

}

#endif /* !POWERMOREBOMB_HPP_ */
