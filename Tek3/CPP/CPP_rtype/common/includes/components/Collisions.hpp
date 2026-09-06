/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Collision
*/

#ifndef COMMONCOMPONENTCOLLISION_HPP_
#define COMMONCOMPONENTCOLLISION_HPP_

#include <vector>
#include <string>
#include "components/AComponent.hpp"

namespace rtype {
    namespace component {

        //use for movement system and damage system

        struct Collision : public AComponent
        {
            Collision() : AComponent() {};
            Collision(std::vector<std::string> entities) : AComponent(), _entitiesId(entities) {};

            std::vector<std::string> _entitiesId;
        };

        struct Collided : public AComponent
        {
            Collided(bool collided) : AComponent(), _hasCollided(collided) {};

            bool _hasCollided;
        };

    }
}

#endif /* !COMMONCOMPONENTCOLLISION_HPP_ */
