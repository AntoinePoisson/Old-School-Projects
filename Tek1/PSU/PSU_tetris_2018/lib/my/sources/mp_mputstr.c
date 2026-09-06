/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mputstr.c
*/

#include <unistd.h>

int mp_mputstr(char const *s)
{
    for (int i = 0; s[i] != 0; i++)
        write(1, &s[i], 1);
    return (0);
}
