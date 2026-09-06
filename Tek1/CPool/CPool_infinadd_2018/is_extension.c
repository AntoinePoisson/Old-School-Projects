/*
** EPITECH PROJECT, 2018
** is_extension
** File description:
** it's extension of infin_add
*/
#include "./include/my.h"

int is_extension_end_b(char *av[], int b, int i, int exit_negative)
{
    if (av[b][i + exit_negative] == '\0')
        return (0);
    return (1);
}

int is_extension_end_a(char *av[], int a, int i, int exit_negative)
{
    if (av[a][i + exit_negative] == '\0')
        return (0);
    return (1);
}

int is_extension_retenue(int *r, int *retenue)
{
    *retenue = 0;
    if (*r > 9) {
        *r = *r % 10;
        *retenue = 1;
    }
    return (0);
}

int is_extension_exit_negative(char *av[], int a, int b)
{
    if (av[1][0] == '-' && av[2][0] == '-') {
        my_revstr(av[a]);
        my_revstr(av[b]);
        return (1);
    }
    my_revstr(av[a]);
    my_revstr(av[b]);
    return (0);
}
