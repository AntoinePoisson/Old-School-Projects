/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** duplicates a constant string into another
*/

#include <stddef.h>
#include <stdlib.h>
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = my_strlen(src);
    char *src2 = NULL;
    src2 = malloc(sizeof(char) * (i + 1));

    if (src2 == NULL)
        return (NULL);
    for (int i = 0; src[i] != '\0'; i = i + 1)
        src2[i] = src[i];
    return (src2);
}
