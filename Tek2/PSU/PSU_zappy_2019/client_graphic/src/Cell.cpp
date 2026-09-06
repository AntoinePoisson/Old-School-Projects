/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Cell
*/

#include "Cell.hpp"
#include <string.h>

Cell::Cell(): _arr(9, {NOTHING, 0}) {}

void Cell::operator=(const struct cell_s &cell) {
    int cnt = 0;
    for (cnt = 0; cell.players[cnt].id[0] != '\0' && cnt < 9; cnt++) {
        if (cell.players[cnt].id == NULL)
            break;
        else if (cell.players[cnt].player_team != NULL && !strncmp(cell.players[cnt].player_team, EGG_TEAM_NAME, strlen(EGG_TEAM_NAME))) {
            _arr[cnt].first = EGG;
        } else if (cell.players[cnt].look == Up) {
            _arr[cnt].first = PLAYER_UP;
        } else if (cell.players[cnt].look == Down) {
            _arr[cnt].first = PLAYER_DOWN;
        } else if (cell.players[cnt].look == Left) {
            _arr[cnt].first = PLAYER_LEFT;
        } else {
            _arr[cnt].first = PLAYER_RIGHT;
        }
    }
    const unsigned int *ptr = (unsigned int *) &cell + 2;
    for (int i = 0; cnt < 9 && i < 7; i++) {
        const unsigned int *cast = (ptr + i);
        if (cast[0]) {
            _arr[cnt].second = *(cast);
            _arr[cnt++].first = (enum Element) i;
        }
    }
}

Cell::Cell(const Cell &cpy) {
    _arr.assign(cpy._arr.begin(), cpy._arr.end());
}