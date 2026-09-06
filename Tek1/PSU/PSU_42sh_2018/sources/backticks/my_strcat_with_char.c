/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** my_strcat_with_char.c
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strcat_with_char(char *dest, char *src, char c)
{
    char *result;
    int total_len = my_strlen(src) + my_strlen(dest);
    int i = 0;

    if (dest == NULL)
        return (src);
    if (src == NULL)
        return (dest);
    if (!(result = malloc(sizeof(char) * (total_len + 2))))
        return (NULL);
    result[total_len + 1] = '\0';
    for (int j = 0; dest[j]; j++)
        result[i++] = dest[j];
    result[i] = c;
    i++;
    for (int k = 0; src[k]; k++)
        result[i++] = src[k];
    return (result);
}
