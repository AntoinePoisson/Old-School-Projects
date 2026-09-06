/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System Damage
*/

#ifndef COMMONSYSTEMDAMAGE_HPP_
#define COMMONSYSTEMDAMAGE_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class Damage : public ASystem
        {
            private:
            protected:
            public:
                Damage() = default;
                virtual ~Damage() = default;
            // check CollisionComponent, and decide if health has to be decreased
        };

    }
}

#endif /* !COMMONSYSTEMDAMAGE_HPP_ */
