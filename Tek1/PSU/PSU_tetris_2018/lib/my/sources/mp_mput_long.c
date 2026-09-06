/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mput_long.c
*/

#include "mprintf.h"

int mp_mput_long(long long nb)
{
    if (nb < 0) {
        nb *= -1;
        mp_mput('-');
    }
    if (nb > 9)
        mp_mput_long(nb / 10);
    mp_mput(nb % 10 + 48);
    return (0);
}
