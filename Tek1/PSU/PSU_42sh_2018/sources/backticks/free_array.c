/*
** EPITECH PROJECT, 2018
** lib
** File description:
** free_array.c
*/

#include <stdlib.h>
#include <stddef.h>

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
