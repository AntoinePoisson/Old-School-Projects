/*
** EPITECH PROJECT, 2019
** navy
** File description:
** battleship.c
*/

#include "navy.h"

static int load_maps(battleship_t *navy, char **av)
{
    if (fill_map(&navy->my_map, &navy->enemy_map, av) == -1)
        return (-1);
    display_map(navy->my_map);
    mputstr("enemy's positions:\n");
    display_map(navy->enemy_map);
    return (0);
}

static void disp_loop(char **map1, char **map2, int round, char **av)
{
    if (((round % 2) == 0 && av[2] != NULL) ||
        ((round % 2) != 0 && av[2] == NULL)) {
        mputstr("my positions:\n");
        display_map(map1);
        mputstr("enemy's positions:\n");
        display_map(map2);
    }
}

int battleship(char **av)
{
    battleship_t navy;

    if (!av || connection(av, &navy) == -1)
        return (84);
    if (redirect_signal() == -1)
        return (84);
    if (load_maps(&navy, av) == -1)
        return (84);
    for (int round = (av[2] == NULL) ? 2 : 1; ; round++) {
        navy.attack = torpedo(av, &navy, round);
        if (navy.attack == -1)
            return (-1);
        if (check_hit(av, &navy, round) == -1)
            return (84);
        disp_loop(navy.my_map, navy.enemy_map, round, av);
        navy.end = end_of_game(navy.my_map, navy.enemy_map, navy.end);
        if (navy.end != -1)
            return (navy.end);
    }
    return (0);
}
