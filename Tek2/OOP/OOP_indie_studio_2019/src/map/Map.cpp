/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"

    // Public
indie::Map::Map(unsigned int seed, unsigned int width, unsigned int height)
: seed(seed), width(width), height(height)
{
    srand(seed);
    std::srand(seed);

    if (width == 0 && height == 0) {
        width = (rand() % 6) + 12;
        height = (rand() % 4) + 9;
        this->width = width;
        this->height = height;
    }
    if (width <= 4 || height <= 4)
        throw indie::error::Error("Map", "Too small size map.");
    if (width % 2 == 0) {
        this->width += 1;
        width += 1;
    }
    if (height % 2 == 0) {
        this->height += 1;
        height += 1;
    }
    std::vector<indie::map::mapElement_t> tmp;
    for (int i = 0; i < height; i++) {
        tmp.clear();
        for (int s = 0; s < width; s++) {
            tmp.push_back(indie::map::Nothing);
        }
        mapBlock.push_back(tmp);
    }
    widthObj = 3 * MULTIPLICATOR;
    heightObj = 3 * MULTIPLICATOR;
    indie::irrlicht->smgr->addCameraSceneNode(0, vector3df(static_cast<int>(std::round(1.45f * width)),35,3), vector3df(static_cast<int>(std::round(1.45f * width)),0,12));
    // indie::irrlicht->smgr->addCameraSceneNode(0, vector3df(18,35,3), vector3df(18,0,12));
//    indie::irrlicht->smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
    generate_map();
}

void indie::Map::print(void)
{
    if (mapBorder.size() == 0)
        return;
	indie::irrlicht->smgr->drawAll();
}

std::vector<std::vector<indie::map::mapElement_t>> &indie::Map::getMap(void)
{
    return (mapBlock);
}

int indie::Map::checkCanMove(int x, int y, direction_t direction, float speed, bool thoughtBox)
{
    int posX = (x / widthObj) + 1;
    int posY = (y / widthObj) + 1;

    while (x >= widthObj) {
        x -= widthObj;
    }
    while (y >= heightObj) {
        y -= heightObj;
    }
    if (posY > height || posX > width)
        return (0);
    if (direction == Up) {
        if (((x > heightObj * SMALL_BORDER) && (x < heightObj * HIGH_BORDER))) {
            if ((mapBlock[posY + 1][posX] == indie::map::Nothing))
                return (1);
            else if ((thoughtBox && mapBlock[posY + 1][posX] == indie::map::Box && checkPowerUp(posX, posY + 1, false) == 0))
                return (1);
            else if (mapBlock[posY + 1][posX] == indie::map::Box && checkPowerUp(posX, posY + 1, false))
                return (checkPowerUp(posX, posY + 1, true));
            else if ((std::round(y + speed) < heightObj * HIGH_BORDER))
                return (1);
        }
        return (0);
    }

    if (direction == Down) {
        if (((x > heightObj * SMALL_BORDER) && (x < heightObj * HIGH_BORDER))) {
            if ((mapBlock[posY - 1][posX] == indie::map::Nothing))
                return (1);
            else if ((thoughtBox && mapBlock[posY - 1][posX] == indie::map::Box && checkPowerUp(posX, posY - 1, false) == 0))
                return (1);
            else if (mapBlock[posY - 1][posX] == indie::map::Box && checkPowerUp(posX, posY - 1, false))
                return (checkPowerUp(posX, posY - 1, true));
            else if ((std::round(y - speed) > heightObj * SMALL_BORDER))
                return (1);
        }
        return (0);
    }

    if (direction == Right) {
        if (((y > widthObj * SMALL_BORDER) && (y < widthObj * HIGH_BORDER))) {
            if ((mapBlock[posY][posX + 1] == indie::map::Nothing))
                return (1);
            else if ((thoughtBox && mapBlock[posY][posX + 1] == indie::map::Box && checkPowerUp(posX + 1, posY, false) == 0))
                return (1);
            else if (mapBlock[posY][posX + 1] == indie::map::Box && checkPowerUp(posX + 1, posY, false))
                return (checkPowerUp(posX + 1, posY, true));
            else if ((std::round(x + speed) < widthObj * HIGH_BORDER))
                return (1);
        }
        return (0);
    }

    if (direction == Left) {
        if (((y > widthObj * SMALL_BORDER) && (y < widthObj * HIGH_BORDER))) {
            if ((mapBlock[posY][posX - 1] == indie::map::Nothing))
                return (1);
            else if ((thoughtBox && mapBlock[posY][posX - 1] == indie::map::Box && checkPowerUp(posX - 1, posY, false) == 0))
                return (1);
            else if (mapBlock[posY][posX - 1] == indie::map::Box && checkPowerUp(posX - 1, posY, false))
                return (checkPowerUp(posX - 1, posY, true));
            else if ((std::round(x - speed) > widthObj * SMALL_BORDER))
                return (1);
        }
        return (0);
    }

    return (0);
}

