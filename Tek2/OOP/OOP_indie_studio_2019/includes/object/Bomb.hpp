/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "AObject.hpp"
#include "Clock.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Particles.hpp"

namespace indie {

    class Bomb : public indie::AObject {
        public:
            Bomb(const int &x, const int &y, const int &z, int range);
            virtual ~Bomb() = default;

            bool isExplosion(std::vector<std::vector<indie::map::mapElement_t>> &map, int indexX, int indexY, std::vector<indie::APlayer*> getPlayer, std::vector<indie::Box> &mapBox);
            int getRangeBomb(void) const;
            ObjectType getType() const final;
            vector3di getCenter();
        private:
            indie::Clock _clock;
            int _x = 0;
            int _y = 0;
            bool _animation;
            int _rangeBomb = 0;
            std::vector<indie::Particles *> _particles = {};
    };

}

#endif /* !BOMB_HPP_ */