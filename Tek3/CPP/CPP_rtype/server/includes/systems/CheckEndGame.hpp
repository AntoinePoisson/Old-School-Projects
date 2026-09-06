/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System systemCheckEndGame
*/

#ifndef SERVERSYSTEMSYSTEMENDGAMESERVER_HPP_
#define SERVERSYSTEMSYSTEMENDGAMESERVER_HPP_

#include "systems/ASystem.hpp"
#include "Server.hpp"

namespace rtype {
    namespace system {

        class CheckEndGame : public ASystem {
            public:
                CheckEndGame() = default;
                virtual ~CheckEndGame() = default;
                void update(const Entity &id) {};
                void run(const Entity &id, std::vector<boost::shared_ptr<rtype::OOP::Client>> &);
        };

    }
}

#endif /* !SERVERSYSTEMSYSTEMENDGAMESERVER_HPP_ */
