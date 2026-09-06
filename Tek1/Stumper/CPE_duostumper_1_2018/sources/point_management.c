/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** first duostumper (fractal)
*/

#include "my_lib.h"
#include <stddef.h>

int check_if_point_in_line(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] == '.')
            return (i);
    return (-1);
}

int find_point_origin(int *y_rtrn, int *x_rtrn, char **init)
{
    int x = 0;
    int y = 0;
    int size = 0;

    for (y = 0; init[y] != NULL; y++) {
        x = check_if_point_in_line(init[y]);
        if (x != -1)
            break;
    }
    *y_rtrn = y + size - 1;
    *x_rtrn = x + size - 1;
}
