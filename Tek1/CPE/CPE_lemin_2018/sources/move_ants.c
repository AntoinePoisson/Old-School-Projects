/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** move_ants.c
*/

#include "lem_in.h"

int last_room(anthill_t anthill[], int *path, int ants)
{
    for (int a = 0; a != ants; a++)
        if (path[anthill[a].index] != -1)
            return (-1);
    return (0);
}

static int check_room(anthill_t anthill[], int *path, int ants, int a)
{
    int index = anthill[a].index + 1;

    if (path[anthill[a].index] == -1)
        return (-1);
    for (int b = 0; b != ants; b++)
        if (anthill[b].index == index && path[index] != -1)
            return (-1);
    return (0);
}

void is_extension_simple_path(int *print, int *path, int a, int cas)
{
    if (cas == 1)
        if (path[2] != -1 && a != 0 && *print == 1)
            write(1, " ", 1);
    if (cas == 2)
        if (path[2] == -1)
            write(1, "\n", 1);
    if (cas == 3) {
        *print = 0;
        if (path[2] != -1)
            write(1, "\n", 1);
    }
}

int simple_path(int ants, int *path, variable_t *var)
{
    anthill_t anthill[ants];

    for (int a = 0; a != ants; a++) {
        anthill[a].ant = a + 1;
        anthill[a].index = 1;
    }
    for (int print = 0;last_room(anthill, path, ants) == -1;) {
        for (int a = 0; a != ants; a++) {
            if (check_room(anthill, path, ants, a) == 0) {
                is_extension_simple_path(&print, path, a, 1);
                disp(anthill[a].ant, var->room[path[anthill[a].index]]->name);
                is_extension_simple_path(&print, path, a, 2);
                anthill[a].index += 1;
                print = 1;
            }
        }
        is_extension_simple_path(&print, path, 5, 3);
    }
    return (0);
}

int move_ants(int ants, int **path, variable_t *var)
{
    return (simple_path(ants, path[0], var));
}
