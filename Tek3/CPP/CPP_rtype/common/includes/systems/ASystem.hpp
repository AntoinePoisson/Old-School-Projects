/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System ASystem
*/

#ifndef COMMONSYSTEMASYSTEM_HPP_
#define COMMONSYSTEMASYSTEM_HPP_

#include <string>

#include "systems/ISystem.hpp"

using Entity = std::string;

namespace rtype {
    namespace system {

        class ASystem : public ISystem
        {
            public:
                virtual ~ASystem() = default;

                virtual void update(const Entity &e) = 0;
        };

    }
}

#endif /* !COMMONSYSTEMISYSTEM_HPP_ */
