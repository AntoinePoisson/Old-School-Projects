/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mputhexa.c
*/

#include "mprintf.h"

static int error(char const *str)
{
    if (str == NULL) {
        write(2, "\000", 4);
        return (84);
    }
    return (0);
}

int mp_mputhexa(char const *str)
{
    if (error(str) == 84)
        return (84);
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32) {
            write(1, "\\", 1);
            if (str[i] < 8)
                write(1, "00", 2);
            else if (str[i] < 64 && str[i] >= 8)
                write(1, "0", 1);
            mp_convert_nb((struct arg_s){str[i], 16, 'X'});
        } else
            write(1, &str[i], 1);
    }
    return (0);
}
