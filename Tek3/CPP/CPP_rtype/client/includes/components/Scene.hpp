/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component ChangeMe
*/

#ifndef SCENECOMPONENT_HPP_
#define SCENECOMPONENT_HPP_

#include "components/AComponent.hpp"
#include "scene/EnumScene.hpp"

namespace rtype {
    namespace component {

        struct Scene : public AComponent
        {
            Scene(const rtype::client::scenes &scene = rtype::client::scenes::MENU)
                : AComponent(), _scene(scene) {};

            enum rtype::client::scenes _scene;
        };
    }
}

#endif /* !SCENECOMPONENT_HPP_ */
