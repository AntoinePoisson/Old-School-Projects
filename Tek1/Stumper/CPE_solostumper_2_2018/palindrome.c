/*
** EPITECH PROJECT, 2019
** palindrome.c
** File description:
** palindrome
*/

#include "my_lib.h"

static int check_maj(char av)
{
    if (av >= 'A' && av <= 'Z')
        return (av + 32);
    return (av);
}

int palindrome(char *av)
{
    int i_two = my_strlen(av) - 1;
    int i = 0;

    if (i_two == 1)
        return (1);
    for (; (i != i_two) && i_two >= 0; i++, i_two--)
        if (check_maj(av[i]) != check_maj(av[i_two]))
            return (0);
    return (1);
}
