/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "Clock.hpp"

indie::Bomb::Bomb(const int &x, const int &y, const int &z, int range)
: _x(x), _y(y)
{
    setObject("./ressources/assets/bomb2/Bomb.obj");
    setTexture("./ressources/assets/bomb2/Albedo.png");
    setPosition(x, y, z);
    _texture->setScale(irr::core::vector3df(10, 10, 10));
    _size = std::round(std::cbrt(_obj->getBoundingBox().getVolume()));
    _animation = false;
    _rangeBomb = range ? abs(range) : 1;
}

irr::core::vector3di indie::Bomb::getCenter()
{
    int size = (_size * 10) / 2;
    vector3di vec(_x - size, _y - size, _z - size);

    return vec;
}

bool indie::Bomb::isExplosion(std::vector<std::vector<indie::map::mapElement_t>> &map, int indexX, int indexY, std::vector<indie::APlayer*> getPlayer, std::vector<indie::Box> &mapBox)
{
    if (_clock.getElapsedTime() >= 3500) {
        int i = 1;
        indexX -= 1;
        indexY -= 1;
        if (_animation == false) {
            for (size_t j = 0; j < getPlayer.size(); j++) {
                int playerX = getPlayer[j]->getCenter().X + 30;
                int playerY = getPlayer[j]->getCenter().Z + 30;
                if (playerX > indexX * 30 && playerX < indexX * 30 + 30 && playerY > (indexY) * 30 && playerY < (indexY) * 30 + 30) {
                    getPlayer[j]->killed();
                }
            }
        }
        i = 1;
        for (; i <= _rangeBomb; i++) { // UP
            if (map[indexY + i][indexX] != indie::map::Wall && map[indexY + i][indexX] != indie::map::Void && map[indexY + i][indexX] != indie::map::Border) {
                if (_animation == false) {
                    size_t k = 0;
                    for (; map[indexY + i][indexX] == indie::map::Box && k < mapBox.size(); k++) {
                        if (mapBox[k].getX() / 30 == indexX && mapBox[k].getZ() / 30 == indexY + i && mapBox[k].getType() == indie::ObjectType::BOX)
                            break;
                    }
                    if (map[indexY + i][indexX] == indie::map::Box && mapBox[k].getType() == indie::ObjectType::BOX) {
                        for (size_t j = 0; j < mapBox.size(); j++) {
                            if (mapBox[j].getX() / 30 == indexX && mapBox[j].getZ() / 30 == indexY + i && mapBox[j].getType() == indie::ObjectType::BOX) {
                                mapBox[j].ExplosionBox();
                                break;
                            }
                        }
                        break;
                    } else {
                        for (size_t j = 0; j < getPlayer.size(); j++) {
                            int playerX = getPlayer[j]->getCenter().X + 30;
                            int playerY = getPlayer[j]->getCenter().Z + 30;
                            if (playerX > indexX * 30 && playerX < indexX * 30 + 30 && playerY > (indexY + i) * 30 && playerY < (indexY + i) * 30 + 30) {
                                getPlayer[j]->killed();
                            }
                        }
                    }
                }
            } else {
                i -= 1;
                break;
            }
        }
        if (_animation == false) {
            this->_particles.push_back(new indie::Particles(indexX * 3, indexY * 3, 0, i));
        }
        i = 1;
        for (; i <= _rangeBomb; i++) { // DOWN
            if (map[indexY - i][indexX] != indie::map::Wall && map[indexY - i][indexX] != indie::map::Void && map[indexY - i][indexX] != indie::map::Border) {
                if (_animation == false) {
                    size_t k = 0;
                    for (; map[indexY - i][indexX] == indie::map::Box && k < mapBox.size(); k++) {
                        if (mapBox[k].getX() / 30 == indexX && mapBox[k].getZ() / 30 == indexY - i && mapBox[k].getType() == indie::ObjectType::BOX)
                            break;
                    }
                    if (map[indexY - i][indexX] == indie::map::Box && mapBox[k].getType() == indie::ObjectType::BOX) {
                        for (size_t j = 0; j < mapBox.size(); j++) {
                            if (mapBox[j].getX() / 30 == indexX && mapBox[j].getZ() / 30 == indexY - i && mapBox[j].getType() == indie::ObjectType::BOX) {
                                mapBox[j].ExplosionBox();
                                break;
                            }
                        }
                        break;
                    } else {
                        for (size_t j = 0; j < getPlayer.size(); j++) {
                            int playerX = getPlayer[j]->getCenter().X + 30;
                            int playerY = getPlayer[j]->getCenter().Z + 30;
                            if (playerX > indexX * 30 && playerX < indexX * 30 + 30 && playerY > (indexY - i) * 30 && playerY < (indexY - i) * 30 + 30) {
                                getPlayer[j]->killed();
                            }
                        }
                    }
                }
            } else {
                i -= 1;
                break;
            }
        }
        if (_animation == false) {
            this->_particles.push_back(new indie::Particles(indexX * 3, indexY * 3, 1, i));
        }
        i = 1;
        for (; i <= _rangeBomb; i++) { // RIGHT
            if (map[indexY][indexX + i] != indie::map::Wall && map[indexY][indexX + i] != indie::map::Void && map[indexY][indexX + i] != indie::map::Border) {
                if (_animation == false) {
                    size_t k = 0;
                    for (; map[indexY][indexX + i] == indie::map::Box && k < mapBox.size(); k++) {
                        if (mapBox[k].getX() / 30 == indexX + i && mapBox[k].getZ() / 30 == indexY && mapBox[k].getType() == indie::ObjectType::BOX)
                            break;
                    }
                    if (map[indexY][indexX + i] == indie::map::Box && mapBox[k].getType() == indie::ObjectType::BOX) {
                        for (size_t j = 0; j < mapBox.size(); j++) {
                            if (mapBox[j].getX() / 30 == indexX + i && mapBox[j].getZ() / 30 == indexY && mapBox[j].getType() == indie::ObjectType::BOX) {
                                mapBox[j].ExplosionBox();
                                break;
                            }
                        }
                        break;
                    } else {
                        for (size_t j = 0; j < getPlayer.size(); j++) {
                            int playerX = getPlayer[j]->getCenter().X + 30;
                            int playerY = getPlayer[j]->getCenter().Z + 30;
                            if (playerX > (indexX + i) * 30 && playerX < (indexX + i) * 30 + 30 && playerY > indexY * 30 && playerY < indexY * 30 + 30) {
                                getPlayer[j]->killed();
                            }
                        }
                    }
                }
            } else {
                i -= 1;
                break;
            }
        }
        if (_animation == false) {
            this->_particles.push_back(new indie::Particles(indexX * 3, indexY * 3, 2, i));
        }
        i = 1;
        for (; i <= _rangeBomb; i++) { // LEFT
            if (map[indexY][indexX - i] != indie::map::Wall && map[indexY][indexX - i] != indie::map::Void && map[indexY][indexX - i] != indie::map::Border) {
                if (_animation == false) {
                    size_t k = 0;
                    for (; map[indexY][indexX - i] == indie::map::Box && k < mapBox.size(); k++) {
                        if (mapBox[k].getX() / 30 == indexX - i && mapBox[k].getZ() / 30 == indexY && mapBox[k].getType() == indie::ObjectType::BOX)
                            break;
                    }
                    if (map[indexY][indexX - i] == indie::map::Box && mapBox[k].getType() == indie::ObjectType::BOX) {
                        for (size_t j = 0; j < mapBox.size(); j++) {
                            if (mapBox[j].getX() / 30 == indexX - i && mapBox[j].getZ() / 30 == indexY && mapBox[j].getType() == indie::ObjectType::BOX) {
                                mapBox[j].ExplosionBox();
                                break;
                            }
                        }
                        break;
                    } else {
                        for (size_t j = 0; j < getPlayer.size(); j++) {
                            int playerX = getPlayer[j]->getCenter().X + 30;
                            int playerY = getPlayer[j]->getCenter().Z + 30;
                            if (playerX > (indexX - i) * 30 && playerX < (indexX - i) * 30 + 30 && playerY > indexY * 30 && playerY < indexY * 30 + 30) {
                                getPlayer[j]->killed();
                            }
                        }
                    }
                }
            } else {
                i -= 1;
                break;
            }
        }
        if (_animation == false) {
            this->_particles.push_back(new indie::Particles(indexX * 3, indexY * 3, 3, i));
        }
        _animation = true;
        if (_clock.getElapsedTime() >= 4200) {
            for (size_t j = 0; j < this->_particles.size(); j++) {
                delete this->_particles[j];
            }
            this->_particles.clear();
            return (true);
        }
    }
    return (false);
}

indie::ObjectType indie::Bomb::getType() const
{
    return indie::ObjectType::BOMBE;
}

int indie::Bomb::getRangeBomb() const
{
    return _rangeBomb;
}