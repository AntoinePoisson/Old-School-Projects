/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "shared.h"
#include <map>
#include <iostream>
#include "Cell.hpp"


static int sizeCell = 33;

using pos_t = std::pair<int, int> ;

class Map {
    std::map<pos_t, Cell> _cells;
    int _x;
    int _y;

    public:
        Map(int x, int y): _x(x), _y(y) {}
        void updateCell(int x, int y, cell_t cell) {
            _cells[{x, y}] = cell;
        }
        Cell getCell(int x, int y) {
            return _cells[{x, y}];
        }
};

#endif