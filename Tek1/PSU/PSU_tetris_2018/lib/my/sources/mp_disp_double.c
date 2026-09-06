/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mput_double.c
*/

#include "mprintf.h"

static void decimal_part(double nb, int nb_int)
{
    int i = 0;

    if (nb != 0.000000) {
        for (; nb < 0.1; i++) {
            write(1, "0", 1);
            nb *= 10;
        }
        nb_int = nb * 1000001;
        for (; i > 0; i--)
            nb_int /= 10;
        mp_mput_nbr(nb_int);
    } else
        write(1, "000000", 6);
}

int mp_mput_double(double nb)
{
    int nb_int = 0;

    if (nb < 0) {
        nb = nb * -1;
        write(1, "-", 1);
    }
    mp_mput_nbr(nb_int = nb);
    write(1, ".", 1);
    nb -= nb_int;
    decimal_part(nb, nb_int);
    return (0);
}
