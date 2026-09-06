/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mstrncmp.c
*/

#include "mprintf.h"

static void disp_format(int plus, int count, char flag)
{
    if (plus != 0)
        write(1, "+", 1);
    if (count != 0) {
        if (flag == 'x')
            write(1, "0x", 2);
        if (flag == 'X')
            write(1, "0X", 2);
        if (flag == 'o')
            write(1, "0", 1);
    }
}

int mp_mstrcmp(char const *s1, char const *s2)
{
    int i = 0;
    char stock[100];
    int count = 0;
    int plus = 0;

    stock[0] = s2[0];
    stock[1] = s2[1];
    for (int j = 2; i < j; i++) {
        plus += (s1[i] == '+') ? 1 : 0;
        count += (s1[i] == '#') ? 1 : 0;
        if (s1[i] == '+' || s1[i] == ' ' || s1[i] == '0' || s1[i] == '#') {
            stock[i + 1] = stock[i];
            stock[i] = s1[i];
            j += 1;
        } else if (s1[i] != stock[i])
            return (-1);
    }
    disp_format(plus, count, s1[i - 1]);
    return (0);
}
