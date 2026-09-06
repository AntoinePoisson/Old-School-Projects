/*
** EPITECH PROJECT, 2019
** navy
** File description:
** lib.c
*/

#include "navy.h"

void mput(char c)
{
    write(1, &c, 1);
}

void mputstr(char const *s)
{
    for (int i = 0; s[i] != 0; i++)
        write(1, &s[i], 1);
}

int mstrcmp(char const *s1, char const *s2)
{
    int i;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    for (i = 0; s1[i] != 0; i++)
        if (s1[i] != s2[i])
            return (-1);
    if (s1[i] != s2[i])
        return (-1);
    return (0);
}

int mput_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        mput('-');
    }
    if (nb > 9)
        mput_nbr(nb/10);
    mput(nb%10 + 48);
    return (0);
}

int mgetnbr(char const *s)
{
    int nb = 0;
    int i = 0;

    if (s[0] == '-')
        i += 1;
    for ( ; s[i] != 0; i++) {
        if (!(s[i] >= 48 && s[i] <= 57))
            break;
        nb = nb * 10 + s[i] - 48;
    }
    if (s[0] == '-')
        return (-nb);
    return (nb);
}
