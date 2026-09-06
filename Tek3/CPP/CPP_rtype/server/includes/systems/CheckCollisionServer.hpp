/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System CheckCollisionServer
*/

#ifndef SERVERSYSTEMCHECKCOLLISION_HPP_
#define SERVERSYSTEMCHECKCOLLISION_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class CheckCollisionServer : public ASystem {
            public:
                CheckCollisionServer() = default;
                virtual ~CheckCollisionServer() = default;
                void update(const Entity &id);
        };

    }
}

#endif /* !SERVERSYSTEMCHECKCOLLISION_HPP_ */
