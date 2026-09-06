/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** my put nbr base
*/

#include "my_put_nbr_base.h"

int my_put_nbr_base(int nb, char *base)
{
    int quotient = 0;
    int reste = 0;
    int base_size = my_strlen(base);

    if (nb >= 0) {
        quotient = nb % base_size;
        reste = nb / base_size;
        if (reste != 0)
            my_put_nbr_base(reste, base);
        if (quotient <= 9)
            my_putchar(quotient + '0');
        if (base[10] == 'A' && quotient > 9)
            my_putchar(quotient + 55);
        if (base[10] == 'a' && quotient > 9)
            my_putchar(quotient + 87);
    }
    if (nb < 0)
        my_put_nbr_base(-nb, base);
    return (0);
}
