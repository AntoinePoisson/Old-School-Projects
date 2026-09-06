/*
** EPITECH PROJECT, 2019
** navy
** File description:
** binary.c
*/

#include "navy.h"

int itobin(int nb)
{
    int j;
    char arr_nb[12];

    for (j = 0; nb / 2 > 0; j++) {
        arr_nb[j] = nb % 2 + 48;
        nb = nb / 2;
    }
    arr_nb[j] = nb + 48;
    arr_nb[j + 1] = 0;
    mrevstr(arr_nb);
    return (mgetnbr(arr_nb));
}

int power(int nb, int p)
{
    int tmp = nb;

    if (p == 0)
        return (1);
    tmp = nb * power(nb, p - 1);
    return (tmp);
}

int bintoi(int nb)
{
    char arr[9];
    int res = 0;

    arr[8] = '\0';
    for (int i = 0; i != 8; i++) {
        arr[i] = nb % 10 + 48;
        nb /= 10;
    }
    for (int i = 0; i != 8; i++)
        res += (arr[i] - 48) * power(2, i);
    return (res);
}
