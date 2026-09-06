/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Life
*/

#ifndef COMMONCOMPONENTLIFE_HPP_
#define COMMONCOMPONENTLIFE_HPP_

#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        enum DamageType {
            PHYSICAL,
            FIRE,
            EXPLOSION
        };

        struct Damage : public AComponent
        {
            Damage(double damage, enum DamageType dType) : AComponent(), _damage(damage), _dType(dType) {};

            double _damage;
            enum DamageType _dType;
        };

        struct Life : public AComponent
        {
            Life(double life) : AComponent(), _life(life) {};
            Life(const struct Life &l){
                _life = l._life;
            };

            double _life;
        };

        struct Level : public AComponent
        {
            Level(int level) : AComponent(), _level(level) {};

            int _level;
        };

    }
}

#endif /* !COMMONCOMPONENTLIFE_HPP_ */
