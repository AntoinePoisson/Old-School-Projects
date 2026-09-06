/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** clean_str.c
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

int my_strlen(char const *str);

char *clean_str(char *str)
{
    char *new_str = NULL;
    int i = 0;
    int j = my_strlen(str) - 1;
    int len = 0;

    if (str == NULL)
        return (NULL);
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
            || str[i] == '\n'))
        i++;
    while (j > 0 && (str[j] == ' ' || str[j] == '\t' || str[j] == '\n'))
        j--;
    len = j - i + 1;
    if (!(new_str = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    new_str[len] = '\0';
    for (int k = 0; i <= j; k++, i++)
        new_str[k] = str[i];
    return (new_str);
}
