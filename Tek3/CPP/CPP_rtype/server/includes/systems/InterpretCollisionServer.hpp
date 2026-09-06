/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System InterpretCollisionServer
*/

#ifndef SERVERSYSTEMINTERPRETCHECKCOLLISION_HPP_
#define SERVERSYSTEMINTERPRETCHECKCOLLISION_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class InterpretCollisionServer : public ASystem {
            public:
                InterpretCollisionServer() = default;
                virtual ~InterpretCollisionServer() = default;
                void update(const Entity &id);
        };

    }
}

#endif /* !SERVERSYSTEMINTERPRETCHECKCOLLISION_HPP_ */
