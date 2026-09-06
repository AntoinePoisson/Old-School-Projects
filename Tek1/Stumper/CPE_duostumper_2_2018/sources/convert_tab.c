/*
** EPITECH PROJECT, 2019
** Boggle
** File description:
** convert tabs
*/

#include <stdlib.h>
#include "my_struct.h"
#include <stdlib.h>

char **convert_to_algo(variable_t *var)
{
    char **tab;

    tab = malloc(sizeof(char *) * (var->flag_s + 1));
    for (int i = 0; i < (var->flag_s + 1); i++)
        tab[i] = malloc(sizeof(char) * (var->flag_s + 1));
    for (int i = 0, y = 0; var->arg_g[i] != '\0'; y++)
        for (int x = 0; x != var->flag_s; x++, i++)
            tab[y][x] = var->arg_g[i];
    return (tab);
}

int convert_from_algo(int y, int x, variable_t *var)
{
    int new_y = y - 1;
    int new_x = (x / 2) - 1;
    char character = var->tab[new_y][new_x] - 32;

    var->tab[new_y][new_x] = character;
    return (0);
}
