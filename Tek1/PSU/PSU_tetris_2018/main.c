/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main.c
*/

#include "my_tetris.h"

int main(int ac, char const **av)
{
    if (ac) {
    }
    if (av[1] && str_comp(av[1], "--help") == 0)
        return (help_opt(av[0]));
    return (tetris(av));
}
