/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_double_array.c
*/

#include "mprintf.h"

int mp_double_array(char const **str)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != NULL; i++)
        for (j = 0; str[i][j] != '\0'; j++)
            write(1, &str[i][j], 1);
    return (0);
}
