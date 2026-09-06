/*
** EPITECH PROJECT, 2019
** check_error
** File description:
** check_error
*/

#include "my_lib.h"

int check_error(int ac, char *av[])
{
    int nbr = 0;

    if (ac != 3)
        return (84);
    for (int i = 1; i <= 2; i++)
        for (int i_two = 0; av[i][i_two] != '\0'; i_two++)
            if (!(av[i][i_two] >= '0' && av[i][i_two] <= '9'))
                return (84);
    nbr = my_getnbr(av[1]);
    if (!(1 < nbr && nbr < 100))
        return (84);
    nbr = my_getnbr(av[2]);
    if (!(nbr > 0))
        return (84);
    return (0);
}
