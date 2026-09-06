/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** LibMob
*/

#ifndef LIBMOBPLANEMOB_HPP_
#define LIBMOBPLANEMOB_HPP_

#include <string>
#include "singleton/ECManager.hpp"
#include "Network.hpp"
#include "./ILibMob.hpp"

using Entity = std::string;

namespace rtype {
    namespace system {

        class PlaneMob : public ILibMob
        {
            private:
                rtype::component::componentType lvl;
            public:
                PlaneMob() = default;
                ~PlaneMob() = default;
                const Entity createEntity(rtype::entity::ComponentManager &handler, int x, int y, int life, int stage);
                void handlerIAMob(rtype::entity::ComponentManager &handler, const Entity &id);
        };

    };
};

#endif /* !LIBMOBPLANEMOB_HPP_ */
