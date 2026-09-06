/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** converts an integer into a string
*/

#include "my.h"

char *my_itoa(int nbr, int neg)
{
    char *result;
    int save = nbr;
    int i = 0;
    int size_int;

    if (is_case_zero(nbr) != 0)
        return (result = "0");
    for (size_int = 1; save >= 1; save = save / 10, size_int = size_int * 10, i++);
    result = malloc(sizeof(char *) * (i + 1 + neg));
    size_int = size_int / 10;
    if (neg == 1)
        result[0] = '-';
    for (i = neg; size_int >= 1; size_int = size_int / 10, i++) {
        save = nbr / size_int;
        nbr = nbr - (save * size_int);
        result[i] = save + 48;
    }
    result[i] = '\0';
    return (result);
}
