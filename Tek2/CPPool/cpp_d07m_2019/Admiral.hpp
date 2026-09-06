/*
** EPITECH PROJECT, 2020
** Admiral
** File description:
** Admiral
*/

#ifndef ADMIRAL_H
#define ADMIRAL_H

#include <iostream>
#include "Destination.hpp"
#include "Federation.hpp"
#include "Borg.hpp"

namespace Federation {
    namespace Starfleet {
        class Ship;
    }
}

namespace Federation {
    namespace Starfleet {
        class Admiral {
            public:
                Admiral(std::string);
                ~Admiral();
                bool (Federation::Starfleet::Ship::*movePtr)(Destination) = nullptr;
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *) = nullptr;
                void fire(Federation::Starfleet::Ship* ship, Borg::Ship *target);
                bool move(Federation::Starfleet::Ship* ship, Destination dest);

            private:
            std::string _name;
        };
    }
}

#endif /* !ADMIRAL_H */
