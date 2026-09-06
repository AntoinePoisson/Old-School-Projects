/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
#define AOBJECT_HPP_

#include "IObject.hpp"
#include "Clock.hpp"

namespace indie
{
    class AObject : public indie::IObject {
        public:
            // AObject() = default;
            virtual ~AObject() = default;
            virtual IAnimatedMeshSceneNode* setTexture(const std::string &path) final;
            virtual IAnimatedMesh* setObject(const std::string &path) final;
            virtual irr::core::vector3df setPosition(const int &x, const int &y, const int &z) final;
            virtual bool getState() const final;
            virtual int getX() const final;
            virtual int getY() const final;
            virtual int getZ() const final;
            virtual int getSize() const final;
            virtual void setState(const bool &state) final;
            virtual ObjectType getType() const = 0;
            virtual IAnimatedMeshSceneNode *getNode() const final;
        protected:
            IAnimatedMeshSceneNode* _texture = nullptr;
            IAnimatedMesh* _obj = nullptr;
            irr::core::vector3df _pos = {0, 0, 0};
            int _x = 0;
            int _y = 0;
            int _z = 0;
            int _size = 0;
            bool _state = true;
    };

    class IPlayer {
        public:
            virtual ~IPlayer() = default;
            virtual void setBinding(const int &left = 0, const int &up = 0, const int &right = 0, const int &down = 0, const int &bomb = 0) = 0;
            virtual void setSingleBinding(const int &orientation, const int &input) = 0;
            virtual std::vector<int> getBinding() = 0;
            virtual int getBinding(const int &orientation) = 0;
            virtual int8_t getColor(void) const = 0;
            virtual int getNbBomb(void) const = 0;
            virtual void setNbBomb(const int &nb) = 0;
            virtual void setSpeedPlayer(float i) = 0;
            virtual void setThoughtBox(bool i) = 0;
            virtual void setRangeBomb(int i) = 0;
            virtual indie::direction_t checkCanMove(const int &input) const = 0;
            virtual void move(indie::direction_t direction) = 0;
            virtual void killed(void) = 0;
            virtual irr::core::vector3di getCenter() = 0;
    };

    class APlayer : public indie::AObject, public indie::IPlayer {
        public:
            virtual ~APlayer() = default;
            virtual void setBinding(const int &left = 0, const int &up = 0, const int &right = 0, const int &down = 0, const int &bomb = 0) = 0;
            virtual void setSingleBinding(const int &orientation, const int &input) final;
            virtual std::vector<int> getBinding() final;
            virtual int8_t getColor(void) const final;
            virtual int getNbBomb(void) const final;
            virtual void setNbBomb(const int &nb) final;
            virtual int getBinding(const int &orientation) final;
            virtual indie::direction_t checkCanMove(const int &input) const = 0;
            virtual void move(indie::direction_t direction) final;
            virtual void killed(void) final;
            virtual void powerUp(indie::ObjectType action) final;
            virtual float getSpeedPlayer(void) const final;
            virtual bool getThoughtBox(void) const final;
            virtual int getRangeBomb(void) const final;
            virtual void setSpeedPlayer(float i) final;
            virtual void regeneBomb(void) final;
            virtual void setThoughtBox(bool i) final;
            virtual void setRangeBomb(int i) final;
            virtual irr::core::vector3di getCenter() final;
            virtual ObjectType getType() const = 0;
            virtual Clock getTimeSurvive() final;
            indie::Clock clockAnimation;
        protected:
            int8_t _color = 0;
            int _left = -1;
            int _up = -1;
            int _right = -1;
            int _down = -1;
            int _bomb = -1;
            int _nbr_bomb = 0;
            int _limit_bomb = DEFAULT_MAX_BOMB;
            float _speed_player = DEFAULT_SPEED_PLAYER;
            bool _thoughtBox = false;
            int _rangeBomb = 1;
            indie::Clock _time_survive;
            indie::Clock _regeneBomb;
    };
}

#endif /* !AOBJECT_HPP_ */
