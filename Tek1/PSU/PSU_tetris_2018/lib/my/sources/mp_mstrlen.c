/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mstrlen.c
*/

int mp_mstrlen(char const *s)
{
    int i;

    for (i = 0; s[i] != 0; i++);
    return (i);
}
