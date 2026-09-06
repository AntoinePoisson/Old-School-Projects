/*
** EPITECH PROJECT, 2019
** dante
** File description:
** generator
*/

#include "my_struct.h"

void is_extension_split_map_y(variable_t *var, int i, int split)
{
    var->map[split + 1][0] = '*';
    if (var->map[split + 2][i - 1] == '0')
        var->map[split + 1][i - 1] = '*';
    else
        var->map[split + 1][i - 2] = '*';
}

int move_on_direction_(variable_t *var, int *x, int *y, int cas)
{
    if (cas == 3) {
        var->map[*y][*x] = '*';
        var->map[*y][*x + 1] = '*';
        *x += 2;
        var->map[*y][*x] = '*';
        return (1);
    }
    return (0);
}

void move_on_direction(variable_t *var, int *x, int *y, int cas)
{
    if (cas == 1) {
        var->map[*y][*x] = '*';
        var->map[*y - 1][*x] = '*';
        *y -= 2;
        var->map[*y][*x] = '*';
        return;
    }
    if (cas == 2) {
        var->map[*y][*x] = '*';
        var->map[*y + 1][*x] = '*';
        *y += 2;
        var->map[*y][*x] = '*';
        return;
    }
    if (move_on_direction_(var, x, y, cas) == 1)
        return;
    var->map[*y][*x] = '*';
    var->map[*y][*x - 1] = '*';
    *x -= 2;
    var->map[*y][*x] = '*';
}
