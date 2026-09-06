/*
** EPITECH PROJECT, 2019
** create_two_d_tab.c
** File description:
** create_two_d_tab
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_struct.h"
#include "my_lib.h"

void display_tab(variable_t *var)
{
    for (int i = 0; var->tab[i]; i++) {
        my_putstr(var->tab[i]);
        write(1, "\n", 1);
    }
}

static int fill_first_and_last_line(variable_t *var, int size, int size_cols)
{
    for (int i = 0; i < var->flag_s + 2; i++, var->tab[i] = NULL);
    for (int i = 0; i < var->flag_s + 2; i++) {
        var->tab[i] = malloc(sizeof(char) * size_cols);
        if (var->tab[i] == NULL)
            return (84);
    }
    for (int i = 0; i < var->flag_s + 2; i++)
        for (int i_two = 0; i_two < size_cols; i_two++)
            var->tab[i][i_two] = '\0';
    for (int i = 0; i < size_cols - 2; i++) {
        var->tab[0][i] = '+';
        var->tab[size][i] = '+';
    }
    return (0);
}

static int fill_tab(variable_t *var)
{
    int i_two = 0;
    int posi = 0;

    for (int i = 1; i < var->flag_s + 1; i++, i_two = 0) {
        var->tab[i][i_two++] = '|';
        var->tab[i][i_two++] = ' ';
        for (int count = 0; count < var->flag_s; count++, posi++) {
            var->tab[i][i_two++] = var->arg_g[posi];
            var->tab[i][i_two++] = ' ';
        }
        var->tab[i][i_two++] = '|';
        var->tab[i][i_two] = '\0';
    }
    return (0);
}

int create_two_d_tab(variable_t *var)
{
    int size_cols = var->flag_s * 2 + 5;

    var->tab = malloc(sizeof(char *) * (var->flag_s + 3));
    if (var->tab == NULL)
        return (84);
    if (fill_first_and_last_line(var, var->flag_s + 1, size_cols) == 84)
        return (my_puterror("Failure Malloc.\n"));
    return (fill_tab(var));
}
