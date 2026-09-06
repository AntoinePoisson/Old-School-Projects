/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main.c
*/

#include "navy.h"

int main(int ac, char **av)
{
    if (mstrcmp(av[1], "-h") == 0)
        return (game_help());
    if (error_handling(ac, av) == -1)
        return (84);
    return (battleship(av));
}
