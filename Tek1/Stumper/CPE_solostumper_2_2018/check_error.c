/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include "my_lib.h"

int check_error(int ac, char *av[])
{
    if (ac != 2)
        return (84);
    if (my_strlen(av[1]) == 0)
        return (84);
    return (0);
}
