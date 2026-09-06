/*
** EPITECH PROJECT, 2018
** Day 08
** File description:
** Task 01
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *new_str;

    if (src == NULL)
        return (NULL);
    if (!(new_str = malloc(sizeof(char) * (my_strlen(src) + 1))))
        return (NULL);
    new_str = my_strcpy(new_str, src);
    return (new_str);
}
