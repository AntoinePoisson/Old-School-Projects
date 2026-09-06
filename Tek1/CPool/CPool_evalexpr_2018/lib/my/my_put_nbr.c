/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Day03 task07 my_put_nbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int a;
    int z;

    while (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
        return (0);
    }
    while (nb >= 0) {
        z = nb % 10;
        a = nb / 10;
        if (a != 0) {
            my_put_nbr(a);
        }
        my_putchar(z + 48);
        return (0);
    }
    return (0);
}
