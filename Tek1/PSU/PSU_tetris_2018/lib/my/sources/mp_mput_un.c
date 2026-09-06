/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mput_un.c
*/

#include "mprintf.h"

int mp_mput_un(unsigned int nb)
{
    if (nb > 9)
        mp_mput_un(nb / 10);
    mp_mput(nb % 10 + 48);
    return (0);
}
