/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my_lib.h"

int check_error(int ac, char *av[]);
int is_fractal_management(char *av[]);

int main(int ac, char *av[])
{
    if (check_error(ac, av) != 0)
        return (84);
    if (my_getnbr(av[1]) == 0) {
        my_putstr("#\n");
        return (0);
    }
    return (is_fractal_management(av));
}
