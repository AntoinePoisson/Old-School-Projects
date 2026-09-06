/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** D7, function that concatenates two strings
*/

#include <stddef.h>

char *my_strcat_charac(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    if (dest == NULL)
        return (NULL);
    if (src == NULL)
        return (dest);
    for (i = 0; dest[i] != '\0'; i++) {
    }
    for (a = 0; src[a] != '\0'; a++, i++) {
        dest[i] = src[a];
    }
    dest[i] = '\0';
    return (dest);
}
