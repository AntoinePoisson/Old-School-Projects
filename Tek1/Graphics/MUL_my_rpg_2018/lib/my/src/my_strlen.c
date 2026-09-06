/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** returns numbers of characters
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int a;

    a = 0;
    if (str == NULL)
        return (0);
    while (str[a] != '\0') {
        a = a + 1;
    }
    return (a);
}
