/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** System ChangeMe
*/

#ifndef COMMONSYSTEMCHANGEME_HPP_
#define COMMONSYSTEMCHANGEME_HPP_

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

#endif /* !COMMONSYSTEMCHANGEME_HPP_ */
