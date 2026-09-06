/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** D7, function that concatenates two strings
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    char *result = NULL;
    int i = 0;
    int a = 0;

    if (dest != NULL)
        for (a = 0; dest[a] != '\0'; a++);
    if (src != NULL)
        for (int i_two = 0; src[i_two] != '\0'; i_two++, a++);
    if ((result = malloc(sizeof(char) * (a + 1))) == NULL)
        return (NULL);
    if (dest != NULL)
        for (; dest[i] != '\0'; i++)
            result[i] = dest[i];
    if (src != NULL)
        for (a = 0; src[a] != '\0'; a++, i++)
            result[i] = src[a];
    result[i] = '\0';
    return (result);
}
