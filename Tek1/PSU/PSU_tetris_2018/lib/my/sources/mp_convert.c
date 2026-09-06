/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_convert_nb.c
*/

#include "mprintf.h"

static void itohexa(char arr_nb[][12], char c)
{
    if (c == 'x') {
        for (int i = 0; (*arr_nb)[i]; i++)
            if ((*arr_nb)[i] > '9')
                (*arr_nb)[i] = (*arr_nb)[i] + 39;
    } else {
        for (int i = 0; (*arr_nb)[i]; i++)
            if ((*arr_nb[i]) > '9')
                (*arr_nb)[i] = (*arr_nb)[i] + 7;
    }
}

int mp_convert_nb(arg_t arg)
{
    int j;
    char arr_nb[12];

    for (j = 0; arg.nb / arg.value > 0; j++) {
        arr_nb[j] = arg.nb % arg.value + 48;
        arg.nb = arg.nb / arg.value;
    }
    arr_nb[j] = arg.nb + 48;
    arr_nb[j + 1] = 0;
    if (arg.value == 16)
        itohexa(&arr_nb, arg.c);
    mp_mrevstr(arr_nb);
    mp_mputstr(arr_nb);
    return (0);
}
