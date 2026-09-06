/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-aurele.auboin
** File description:
** Component Type
*/

#ifndef COMMONCOMPONENTTYPE_HPP_
#define COMMONCOMPONENTTYPE_HPP_

#include "components/Exception.hpp"
#include "components/AComponent.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace rtype {
    namespace component {

        enum componentType {
            BACKGROUND,
            TILE,
            DESTROYABLETILE,
            PLAYERRED,
            PLAYERBLUE,
            PLAYERBLUELIGHT,
            PLAYERGREEN,
            PLAYERPURPLE,
            MONSTER1,
            MONSTER2,
            MONSTER3,
            MONSTER4,
            BULLET1,
            BULLET2,
            BULLET3,
            BULLET4,
            BULLET5,
            POWERUPMONSTER,//same question // exist ou c'est le nombre de monstre tué qui te donne ton powerup?
            WEAPON,//same question
            DEFEAT,
            VICTORY,
        };

        struct Type : public AComponent
        {
            Type(componentType type) : AComponent(), _type(type) {};
            Type(const struct Type &t) {
                _type = t._type;
            }
            componentType _type;
        };


        //client side
        enum buttonAction {
            PLAY1 = 1,
            PLAY2,
            PLAY3,
            PLAY4,
            QUITGAME,
            QUITPRGM,
            VOLPLUS,
            VOLMINUS,
        };

        struct ButtonAction : public AComponent
        {
            ButtonAction(buttonAction action) : AComponent(), _action(action) {};

            buttonAction _action;
        };

    }
}

#endif /* !COMMONCOMPONENTTYPE_HPP_ */
