/*
** EPITECH PROJECT, 2019
** navy
** File description:
** lib2.c
*/

#include "navy.h"

int mstrlen(char const *s)
{
    int y;

    if (s == NULL)
        return (0);
    for (y = 0; s[y] != 0; y++);
    return (y);
}

char *mrevstr(char *s)
{
    int a, b;
    char c;

    for (a = 0; s[a + 1] != 0; a++);
    for (b = 0; a >= b; b++, a--) {
        c = s[a];
        s[a] = s[b];
        s[b] = c;
    }
    return (s);
}

void display_map(char **map)
{
    for (int a = 0; map[a] != NULL; a++) {
        mputstr(map[a]);
        mput('\n');
    }
    mput('\n');
}

int misnum(char const *str)
{
    int i = 0;

    if (str[0] == '-')
        i += 1;
    for ( ; str[i] != 0; i++)
        if (!(str[i] >= 48 && str[i] <= 57))
            return (-1);
    return (0);
}
