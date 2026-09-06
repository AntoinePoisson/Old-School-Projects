/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component MethodeMob
*/

#ifndef SERVERCOMPONENTMETHODEMOB_HPP_
#define SERVERCOMPONENTMETHODEMOB_HPP_

#include <vector>
#include <utility>
#include <memory>
#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        struct ListMethodeMob : public AComponent
        {
            ListMethodeMob() = default;
            ~ListMethodeMob() = default;

            std::vector<void *> _list;
        };

        struct NbrMob : public AComponent
        {
            NbrMob(): _count(0) {};
            ~NbrMob() = default;

            int _count;
        };

    }
}

#endif /* !SERVERCOMPONENTMETHODEMOB_HPP_ */
