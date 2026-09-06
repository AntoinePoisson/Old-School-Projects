/*
** EPITECH PROJECT, 2018
** my_display_rush
** File description:
** Display rush1-# and others parameters.
*/

#include "rush3.h"

void my_display_rush(int a, int b, int c)
{
    my_putstr("[rush1-");
    my_put_nbr(a);
    my_putstr("] ");
    my_put_nbr(b);
    write(1, " ", 1);
    my_put_nbr(c);
}
