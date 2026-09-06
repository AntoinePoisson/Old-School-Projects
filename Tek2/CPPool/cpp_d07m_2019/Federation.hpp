/*
** EPITECH PROJECT, 2020
** Federation
** File description:
** Federation
*/

#ifndef FEDERATION_H
#define FEDERATION_H

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"


// namespace Borg;
// class Borg::Ship;

namespace Borg {
    class Ship;
}

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);

            private:
                std::string _name;
                int _age;
        };

        class Ship {
            public:
                Ship(int lenght = 289, int width = 132, std::string = "Entreprise", short maxWarp = 6, int torpedo = 0);
                ~Ship();
                void setupCore(WarpSystem::Core *);
                void checkCore(void);
                void promote(Federation::Starfleet::Captain *);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);

            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Federation::Starfleet::Captain *_captain;
                Destination _location = EARTH;
                Destination _home = EARTH;
                int _shield = 100;
                int _photonTorpedo;
        };

        class Ensign {
            public:
                explicit Ensign(std::string);
                ~Ensign();

            private:
                std::string _name;
        };
    }

    class Ship {
        public:
            Ship(int, int, std::string);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore(void);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore(void);
            // int getShield();
            // void setShield(int shield);
            // int getTorpedo();
            // void setTorpedo(int torpedo);
            // void fire(Borg::Ship *target);
            // void fire(int torpedoes, Borg::Ship *target);

        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location = VULCAN;
            Destination _home = VULCAN;
            // int _shield = 100;
            // int _photonTorpedo;
    };
};

#endif /* !FEDERATION_H */
