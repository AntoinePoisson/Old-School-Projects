/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AObject
*/

#include "AObject.hpp"

IAnimatedMeshSceneNode *indie::AObject::getNode() const
{
    return (_texture);
}

IAnimatedMeshSceneNode* indie::AObject::setTexture(const std::string &path)
{
    IAnimatedMeshSceneNode* node = indie::irrlicht->smgr->addAnimatedMeshSceneNode(_obj);

    if (node) {
        node->setMaterialFlag(EMF_LIGHTING, true);
        node->setMD2Animation(scene::EMAT_STAND);
        irr::video::ITexture *textureTmp = indie::irrlicht->driver->getTexture(path.c_str());
        if (!textureTmp)
            throw (indie::error::Image(path.c_str()));
        node->setMaterialTexture(0, textureTmp);
        node->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, true);
        _texture = node;
    } else {
        throw (indie::error::Mesh(path));
    }
    return node;
}

IAnimatedMesh* indie::AObject::setObject(const std::string &path)
{
    IAnimatedMesh* mesh = indie::irrlicht->smgr->getMesh(path.c_str());

    if (!mesh) {
        indie::irrlicht->device->drop();
        throw (indie::error::Mesh(path));
        return nullptr;
    }
    _obj = mesh;
    return mesh;
}

int indie::AObject::getSize() const
{
    return _size;
}

irr::core::vector3df indie::AObject::setPosition(const int &x, const int &y, const int &z)
{
    float xx = static_cast<float>(x) / 10;
    float yy = static_cast<float>(y) / 10;
    float zz = static_cast<float>(z) / 10;

    _x = x;
    _y = y;
    _z = z;
    _pos = {xx, yy, zz};
    _texture->setPosition(_pos);
    return _pos;
}

void indie::AObject::setState(const bool &state)
{
    _state = state;
}

bool indie::AObject::getState() const
{
    return _state;
}

int indie::AObject::getX() const
{
    return _x;
}

int indie::AObject::getY() const
{
    return _y;
}

int indie::AObject::getZ() const
{
    return _z;
}

void indie::APlayer::setSingleBinding(const int &orientation, const int &input)
{
    if (orientation == 0)
        _left = input;
    else if (orientation == 1)
        _up = input;
    else if (orientation == 2)
        _right = input;
    else if (orientation == 3)
        _down = input;
    else
        _bomb = input;
}

std::vector<int> indie::APlayer::getBinding()
{
    std::vector<int> tmp = {_left, _up, _right, _down, _bomb};

    return (tmp);
}

int8_t indie::APlayer::getColor(void) const
{
    return _color;
}
int indie::APlayer::getNbBomb(void) const
{
    return _nbr_bomb;
}

void indie::APlayer::setNbBomb(const int &nb)
{
    _nbr_bomb = nb;
}

int indie::APlayer::getBinding(const int &orientation)
{
    if (orientation == 0)
        return (_left);
    else if (orientation == 1)
        return (_up);
    else if (orientation == 2)
        return (_right);
    else if (orientation == 3)
        return (_down);
    else
        return (_bomb);
}

void indie::APlayer::move(indie::direction_t direction)
{
    if (direction == indie::None) {
        return ;
    }
    if (direction == indie::Bomber && _nbr_bomb > 0) {
        _nbr_bomb -= 1;
        return ;
    }
    this->clockAnimation.restart();
    if (direction == indie::Left) {
        this->_texture->setRotation(irr::core::vector3df(0, 90, 0));
        this->setPosition(std::round(this->getX() - _speed_player), this->getY(), this->getZ());
    } else if (direction == indie::Right) {
        this->_texture->setRotation(irr::core::vector3df(0, 270, 0));
        this->setPosition(std::round(this->getX() + _speed_player), this->getY(), this->getZ());
    } else if (direction == indie::Up) {
        this->_texture->setRotation(irr::core::vector3df(0, 180, 0));
        this->setPosition(this->getX(), this->getY(), std::round(this->getZ() + _speed_player));
    } else if (direction == indie::Down) {
        this->_texture->setRotation(irr::core::vector3df(0, 0, 0));
        this->setPosition(this->getX(), this->getY(), std::round(this->getZ() - _speed_player));
    }
}

void indie::APlayer::killed()
{
    if (getState() == true)
        getNode()->remove();
    setState(false);
    return;
}

void indie::APlayer::regeneBomb(void)
{
    if (_nbr_bomb >= 10)
        _regeneBomb.restart();
    if (_regeneBomb.getElapsedTime() / 12000 != 0) {
        if (_nbr_bomb < 10)
            _nbr_bomb += 1;
        _regeneBomb.restart();
    }
}

void indie::APlayer::powerUp(indie::ObjectType action)
{
    switch (action) {
        case POWER_SPEED:
            _speed_player += 0.35f;
            return;
        case POWER_PASSBOX:
            _thoughtBox = true;
            return;
        case POWER_MOREBOMB:
            _nbr_bomb = DEFAULT_MAX_BOMB;
            return;
        case POWER_UPRANGEBOMB:
            _rangeBomb += 1;
            return;
        default: return;
    }
}

int indie::APlayer::getRangeBomb(void) const
{
    return (_rangeBomb);
}

float indie::APlayer::getSpeedPlayer(void) const
{
    return (_speed_player);
}

bool indie::APlayer::getThoughtBox(void) const
{
    return (_thoughtBox);
}

void indie::APlayer::setSpeedPlayer(float i)
{
    _speed_player = i;
}

void indie::APlayer::setThoughtBox(bool i)
{
    _thoughtBox = i;
}

void indie::APlayer::setRangeBomb(int i)
{
    _rangeBomb = i;
}

irr::core::vector3di indie::APlayer::getCenter()
{
    int size = (_size * 10) / 2;
    vector3di vec(_x - size, _y - size, _z - size);

    return vec;
}

indie::Clock indie::APlayer::getTimeSurvive()
{
    return _time_survive;
}