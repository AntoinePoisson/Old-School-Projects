/*
** EPITECH PROJECT, 2019
** lib
** File description:
** mstrchr.c
*/

#include <stddef.h>

char *my_strchr(char *str, int c)
{
    int a;

    for (a = 0; str[a] != c && str[a]; a++);
    return (str[a]) ? (&str[a]) : (NULL);
}
