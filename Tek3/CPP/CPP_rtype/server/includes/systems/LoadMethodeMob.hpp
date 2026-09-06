/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System LoadMethode
*/

#ifndef SERVERSYSTEMLOADMETHODEEE_HPP_
#define SERVERSYSTEMLOADMETHODEEE_HPP_

#include "systems/ASystem.hpp"
#include "singleton/ECManager.hpp"

namespace rtype {
    namespace system {

        class LoadMethodeMob : public ASystem {
            public:
                LoadMethodeMob() = default;
                virtual ~LoadMethodeMob() = default;
                void update(const Entity &id);
        };

    }
}


#endif /* !SERVERSYSTEMLOADMETHODEEE_HPP_ */
