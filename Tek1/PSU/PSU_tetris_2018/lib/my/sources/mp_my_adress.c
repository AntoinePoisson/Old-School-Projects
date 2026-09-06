/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_disp_adress.c
*/

#include "mprintf.h"

static int conv_adress(char array_nb[])
{
    for (int i = 0; array_nb[i]; i++)
        if (array_nb[i] > '9')
            array_nb[i] = array_nb[i] + 39;
    if (array_nb[0] == '0' && array_nb[1] == '\0') {
        mp_mputstr("(nil)");
        return (84);
    }
    write(1, "0x", 2);
    mp_mrevstr(array_nb);
    mp_mputstr(array_nb);
    return (0);
}

int mp_disp_adress(void const *point)
{
    long nb = (long)point;
    char arr_nb[15];
    int j;

    if (point == 0) {
        mp_mputstr("(nil)");
        return (84);
    }
    for (j = 0; nb / 16 > 0; j++) {
        arr_nb[j] = nb % 16 + 48;
        nb = nb / 16;
    }
    arr_nb[j] = nb + 48;
    arr_nb[j + 1] = 0;
    return (conv_adress(arr_nb));
}
