/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System TimerGame
*/

#ifndef SERVERSYSTEMTIMERGAME_HPP_
#define SERVERSYSTEMTIMERGAME_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class TimerGame : public ASystem {
            public:
                TimerGame() = default;
                virtual ~TimerGame() = default;
                void update(const Entity &id);
        };

    }
}

#endif /* !SERVERSYSTEMTIMERGAME_HPP_ */
