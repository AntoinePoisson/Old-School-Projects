/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** Day05 task04 my_compute_power_rec
*/

#include <limits.h>

int my_compute_power_rec(int nb, int p)
{
    int b;

    if (nb * nb > INT_MAX)
        return (0);
    if (p <= 1) {
        if (p == 0)
            return (1);
        if (p < 0)
            return (0);
        if (p == 1)
            return (nb);
    } else {
        b = nb * my_compute_power_rec(nb, p - 1);
        return (b);
    }
}
