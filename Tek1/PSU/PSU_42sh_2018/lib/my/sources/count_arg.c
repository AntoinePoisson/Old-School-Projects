/*
** EPITECH PROJECT, 2019
** count_arg.c
** File description:
** count_arg
*/

#include <stddef.h>

int count_arg(char *arg[])
{
    int count = 0;

    if (arg == NULL)
        return (0);
    for (; arg[count] != NULL; count++) {
    }
    return (count);
}
