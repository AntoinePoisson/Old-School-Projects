/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display fractals
*/

#include "my_put.h"

int display(char **str)
{
    for (int i = 0; str[i]; i++) {
        my_putstr(str[i]);
        if (str[i + 1])
            my_putchar('\n');
    }
    return (0);
}
