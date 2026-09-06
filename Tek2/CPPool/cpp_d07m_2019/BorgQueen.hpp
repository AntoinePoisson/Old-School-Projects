/*
** EPITECH PROJECT, 2020
** BorgQueen
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN
#define BORGQUEEN

#include <iostream>
#include "Destination.hpp"
#include "Federation.hpp"
#include "Borg.hpp"

namespace Borg {
    class BorgQueen {
        public:
            BorgQueen();
            ~BorgQueen();
            bool (Borg::Ship::*movePtr)(Destination) = nullptr;
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *) = nullptr;
            void (Borg::Ship::*destroyPtr)(Federation::Ship *) = nullptr;
            bool move(Borg::Ship* ship, Destination dest);
            void fire(Borg::Ship* ship, Federation::Starfleet::Ship* target);
            void destroy(Borg::Ship* ship, Federation::Ship* target);

        private:
    };
}

#endif /* !BORGQUEEN */
