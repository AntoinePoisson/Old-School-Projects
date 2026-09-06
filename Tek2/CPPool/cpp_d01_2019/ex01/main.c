/*
** EPITECH PROJECT, 2020
** main
** File description:
** day01
*/

#include <stdlib.h>
#include <stdbool.h>
#include "menger.h"

int my_compute_power_rec(int nb, int p)
{
    int i = 1;
    int a = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    for (i = 1; i != p; i = i + 1)
        nb = nb * a;
    return (nb);
}

int check_error(int ac, char *av[])
{
    int size = 0;
    int level = 0;

    if (ac != 3)
        return (true);
    for (int i = 0; av[1][i]; i++)
        if (!(av[1][i] >= '0' && av[1][i] <= '9'))
            return (true);
    for (int i = 0; av[2][i]; i++)
        if (!(av[2][i] >= '0' && av[2][i] <= '9'))
            return (true);
    level = atoi(av[2]);
    size = atoi(av[1]);    
    if (size <= 0 || level < 0)
        return (true);
    if (size % 3 != 0 || !(size >= my_compute_power_rec(3, level)))
        return (true);
    return (false);
}

int main(int ac, char *av[])
{
    int size = 0;
    int level = 0;

    if (check_error(ac, av))
        return (84);
    size = atoi(av[1]);
    level = atoi(av[2]);
    if (level >= 1) {
        menger(level, size, 0, 0);
    }
    return (0);
}