/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System Shooting
*/

#ifndef COMMONSYSTEMSHOOTING_HPP_
#define COMMONSYSTEMSHOOTING_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class Shooting : public ASystem
        {
            private:
            protected:
            public:
                Shooting() = default;
                virtual ~Shooting() = default;
            // create bullet, get weapon's attribute
            // add to EntityComponentManager
        };

    }
}

#endif /* !COMMONSYSTEMSHOOTING_HPP_ */
