/*
** EPITECH PROJECT, 2019
** my_malloc_two_d.c
** File description:
** my_malloc of char **
*/

#include <stdlib.h>
#include <stddef.h>

char **my_malloc_two_d(int size)
{
    char **str = malloc(sizeof(char *) * (size));

    if (str == NULL)
        return (NULL);
    for (int i = 0; i != size; i++)
        str[i] = NULL;
    return (str);
}
