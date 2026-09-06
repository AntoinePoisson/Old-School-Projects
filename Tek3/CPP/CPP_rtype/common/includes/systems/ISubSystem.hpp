/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** ISubSystem
*/

#ifndef COMMONISUBSYSTEM_HPP_
#define COMMONISUBSYSTEM_HPP_

#include <string>
#include "RType.hpp"

using Entity = std::string;

namespace rtype {
    namespace system {

        class ISubSystem
        {
            public:
                virtual ~ISubSystem() = default;
                virtual void update(const Entity &ents) = 0;
        };
    }
}
#endif /* !COMMONISUBSYSTEM_HPP_ */
