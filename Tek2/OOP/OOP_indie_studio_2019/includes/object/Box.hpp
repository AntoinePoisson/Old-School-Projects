/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "AObject.hpp"
#include "PowerSpeedUp.hpp"
#include "PowerPassBox.hpp"
#include "PowerMoreBomb.hpp"
#include "PowerUpRangeBomb.hpp"

namespace indie
{
    class Box : public indie::AObject{
        public:
            Box(const int &x, const int &y, const int &z);
            virtual ~Box() = default;
            void ExplosionBox(void);
            void OffPower(void);
            void deletBox(void);
            void setType(indie::ObjectType type);
            ObjectType getType(void) const final;
        private:
            indie::ObjectType type;
            std::shared_ptr<indie::AObject> power;
    };
}
#endif /* !BOX_HPP_ */
