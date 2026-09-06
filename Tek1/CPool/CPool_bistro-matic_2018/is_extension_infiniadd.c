/*
** EPITECH PROJECT, 2018
** is_extension
** File description:
** it's extension of infin_add
*/

#include "./include/my.h"

int is_extension_retenue(int *r, int *retenue)
{
    *retenue = 0;
    if (*r > 9) {
        *r = *r % 10;
        *retenue = 1;
    }
    return (*r);
}

int is_extension_exit_negative(char *first, char *second)
{
    if (first[0] == '-' && second[0] == '-') {
        my_revstr(first);
        my_revstr(second);
        return (1);
    }
    my_revstr(first);
    my_revstr(second);
    return (0);
}
