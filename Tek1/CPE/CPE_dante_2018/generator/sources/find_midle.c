/*
** EPITECH PROJECT, 2019
** dante
** File description:
** find midle
*/

#include <stddef.h>
#include "my_struct.h"

char **fill_map(variable_t *var);

int find_midle_map_two(variable_t *var, int posi, int cas)
{
    static char **map = NULL;

    if (cas == 5)
        map = fill_map(var);
    if (cas == 1 && map[0][posi] == '0')
        return (posi);
    if (cas == 1 && map[0][posi + 1] == '0')
        return (posi + 1);
    if (cas == 1 && posi > 0 && map[0][posi - 1] == '0')
        return (posi - 1);
    if (cas == 0 && map[posi][0] == '0')
        return (posi);
    if (cas == 0 && map[posi + 1][0] == '0')
        return (posi + 1);
    if (cas == 0 && posi > 0 && map[posi - 1][0] == '0')
        return (posi - 1);
    return (posi);
}

int find_midle_map(variable_t const *var, int posi, int cas)
{
    if (cas == 1 && var->map[0][posi] == '0')
        return (posi);
    if (cas == 1 && var->map[0][posi + 1] == '0')
        return (posi + 1);
    if (cas == 1 && posi > 0 && var->map[0][posi - 1] == '0')
        return (posi - 1);
    if (cas == 0 && var->map[posi][0] == '0')
        return (posi);
    if (cas == 0 && var->map[posi + 1][0] == '0')
        return (posi + 1);
    if (cas == 0 && posi > 0 && var->map[posi - 1][0] == '0')
        return (posi - 1);
    return (posi);
}
