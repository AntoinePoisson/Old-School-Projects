/*
** EPITECH PROJECT, 2019
** is_initialization.c
** File description:
** is_initialization
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_lib.h"

static char **border(char **map, var_t *var)
{
    int i = 0;

    for (i = 0; i < var->size + 2; i++)
        map[0][i] = '*';
    map[0][i] = '\0';
    for (i = 0; i < var->size + 2; i++)
        map[var->nbr_line + 1][i] = '*';
    map[var->nbr_line + 1][i] = '\0';
    for (i = 1; i <= var->nbr_line; i++)
        for (int i_two = 0; i_two < var->size + 2; i_two++) {
            if (i_two == 0 || i_two == var->size + 1)
                map[i][i_two] = '*';
            else
                map[i][i_two] = ' ';
            map[i][i_two + 1] = '\0';
        }
    return (map);
}

static char **fill_map(char **map, var_t *var)
{
    int mid = ((var->size + 2) / 2);
    int range = 0;

    border(map, var);
    for (int i = 1; i <= var->nbr_line; i++, range++)
        for (int i_two = 1; i_two <= var->size; i_two++)
            if (i_two <= mid + range && i_two >= mid -range)
                map[i][i_two] = '|';
    return (map);
}

static int create_map(var_t *var)
{
    char **map = malloc(sizeof(char *) * (var->nbr_line + 2));

    if (map == NULL)
        return (84);
    for (int i = 0; i < var->nbr_line + 2; i++) {
        map[i] = malloc(sizeof(char) * var->size + 3);
        if (map[i] == NULL)
            return (84);
    }
    var->game_board = fill_map(map, var);
    return (0);
}

void is_init_pow(var_t *var)
{
    var->pow.zero = 0;
    var->pow.one = 0;
    var->pow.two = 0;
    var->pow.three = 0;
    var->pow.four = 0;
    var->pow.five = 0;
    var->pow.six = 0;
    var->pow.seven = 0;
}

int is_initialization(char *av[], var_t *var)
{
    var->nbr_line = my_getnbr(av[1]);
    var->nbr_remove = my_getnbr(av[2]);
    var->turn = 1;
    var->size = var->nbr_line + var->nbr_line - 1;
    is_init_pow(var);
    return (create_map(var));
}
