/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerModel
*/

#ifndef PLAYER_MODEL_HPP_
#define PLAYER_MODEL_HPP_

#include "AObject.hpp"

namespace indie
{
    class PlayerModel : public indie::AObject{
        public:
            PlayerModel(const int &x, const int &y, const int &z);
            virtual ~PlayerModel() = default;
            ObjectType getType() const final;
    };
}

#endif /* !PlayerModel_HPP_ */
