/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include "Indie.hpp"

namespace indie
{
    enum ObjectType {
        NONE = 0,
        WALL = 1,
        FLOOR = 2,
        BOX = 3,
        WALLINSIDE = 4,
        PLAYER = 5,
        AI = 6,
        BOMBE = 7,
        POWER_SPEED = 8,
        POWER_MOREBOMB = 9,
        POWER_PASSBOX = 10,
        POWER_UPRANGEBOMB = 11,
        // à rajouter
    };

    class IObject {
        public:
            virtual ~IObject() = default;
            virtual IAnimatedMeshSceneNode* setTexture(const std::string &path) = 0;
            virtual IAnimatedMesh* setObject(const std::string &path) = 0;
            virtual irr::core::vector3df setPosition(const int &x, const int &y, const int &z) = 0;
            virtual bool getState() const = 0;
            virtual int getX() const = 0;
            virtual int getY() const = 0;
            virtual int getZ() const = 0;
            virtual int getSize() const = 0;
            virtual void setState(const bool &state) = 0;
            virtual ObjectType getType() const = 0;
            virtual IAnimatedMeshSceneNode *getNode() const = 0;
    };
}
#endif /* !IOBJECT_HPP_ */