int indie::Map::getHeightMap(void) const
{
    return (height);
}

int indie::Map::getWidthMap(void) const
{
    return (width);
}

int indie::Map::getIndexPositionX(int x) const
{
    x = abs(x);
    return ((x / widthObj) + 1);
}

int indie::Map::getIndexPositionY(int y) const
{
    y = abs(y);
    return ((y / widthObj) + 1);
}

std::vector<indie::Box> indie::Map::getBox(void) const
{
    return (mapBox);
}

std::vector<indie::Box> &indie::Map::getBox(void)
{
    return (mapBox);
}

void indie::Map::setBox(std::vector<indie::Box> &box)
{
    mapBox = box;
}

unsigned int indie::Map::getSeed() const
{
    return this->seed;
}

    // Private
void indie::Map::generate_map(void)
{
    mapBorder.clear();
    mapFloor.clear();
    mapInsideWall.clear();
    mapBox.clear();
    for (int z = 0; z < height; z++) {
        if (!z || z + 1 == height) {
            for (int x = 0; x < width; x++) {
                indie::Wall wall(x * widthObj, 0, z * heightObj);
                widthObj = wall.getSize() * MULTIPLICATOR;
                heightObj = wall.getSize() * MULTIPLICATOR;
                mapBorder.push_back(wall);
                mapBlock[z][x] = indie::map::mapElement_t::Border;
            }
        } else {
            indie::Wall wall(0, 0, z * heightObj);
            mapBorder.push_back(wall);
            indie::Wall wall2((width - 1) * widthObj, 0, z * heightObj);
            mapBorder.push_back(wall2);
            mapBlock[z][0] = indie::map::mapElement_t::Border;
            mapBlock[z][(width - 1)] = indie::map::mapElement_t::Border;
        }
    }
    for (int z = 0; z < height; z++)
        for (int x = 0; x < width; x++) {
            indie::Floor floor(x * widthObj, -heightObj, z * heightObj);
            mapFloor.push_back(floor);
        }
    for (int z = 1; z + 1 < height; z++) {
        if (z % 2 == 0)
            for (int x = 1; x + 1 < width; x++) {
                if (x % 2 == 0) {
                    indie::WallInside wall4(x * widthObj, 0, z * heightObj);
                    mapInsideWall.push_back(wall4);
                    mapBlock[z][x] = indie::map::mapElement_t::Wall;
                }
            }
    }
    for (int nbr = ((height - 1) * (width - 1) / 4); nbr >= 0; nbr--) {
        for (int coun = 0; coun < 5; coun++) {
            int z = ((rand() % (height - 2)) + 1);
            int x = ((rand() % (width - 2)) + 1);
            if (z < height && x < width &&
                mapBlock[z][x] == indie::map::mapElement_t::Nothing) {
                if ((z == 1 && x == 1) || (z == 1 && x == width - 2) ||
                    (z == height - 2 && x == width - 2) || (z == height - 2 && x == 1))
                    continue;
                if ((z == 2 && x == 1) || (z == 1 && x == 2) || (z == 2 && x == width - 2) || (z == 1 && x == width - 3) ||
                    (z == height - 2 && x == width - 3) || (z == height - 3 && x == width - 2) || (z == height - 3 && x == 1) || (z == height - 2 && x == 2))
                    continue;
                indie::Box boxe(x * widthObj, 0, z * heightObj);
                mapBox.push_back(boxe);
                mapBlock[z][x] = indie::map::mapElement_t::Box;
                break;
            }
        }
    }
}

int indie::Map::checkPowerUp(int x, int y, bool offPower)
{
    int index = 0;

    if (y > height || x > width)
        return (0);
    if (mapBlock[y][x] != indie::map::Box)
        return (1);
    for (auto tmp : mapBox) {
        if (y == (getIndexPositionY(tmp.getZ()) - 1) && x == (getIndexPositionX(tmp.getX()) - 1))
            break;
        index += 1;
    }
    if ((index >= mapBox.size()))
        return (0);
    if (y != (getIndexPositionY(mapBox[index].getZ()) - 1) || x != (getIndexPositionX(mapBox[index].getX()) - 1))
        return (0);
    if (mapBox[index].getType() == indie::ObjectType::BOX)
        return (0);
    if (mapBox[index].getType() == indie::ObjectType::NONE)
        return (1);
    if (offPower) {
        indie::ObjectType save = mapBox[index].getType();
        mapBox[index].OffPower();
        return (save);
    } else {
        return (2);
    }
}