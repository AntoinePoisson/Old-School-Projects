/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System Collision
*/

#ifndef COMMONSYSTEMCOLLISION_HPP_
#define COMMONSYSTEMCOLLISION_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class Collision : public ASystem
        {
            private:
            protected:
            public:
                Collision() = default;
                virtual ~Collision() = default;
            // if no collision udpate position to nextPosition
            // set CollisionComponent in entity if there is collision between them
        };

    }
}

#endif /* !COMMONSYSTEMCOLLISION_HPP_ */
