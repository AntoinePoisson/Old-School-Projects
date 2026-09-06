/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include <stddef.h>

char *my_strdup(char const *str)
{
    int size = 0;
    char *result = NULL;

    if (str == NULL)
        return (NULL);
    for (size = 0; str[size] != '\0'; size++);
    if ((result = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    for (size = 0; str[size] != '\0'; size++)
        result[size] = str[size];
    result[size] = '\0';
    return (result);
}
