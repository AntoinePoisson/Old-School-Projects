/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System ISystem
*/

#ifndef COMMONSYSTEMISYSTEM_HPP_
#define COMMONSYSTEMISYSTEM_HPP_

#include <string>
#include "RType.hpp"

using Entity = std::string;

namespace rtype {
    namespace system {

        class ISystem
        {
            public:
                virtual ~ISystem() = default;

                virtual void update(const Entity &e) = 0;
        };

    }
}

#endif /* !COMMONSYSTEMISYSTEM_HPP_ */
