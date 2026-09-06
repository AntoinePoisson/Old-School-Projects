/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System PlayerAlive
*/

#ifndef SERVERSYSTEMSYSTEMPLAYERALIVEERVER_HPP_
#define SERVERSYSTEMSYSTEMPLAYERALIVEERVER_HPP_

#include "systems/ASystem.hpp"
#include "Server.hpp"
#include <vector>

namespace rtype {
    namespace system {

        class PlayerAlive : public ASystem {
            public:
                PlayerAlive() = default;
                virtual ~PlayerAlive() = default;
                void update(const Entity &id) {};
                void run(const Entity &id, std::vector<boost::shared_ptr<rtype::OOP::Client>> &squad);
        };

    }
}

#endif /* !SERVERSYSTEMSYSTEMPLAYERALIVEERVER_HPP_ */
