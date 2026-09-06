/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** d3 function that displays the number given as a parameter
*/

#include "my_unsigned_putnbr.h"

unsigned int my_unsigned_putnbr(int nb)
{
    int quotient = 0;
    int reste = 0;

    if (nb >= 0) {
        quotient = nb % 10;
        reste = nb / 10;
        if (reste != 0)
            my_put_nbr(reste);
        my_putchar(quotient + '0');
    }
    if (nb < 0)
        my_unsigned_putnbr(-nb);
    return (0);
}
