/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** D6, Reproduce the behavior of the my_strcmp function of n case.
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    char a = '\0';

    if ((s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL))
        return (-1);
    if (s1 == NULL && s2 == NULL)
        return (a);
    while (s1[i] == s2[i] && n > 0) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
        n--;
    }
    a = s1[i] - s2[i];
    return (a);
}
