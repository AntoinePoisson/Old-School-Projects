/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerSpeedUp
*/

#ifndef POWERSPEEDUP_HPP_
#define POWERSPEEDUP_HPP_

#include "AObject.hpp"

namespace indie {

    class PowerSpeedUp : public indie::AObject {
        public:
            PowerSpeedUp(const int &x, const int &y, const int &z);
            virtual ~PowerSpeedUp() = default;
            ObjectType getType() const final;
    };

}

#endif /* !POWERSPEEDUP_HPP_ */
