/*
** EPITECH PROJECT, 2019
** dante
** File description:
** perfect to imperfect maze
*/

#include <stdio.h>
#include <unistd.h>
#include "my_struct.h"
#include "my_put.h"
#include "my_lib.h"

void separe_wall(variable_t *var)
{
    static int i = 1;
    static int j = 1;

    for (; i < var->size_y - 1; i++)
        for (; j < var->size_x - 1; j++)
            if (var->map[i][j] == 'X' && ((var->map[i][j - 1] == 'X'
                && var->map[i][j + 1] == 'X' && var->map[i - 1][j] == '*'
                && var->map[i + 1][j] == '*') || (var->map[i - 1][j] == 'X'
                && var->map[i + 1][j] == 'X' && var->map[i][j + 1] == '*'
                && var->map[i][j - 1] == '*'))) {
                var->map[i][j] = '*';
                i++;
                return;
            }
}

void imperfect_maze(variable_t *var)
{
    int size = var->size_y * var->size_x;

    for (; size > 0; size = size / 2)
        separe_wall(var);
}
