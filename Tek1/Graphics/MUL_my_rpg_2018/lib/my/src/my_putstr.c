/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Afficher une chaîne de caractère
*/

#include <stddef.h>
#include <unistd.h>

int my_putstr(char const *str)
{
    int a = 0;

    if (str == NULL)
        my_putstr("(null)");
    else {
        for (; str[a]; a++);
        write(1, str, a);
    }
    return (0);
}
