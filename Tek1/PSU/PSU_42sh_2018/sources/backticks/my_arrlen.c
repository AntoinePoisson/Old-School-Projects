/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_arrlen.c
*/

#include <stddef.h>

int my_arrlen(char **array)
{
    int i = 0;

    if (!array || array == NULL)
        return (0);
    for (; array[i]; i++);
    return (i);
}
