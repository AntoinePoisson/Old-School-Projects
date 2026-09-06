/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System MobServer
*/

#ifndef SERVERSYSTEMMOBSERVER_HPP_
#define SERVERSYSTEMMOBSERVER_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class MobServer : public ASystem {
            private:
                void creationMob(const Entity &id, int stage);
            public:
                MobServer() = default;
                virtual ~MobServer() = default;
                void update(const Entity &id) {};
                void run(const Entity &id, int *prevNbr, int *stage);
        };

    }
}

#endif /* !SERVERSYSTEMMOBSERVER_HPP_ */
