/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** D4, function that displays, one_to_one, the characters of a string
*/

#include <unistd.h>
#include <stddef.h>

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    for (; str[i] != '\0'; i++) {
    }
    write(1, str, i);
    return (0);
}
