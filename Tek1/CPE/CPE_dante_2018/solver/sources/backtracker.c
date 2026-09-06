/*
** EPITECH PROJECT, 2019
** backtracker.c
** File description:
** backtracker algo
*/

#include <time.h>
#include <stdlib.h>
#include "my_struct.h"

void pop(variable_t *var, int *x, int *y);
int push(variable_t *var, int x, int y, int cas);
int move_on_direction_(variable_t *var, int *x, int *y, int cas);

static void move_on_direction(variable_t *var, int *x, int *y, int cas)
{
    if (cas == 1) {
        var->map[*y][*x] = 'o';
        var->map[*y - 1][*x] = 'o';
        *y -= 1;
        return;
    }
    if (cas == 2) {
        var->map[*y][*x] = 'o';
        var->map[*y][*x + 1] = 'o';
        *x += 1;
        return;
    }
    if (move_on_direction_(var, x, y, cas) == 1)
        return;
    var->map[*y][*x] = 'o';
    var->map[*y + 1][*x] = 'o';
    *y += 1;
}

static int possibility_move(variable_t const *var, int x, int y,
    int cas)
{
    if (cas == 1 && y - 1 >= 0 && var->map[y - 1][x] == '*')
            return (1);
    if (cas == 2 && x + 1 <= var->size_x && var->map[y][x + 1] == '*')
            return (2);
    if (cas == 3 && x - 1 >= 0 && var->map[y][x - 1] == '*')
            return (3);
    if (cas == 4 && y + 1 <= var->size_y && var->map[y + 1][x] == '*')
            return (4);
    return (0);
}

static int special_case(variable_t const *var, int x, int y)
{
    for (int i = 1; i <= 4; i++)
        if (possibility_move(var, x, y, i) != 0) {
            return (i);
        }
    return (-1);
}

static int check_end(variable_t *var, int x, int y, int *move)
{
    *move = special_case(var, x, y);
    if (x == var->size_x && y == var->size_y)
        return (0);
    if (x == 0 && y == 0 && *move == -1) {
        *move = 84;
        return (0);
    }
    return (1);
}

int backtracker(variable_t *var, int x, int y)
{
    int move = special_case(var, x, y);

    for (; check_end(var, x, y, &move);) {
        if (move != -1) {
            push(var, x, y, move);
            move_on_direction(var, &x, &y, move);
        } else {
            pop(var, &x, &y);
        }
    }
    if (move == 84)
        return (84);
    return (0);
}
