/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System ChangeMe
*/

#ifndef CLIENTSYSTEMCHANGEME_HPP_
#define CLIENTSYSTEMCHANGEME_HPP_

#include "systems/ASystem.hpp"

namespace rtype {
    namespace system {

        class ChangeMe : public ASystem
        {
            private:
            protected:
            public:
                ChangeMe() = default;
                virtual ~ChangeMe() = default;
                void update(const Entity &id);
        };

    }
}

#endif /* !CLIENTSYSTEMCHANGEME_HPP_ */
