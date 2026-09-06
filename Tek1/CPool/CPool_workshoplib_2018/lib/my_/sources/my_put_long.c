/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** d3, function that displays the number given as a parameter
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
        my_putchar(quotient + '0');
    }
    if (nb < 0) {
        my_putchar(45);
        my_put_long(-nb);
    }
    return (0);
}
