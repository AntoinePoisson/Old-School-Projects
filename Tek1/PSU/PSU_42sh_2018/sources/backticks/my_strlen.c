/*
** EPITECH PROJECT, 2018
** Day 04
** File description:
** Task 03
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int nb = 0;

    if (!str || str == NULL)
        return (0);
    while (str[nb] != '\0') {
        nb = nb + 1;
    }
    return (nb);
}
