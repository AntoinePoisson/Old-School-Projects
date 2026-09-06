/*
** EPITECH PROJECT, 2019
** dante
** File description:
** hanlde imperfect maze
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_struct.h"

void imperfect_maze(variable_t *var);
void check_valid_end(variable_t *var);

void free_funct(variable_t *var)
{
    for (int i = 0; var->map[i]; i++)
        free(var->map[i]);
    free(var->map);
    free(var);
}

void handle_imperfect(variable_t *var, int ac, char *av[])
{
    var->size_x = atoi(av[1]);
    var->size_y = atoi(av[2]);
    check_valid_end(var);
    if (ac != 4 || strcmp(av[3], "perfect") != 0)
        imperfect_maze(var);
    for (int i = 0; var->map[i]; i++) {
        write(1, var->map[i], var->size_x);
        if (var->map[i + 1] != NULL)
            write(1, "\n", 1);
    }
    free_funct(var);
}
