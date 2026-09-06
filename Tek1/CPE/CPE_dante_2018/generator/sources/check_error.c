/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_struct.h"

void alternance_exit_tunnel(variable_t *var, int i, int split, int cass);

void is_extension_split_map_y_two(variable_t *var, int *i, int split)
{
    for (; var->map[split][*i]; *i += 1) {
        if (var->map[split][*i] == '*') {
            alternance_exit_tunnel(var, *i, split, 1);
        } else if (*i == 0 || var->map[split + 1][*i - 1] != '*') {
            var->map[split - 1][*i] = 'X';
            var->map[split][*i] = '*';
            var->map[split + 1][*i] = 'X';
        } else {
            var->map[split][*i + 1] = '*';
            var->map[split - 1][*i + 1] = '*';
            *i += 1;
        }
    }
}

void nbr_split(variable_t *var)
{
    int count_x = 1;
    int count_y = 1;

    for (int i = 24; i < var->size_x; i += 24)
        count_x++;
    for (int i = 24; i < var->size_y; i += 24)
        count_y++;
    var->split_x = (var->size_x / (count_x));
    var->split_y = (var->size_y / (count_y));
    if (count_x != 1)
        count_x--;
    if (count_y != 1)
        count_y--;
    var->nbr_split_x = count_x;
    var->nbr_split_y = count_y;
}

int my_str_isnum(char const *str)
{
    if (str == NULL || str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    }
    return (1);
}

int check_error(int ac, char *av[], variable_t *var)
{
    if (ac != 3 && ac != 4)
        return (84);
    if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
        return (84);
    if (var == NULL)
        return (84);
    var->size_x = atoi(av[1]);
    var->size_y = atoi(av[2]);
    var->list = NULL;
    var->map = NULL;
    var->split_x = 0;
    var->split_y = 0;
    if (var->size_y >= 25 && var->size_x >= 25)
        nbr_split(var);
    return (0);
}