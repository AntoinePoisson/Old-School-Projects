/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_put.h"

int check_error(int ac, char *av[], variable_t *var);
int my_putstr(char const *str);
int backtracker(variable_t *var, int x, int y);
void imperfect_maze(variable_t *var);
void split_map(variable_t *var, char *av[]);
void handle_imperfect(variable_t *var, int ac, char *av[]);

char **fill_map(variable_t *var)
{
    char **tab = malloc(sizeof(char *) * (var->size_y + 1));

    tab[var->size_y] = NULL;
    for (int i = 0; i < var->size_y; i++) {
        tab[i] = malloc(sizeof(char) * (var->size_x + 1));
        tab[i][var->size_x] = '\0';
        if (i % 2 == 0)
            for (int j = 0; j < var->size_x; j++) {
                if (j % 2 == 0)
                    tab[i][j] = '0';
                else
                    tab[i][j] = 'X';
            }
        else
            for (int j = 0; j < var->size_x; j++)
                tab[i][j] = 'X';
    }
    return (tab);
}

void check_valid_end(variable_t *var)
{
    if ((var->size_x % 2) == 1 && (var->size_y % 2) == 1)
        return;
    if (((var->size_x % 2) == 1 && (var->size_y % 2) != 1)
        || ((var->size_x % 2) != 1 && (var->size_y % 2) == 1))
        var->map[var->size_y - 1][var->size_x - 1] = '*';
    if ((var->size_x % 2) != 1 && (var->size_y % 2) != 1) {
        var->map[var->size_y - 1][var->size_x - 1] = '*';
        var->map[var->size_y - 2][var->size_x - 1] = '*';
    }
}

int check_num(int x, int y)
{
    if (x > 2 || y > 2)
        return (0);
    else {
        if (y == 1 && x == 1)
            write(1, "*", 1);
        if (y == 1 && x == 2)
            write(1, "**", 2);
        if (y == 2 && x == 1)
            write(1, "*\n*", 3);
        if (y == 2 && x == 2)
            write(1, "*X\n**", 5);
        return (1);
    }
}

int main(int ac, char *av[])
{
    variable_t *var = malloc(sizeof(variable_t));

    if (check_error(ac, av, var) != 0)
        return (84);
    srand(time(NULL));
    if (check_num(var->size_x, var->size_y) == 1)
        return (0);
    var->map = fill_map(var);
    if (var->split_x != 0 && var->split_x != 0)
        split_map(var, av);
    else {
        var->size_x = atoi(av[2]);
        var->size_y = atoi(av[1]);
    if (backtracker(var, 0, 0) == 84)
            return (84);
        var->map[0][0] = '*';
    }
    handle_imperfect(var, ac, av);
    return (0);
}
