/*
** EPITECH PROJECT, 2019
** split_map.c
** File description:
** split_map
*/

#include <time.h>
#include <stdlib.h>
#include "my_struct.h"

char **fill_map(variable_t *var);
int backtracker(variable_t *var, int y, int x);
int find_midle_map_two(variable_t *var, int posi, int cas);
int find_midle_map(variable_t const *var, int posi, int cas);
void is_extension_split_map_y(variable_t *var, int i, int split);
void is_extension_split_map_y_two(variable_t *var, int *i, int split);

static int management_enter_tunnel_x(variable_t *var, int split)
{

    for (int i = var->size_y - 1; i >= 0; i--) {
        if (var->map[i][split] == '0')
            return (i);
    }
    return (-1);
}

void alternance_exit_tunnel(variable_t *var, int i, int split, int cass)
{
    static int cas = 1;

    if (cass == -1) {
        cas = 1;
        return;
    }
    var->map[split - 1][i - 1] = 'X';
    var->map[split][i - 1] = 'X';
    if (cas == 1) {
        var->map[split - 1][i - 2] = '*';
        cas = 0;
    } else {
        var->map[split + 1][i - 2] = '*';
    }
}

static void split_map_y(variable_t *var, int i)
{
    int split = find_midle_map(var, var->split_y, 0);

    for (int count = 1; count < var->nbr_split_y + 1; count++, i = 0) {
        split = find_midle_map(var, count * var->split_y, 0);
        is_extension_split_map_y_two(var, &i, split);
        is_extension_split_map_y(var, i, split);
        alternance_exit_tunnel(var, i, split, -1);
    }
}

static void split_map_x(variable_t *var)
{
    int split = find_midle_map(var, var->split_x, 1);
    int stop = management_enter_tunnel_x(var, split);

    for (int count = 1; count < var->nbr_split_x + 1; count++) {
        split = find_midle_map(var, count * var->split_x, 1);
        for (int i = 0; var->map[i]; i++) {
            var->map[i][split - 1] = 'X';
            var->map[i][split] = '*';
            var->map[i][split + 1] = 'X';
            if (i == stop)
                var->map[i][split - 1] = '*';
        }
        var->map[0][split + 1] = '*';
    }
}

void split_map(variable_t *var, char *av[])
{
    int split_y = find_midle_map_two(var, 0, 5);
    int split_x = 0;

    split_map_x(var);
    split_map_y(var, 0);
    var->size_x = atoi(av[2]);
    var->size_y = atoi(av[1]);
    for (int y = 0; y < var->nbr_split_y + 1; y++) {
        split_y = find_midle_map_two(var, y * var->split_y, 0);
        if (y > 0)
            split_y = split_y + 2;
        for (int x = 0; x < var->nbr_split_x + 1; x++) {
            split_x = find_midle_map_two(var, x * var->split_x, 1);
            if (x > 0)
                split_x = split_x + 2;
            backtracker(var, split_x, split_y);
        }
    }
}
