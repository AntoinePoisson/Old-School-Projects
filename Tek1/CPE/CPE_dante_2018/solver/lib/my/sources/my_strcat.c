/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** D7, function that concatenates two strings
*/

#include <stddef.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    for (i = 0; dest && dest[i] != '\0'; i++);
    for (a = 0; dest && src && src[a] != '\0'; a++, i++) {
        dest[i] = src[a];
    }
    dest[i] = '\0';
    return (dest);
}
