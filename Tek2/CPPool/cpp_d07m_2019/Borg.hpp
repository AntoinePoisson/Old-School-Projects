/*
** EPITECH PROJECT, 2020
** Borg
** File description:
** Borg
*/

#ifndef BORG_H
#define BORG_H

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"


namespace Federation {
    namespace Starfleet {
        class Ship;
        class Captain;
        class Ensign;
    }
    class Ship;
}


namespace Borg {
    class Ship {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore(void);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();

        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location = UNICOMPLEX;
            Destination _home = UNICOMPLEX;
            int _shield = 100;
            int _weaponFrequency;
            short _repair;
    };
};

#endif /* !BORG_H */
