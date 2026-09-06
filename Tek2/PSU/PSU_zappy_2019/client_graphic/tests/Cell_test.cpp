/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Cell_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Map.hpp"

void redirect_all_stdout(void);

Test(Cell_test, test1)
{
    cell_t cellFromC;
    cell_player_t player = {"chouette", "corbeau", Down};

    bzero(&cellFromC, sizeof(struct cell_s));
    cellFromC.x = 1;
    cellFromC.y = 20;
    cellFromC.food = 1;
    cellFromC.phiras = 1;
    cellFromC.players[0] = player;
    Cell cellFromCpp;

    cellFromCpp = cellFromC;

    cr_expect_eq(cellFromCpp._arr[0], PLAYER_DOWN);
    cr_expect_eq(cellFromCpp._arr[1], FOOD);
    cr_expect_eq(cellFromCpp._arr[2], PHIRAS);
    cr_expect_eq(cellFromCpp._arr[3], NOTHING);
}
