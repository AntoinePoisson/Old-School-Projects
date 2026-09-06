/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** Reproduce the behavior of the my_strcmp function of n case.
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    if (!s1 || !s2)
        return (-1);
    for (i = 0; s1[i] && s2[i] && i != n; i++)
        if (s1[i] ^ s2[i])
            return (-1);
    return (i != n) ? (-1) : (0);
}
