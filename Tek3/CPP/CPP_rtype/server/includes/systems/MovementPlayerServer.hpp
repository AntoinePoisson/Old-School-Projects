/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System Movement
*/

#ifndef SERVERSYSTEMMOVEMENTPLAYER_HPP_
#define SERVERSYSTEMMOVEMENTPLAYER_HPP_

#include "systems/ASystem.hpp"
#include "Network.hpp"

namespace rtype {
    namespace system {

        class MovementPlayerServer : public ASystem {
            public:
                MovementPlayerServer() = default;
                virtual ~MovementPlayerServer() = default;
                void update(const Entity &id) {};
                void action(const Entity &id, enum rtype::network::CodeAction move);
        };

    }
}

#endif /* !SERVERSYSTEMMOVEMENTPLAYER_HPP_ */
