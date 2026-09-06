/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check_eog.c
*/

#include "navy.h"

static int check_win(char **enemy_map)
{
    int a, b;
    int destroyed_ships = 0;

    for (a = 2; enemy_map[a] != NULL; a++) {
        for (b = 2; enemy_map[a][b] != '\0'; b++)
            destroyed_ships += (enemy_map[a][b] == 'x') ? 1 : 0;
    }
    if (destroyed_ships != 14)
        return (-1);
    mputstr("I won\n");
    return (0);
}

static int check_lose(char **my_map)
{
    int a, b;

    for (a = 2; my_map[a] != NULL; a++)
        for (b = 2; my_map[a][b] != '\0'; b++)
            if (my_map[a][b] >= '2' && my_map[a][b] <= '5')
                return (-1);
    mputstr("Enemy won\n");
    recover_signal('e');
    return (1);
}

int end_of_game(char **my_map, char **enemy_map, int end)
{
    end = (check_lose(my_map) == -1) ? check_win(enemy_map) : 1;
    return (end);
}
