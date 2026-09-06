/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Indie.hpp"
#include "Wall.hpp"
#include "PlayerModel.hpp"
#include "Box.hpp"
#include "Floor.hpp"
#include "WallInside.hpp"

static const float SMALL_BORDER = 0.30f;
static const float HIGH_BORDER = 0.70f;

# define MULTIPLICATOR 10

namespace indie {

    namespace map {
        typedef enum mapElement_e {
            Void,
            Nothing,
            Border,
            Wall,
            Box,
            Bomb,
        } mapElement_t;
    }

    class Map {
        public:
            Map(unsigned int seed, unsigned int width = 0, unsigned int height = 0);
            Map() = default;
            virtual ~Map() = default;

            void print(void);
            std::vector<std::vector<indie::map::mapElement_t>> &getMap(void);
            int checkCanMove(int x, int y, direction_t direction, float speed, bool thoughtBox);

            int getHeightMap(void) const;
            int getWidthMap(void) const;
            std::vector<indie::Box> getBox(void) const;
            std::vector<indie::Box> &getBox(void);
            void setBox(std::vector<indie::Box> &box);

            unsigned int getSeed() const;
            int getIndexPositionX(int x) const;
            int getIndexPositionY(int y) const;
            int checkPowerUp(int x, int y, bool offPower = false);
        private:
            unsigned int seed;
            unsigned int width;
            unsigned int height;
            int widthObj;
            int heightObj;
            std::vector<indie::Wall> mapBorder; // Wall
            std::vector<indie::WallInside> mapInsideWall; // WallInside
            std::vector<indie::Floor> mapFloor; // Floor
            std::vector<indie::Box> mapBox; // Box
            std::vector<std::vector<indie::map::mapElement_t>> mapBlock;
            // bool mapBlock;
        private:
            void generate_map(void);
    };

}

#endif /* !MAP_HPP_ */
