/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** backticks2.c
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "my_shell.h"

bool nb_backticks_is_even(char *str)
{
    int nb = 0;

    if (str == NULL)
        return (false);
    for (int i = 0; str[i]; i++)
        if (str[i] == '`')
            nb++;
    if (nb > 0 && nb % 2 == 0)
        return (true);
    return (false);
}

char *get_str_between_backticks(char *str)
{
    char *new_str = NULL;
    int i = 0;
    int j = my_strlen(str);
    int len = 0;

    if (str == NULL)
        return (NULL);
    for (; str[i] != '\0' && str[i] != '`'; i++);
    for (; j > 0 && str[j] != '`'; j--);
    len = j - i - 1;
    if (len <= 0)
        return (NULL);
    if (!(new_str = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    new_str[len] = '\0';
    i++;
    j--;
    for (int k = 0; i <= j; k++, i++)
        new_str[k] = str[i];
    return (new_str);
}

bool my_str_has_backtick(char *str)
{
    if (str == NULL)
        return (false);
    for (int i = 0; str[i]; i++)
        if (str[i] == '`')
            return (true);
    return (false);
}

bool my_str_starts_with_backtick(char *str)
{
    if (str == NULL)
        return (false);
    if (str[0] == '`')
        return (true);
    return (false);
}

bool my_str_finish_with_backtick(char *str)
{
    if (str == NULL)
        return (false);
    if (str[my_strlen(str) - 1] == '`')
        return (true);
    return (false);
}
