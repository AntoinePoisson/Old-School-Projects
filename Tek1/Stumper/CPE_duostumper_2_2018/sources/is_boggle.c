/*
** EPITECH PROJECT, 2019
** is_boggle.c
** File description:
** is_boggle
*/

#include <stddef.h>
#include "my_lib.h"
#include "my_struct.h"

int research_list(variable_t *var, int x, int y);
void add_element(variable_t *var, int x, int y);
void delete_element(variable_t *var, int x, int y);
void recovery_last_posi(variable_t *var, int *x, int *y);
int convert_to_algo(variable_t *var);
int convert_from_algo(int y, int x, variable_t *var);

static int control_range(variable_t *var, int *x, int *y, char charac)
{
    if (*x < var->flag_s && var->tab[*x + 1][*y] == charac &&
        research_list(var, *x + 1, *y) != 1) {
        *x += 1;
        return (1);
    }
    if (*x - 1 >= 0 && var->tab[*x - 1][*y] == charac &&
        research_list(var, *x - 1, *y) != 1) {
        *x -= 1;
        return (1);
    }
    if (var->tab[*y + 1] != NULL && var->tab[*x][*y + 1] == charac &&
        research_list(var, *x, *y + 1) != 1) {
        *y += 1;
        return (1);
    }
    if (*y - 1 >= 0 && var->tab[*x][*y - 1] == charac &&
        research_list(var, *x, *y - 1) != 1) {
        *y -= 1;
        return (1);
    }
    return (0);
}

static void analyze(variable_t *var, int x, int y, int posi)
{
    int modif = 0;
    int failure = 0;

    if (control_range(var, &x, &y, var->arg_w[posi]) == 1) {
        add_element(var, x, y);
        modif += 1;
    }
    while (modif >= 1 && var->arg_w[posi] && modif < 100) {
        if (control_range(var, &x, &y, var->arg_w[posi]) == 1) {
            if (failure == 1) {
                failure = 0;
                modif -= 1;
                delete_element(var, x, y);
            }
            add_element(var, x, y);
            modif += 1;
        } else {
            failure += 1;
            recovery_last_posi(var, &x, &y);
        }
        if (failure == 2) {
            failure = 0;
            delete_element(var, x, y);
            modif -= 1;
        }
    }
    delete_element(var, x, y);
}

int boggle(variable_t *var)
{
    char *word = var->arg_w;
    int posi = 0;
    int y = 0;

    for (int x = 0; word[posi] && var->tab[y] != NULL; posi++, y++) {
        for (; word[posi] && var->tab[y][x]; x++) {
            analyze(var, x, y, posi);
        }
    }
    if (word[posi] == '\0')
        return (1);
    return (0);
}

int is_algo(variable_t *var)
{
    char **save = var->tab;

    convert_to_algo(var);
    if (boggle(var) == 1) {
        for (; var->list; var->list = var->list->next)
            convert_from_algo(var->list->y, var->list->x, var);
        return (1);
    }
    var->tab = save;
    return (0);
}
