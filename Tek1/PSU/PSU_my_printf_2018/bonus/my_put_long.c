/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** D3, function that displays the number given as a parameter
*/

#include "my_put_long.h"

int my_put_long(long nb)
{
    long quotient = 0;
    long reste = 0;

    if (nb >= 0) {
        quotient = nb % 10;
        reste = nb / 10;
        if (reste != 0)
            my_put_long(reste);
        my_putchar_color_int(quotient + '0');
    }
    if (nb < 0) {
        my_putchar_color_int(45);
        my_put_long(-nb);
    }
    return (0);
}
