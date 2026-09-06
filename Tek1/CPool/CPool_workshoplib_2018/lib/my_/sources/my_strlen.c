/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Write a function that counts string.
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str != NULL)
        for (; str[i] != '\0'; i++) {
        }
    return (i);
}
