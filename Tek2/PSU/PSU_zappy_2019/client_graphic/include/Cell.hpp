/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Cell
*/

#ifndef CELL_H_
#define CELL_H_


#include "shared.h"
#include <iostream>
#include <vector>

enum Element {
    NOTHING = -1,
    PLAYER_UP = -2,
    PLAYER_DOWN = -3,
    PLAYER_LEFT = -4,
    PLAYER_RIGHT = -5,
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    EGG
};
#include <vector>

class Cell {
    public:
    std::vector<std::pair<Element, unsigned int>> _arr;
    Cell();
    void operator=(const struct cell_s &cell);
    // Cell(const cell_t &cell);

    Cell(const Cell &cpy);
};

#endif