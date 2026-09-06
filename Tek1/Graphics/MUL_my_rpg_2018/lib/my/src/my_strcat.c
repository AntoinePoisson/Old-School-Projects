/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** D7, function that concatenates two strings
*/

#include <stdlib.h>
#include <stddef.h>

char *my_strcat(char *dest, char *src)
{
    char *result = NULL;
    int i = 0;
    int a = 0;

    for (a = 0; dest != NULL && dest[a] != '\0'; a++);
    for (i = 0; src != NULL && src[i] != '\0'; a++, i++);
    if ((result = malloc(sizeof(char) * (a + 3))) == NULL)
        return (NULL);
    if (dest != NULL)
        for (i = 0; dest[i] != '\0'; i++)
            result[i] = dest[i];
    if (src != NULL)
        for (a = 0; src[a] != '\0'; a++, i++)
            result[i] = src[a];
    result[i] = '\0';
    return (result);
}
