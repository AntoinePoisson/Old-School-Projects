/*
** EPITECH PROJECT, 2019
** check_error
** File description:
** check_error
*/

#include "my_lib.h"

int check_error(int ac, char *av[])
{
    if (ac != 2) {
        my_putstr("\n");
        return (1);
    }
    return (0);
}
