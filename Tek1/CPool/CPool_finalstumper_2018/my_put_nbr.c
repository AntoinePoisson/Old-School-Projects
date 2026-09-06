/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Display a number whit char while its an integer.
*/

#include "rush3.h"

int my_put_nbr(int nb)
{
    if (nb >= 10){
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        nb = nb + 48;
        write(1, &nb, 1);
    }
    return (0);
}
