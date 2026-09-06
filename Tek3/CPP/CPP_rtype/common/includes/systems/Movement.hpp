/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System Movement
*/

#ifndef COMMONSYSTEMMOVEMENT_HPP_
#define COMMONSYSTEMMOVEMENT_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class Movement : public ASystem
        {
            private:
            protected:
            public:
                Movement() = default;
                virtual ~Movement() = default;
            // otherwise move
            // set NextPositionComponent if entity is moving
        };

    }
}

#endif /* !COMMONSYSTEMMOVEMENT_HPP_ */
