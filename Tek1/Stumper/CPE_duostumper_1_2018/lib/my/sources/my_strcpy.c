/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** D6, copie function in the other function
*/

#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    for (a = 0; src[a] != '\0'; a++)
        dest[a] = src[a];
    dest[a] = '\0';
    return (dest);
}
