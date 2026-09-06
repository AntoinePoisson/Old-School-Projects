/*
** EPITECH PROJECT, 2019
** backtracker.c
** File description:
** backtracker algo
*/

#include <time.h>
#include <stdlib.h>
#include "my_struct.h"

int pop(variable_t *var, int *x, int *y);
int push(variable_t *var, int x, int y);
int move_on_direction_(variable_t *var, int *x, int *y, int cas);
void move_on_direction(variable_t *var, int *x, int *y, int cas);

static int possibility_move(variable_t const *var, int x, int y,
    int cas)
{
    if (cas == 1 && y - 2 >= 0 && var->map[y - 2][x] != '*')
        return (1);
    if (cas == 2 && y + 2 < var->size_x && var->map[y + 2][x] != '*')
        return (1);
    if (cas == 3 && x + 2 < var->size_y && var->map[y][x + 2] != '*')
        return (1);
    if (cas == 4 && x - 2 >= 0 && var->map[y][x - 2] != '*')
        return (1);
    return (0);
}

static int special_case(variable_t const *var, int x, int y)
{
    int count = 0;
    int save = 0;

    for (int i = 1; i <= 4; i++)
        if (possibility_move(var, x, y, i) == 1) {
            count++;
            save = i;
        }
    if (count > 1)
        return (0);
    if (count == 0)
        return (-1);
    return (save);
}

static int choose_direction(variable_t *var, int *x, int *y)
{
    int result = special_case(var, *x, *y);

    if (result > 0) {
        move_on_direction(var, x, y, result);
        return (1);
    }
    if (result == -1)
        return (0);
    for (result = rand() % (5 - 1) + 1; possibility_move(var, *x, *y, result)
        != 1; result = rand() % (5 - 1) + 1);
    move_on_direction(var, x, y, result);
    return (1);
}

int backtracker(variable_t *var, int x, int y)
{
    int move = special_case(var, x, y);

    for (int count = 0; count >= 0 || move != -1;) {
        if ((move = special_case(var, x, y)) != -1) {
            push(var, x, y);
            choose_direction(var, &x, &y);
            count++;
        } else {
            pop(var, &x, &y);
            count--;
        }
    }
    while (pop(var, &x, &y) != 84);
    return (0);
}
