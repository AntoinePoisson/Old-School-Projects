/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Afficher une chaîne de caractère
*/

#include <stddef.h>
#include <unistd.h>

int my_puterror(char const *str)
{
    int a = 0;

    if (str == NULL)
        my_puterror("(null)");
    else {
        for (; str[a]; a++);
        write(2, str, a);
    }
    return (84);
}
