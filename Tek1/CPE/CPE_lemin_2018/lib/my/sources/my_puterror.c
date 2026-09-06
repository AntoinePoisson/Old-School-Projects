/*
** EPITECH PROJECT, 2019
** my_puterror.c
** File description:
** my_puterror
*/

#include <unistd.h>
#include <stddef.h>

int my_puterror(char const * str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    for (; str[i] != '\0'; i++) {
    }
    write(2, str, i);
    return (84);
}
