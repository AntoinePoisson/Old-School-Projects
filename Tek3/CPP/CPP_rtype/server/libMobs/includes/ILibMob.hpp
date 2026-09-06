/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** LibMob
*/

#ifndef SERVERMOBLIBMOBILIBMOB_HPP_
#define SERVERMOBLIBMOBILIBMOB_HPP_

#include <string>
#include "singleton/ECManager.hpp"

using Entity = std::string;

namespace rtype {
    namespace system {

        class ILibMob
        {
            public:
                virtual ~ILibMob() = default;
                virtual const Entity createEntity(rtype::entity::ComponentManager &handler, int x, int y, int life, int stage) = 0;
                virtual void handlerIAMob(rtype::entity::ComponentManager &handler, const Entity &id) = 0;
        };

    };
};

typedef rtype::system::ILibMob *(*createMethodeMob)(void);

#endif /* !SERVERMOBLIBMOBILIBMOB_HPP_ */
