/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUpRangeBomb
*/

#ifndef POWERUPRANGEBOMB_HPP_
#define POWERUPRANGEBOMB_HPP_

#include "AObject.hpp"

namespace indie {

    class PowerUpRangeBomb : public indie::AObject {
        public:
            PowerUpRangeBomb(const int &x, const int &y, const int &z);
            virtual ~PowerUpRangeBomb() = default;
            ObjectType getType() const final;
    };

}

#endif /* !POWERUPRANGEBOMB_HPP_ */
