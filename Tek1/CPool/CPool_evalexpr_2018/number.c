/*
** EPITECH PROJECT, 2018
** number
** File description:
** number of evalexpr
*/

#include "my.h"

int number(char **str)
{
    int i = 0;
    int nbr = 0;

    for (int a = 0; str[1][i] >= '0' && str[1][i] <= '9'; i += 1) {
        if (str[1][i] < '0' || str[1][i] > '9')
            return (0);
        nbr = (nbr * 10) + (str[1][i] - '0');
        a += 1;
        if (a > 10)
            return (0);
    }
    return (nbr);
}
