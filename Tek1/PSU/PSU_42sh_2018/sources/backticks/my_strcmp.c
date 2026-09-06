/*
** EPITECH PROJECT, 2018
** Day 05
** File description:
** Task 05
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (1);
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i = i + 1;
    }
    return (s1[i] - s2[i]);
}
