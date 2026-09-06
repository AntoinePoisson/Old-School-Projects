/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** ShootServer
*/

#ifndef SHOOTSERVER_HPP_
#define SHOOTSERVER_HPP_

#include "systems/ASystem.hpp"
#include "Network.hpp"

namespace rtype {
    namespace system {

        class ShootBullet : public ASystem {
            public:
                ShootBullet() = default;
                virtual ~ShootBullet() = default;
                void update(const Entity &id);
        };

        class CheckBullet : public ASystem {
            public:
                CheckBullet() = default;
                virtual ~CheckBullet() = default;
                void update(const Entity &id);
        };

    }
}
#endif /* !SHOOTSERVER_HPP_ */
