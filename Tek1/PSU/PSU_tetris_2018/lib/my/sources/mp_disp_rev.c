/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_disp_rev.c
*/

#include "mprintf.h"

int mp_disp_rev(char *str)
{
    int a = 0;
    int b = 0;
    char tmp[mp_mstrlen(str)];
    char d;

    for (b = 0; str[b] != 0; b++)
        tmp[b] = str[b];
    tmp[b] = '\0';
    for (a = 0; tmp[a + 1] != 0; a++);
    for (b = 0; a >= b; b++) {
        d = tmp[a];
        tmp[a] = tmp[b];
        tmp[b] = d;
        a -= 1;
    }
    mp_mputstr(tmp);
    return (0);
}
