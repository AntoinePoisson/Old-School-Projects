/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component ChangeMe
*/

#ifndef UNREMOVABLE_CPT_HPP
#define UNREMOVABLE_CPT_HPP

#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        struct Unremovable : public AComponent
        {
            Unremovable(): AComponent() {};
            Unremovable(const std::vector<Entity> &cpy): 
            AComponent(), entities(cpy) {};

            std::vector<Entity> entities;
        };

    }
}

#endif /* !UNREMOVABLE_CPT_HPP */
