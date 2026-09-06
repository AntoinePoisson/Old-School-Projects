/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** OtherMob
*/

#ifndef LIBMOBOTHERMOB_HPP_
#define LIBMOBOTHERMOB_HPP_

#include <string>
#include "singleton/ECManager.hpp"
#include "./ILibMob.hpp"

using Entity = std::string;

namespace rtype {
    namespace system {

        class OtherMob : public ILibMob
        {
            public:
                OtherMob() = default;
                ~OtherMob() = default;
                const Entity createEntity(rtype::entity::ComponentManager &handler, int x, int y, int life, int stage);
                void handlerIAMob(rtype::entity::ComponentManager &handler, const Entity &id);
        };

    };
};

#endif /* !LIBMOBOTHERMOB_HPP_ */
