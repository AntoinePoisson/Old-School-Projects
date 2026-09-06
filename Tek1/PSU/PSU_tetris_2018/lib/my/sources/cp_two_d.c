/*
** EPITECH PROJECT, 2018
** cp_two_d.c
** File description:
** cp_two_d
*/

#include <stdlib.h>

char **my_malloc_two_d(int nbr);
char *my_strdup(char const *str);

int cal_size_y(char **str)
{
    int i = 0;

    for (; str && str[i]; i++);
    return (i);
}

char **cp_two_d(char **str)
{
    int size_y = cal_size_y(str);
    char **new = my_malloc_two_d(size_y + 1);

    for (int i = 0; str && str[i]; i++)
        new[i] = my_strdup(str[i]);
    return (new);
}