/*
** EPITECH PROJECT, 2020
** tab_to_2dtab.c
** File description:
** daytwo
*/

#include <stdlib.h>

void tab_to_2dtab(const int * tab, int length, int width, int ***res)
{
    int **result = malloc(sizeof(int *) * (length + 1));
    int offset = 0;
    int i = 0;

    if (!result)
        return;
    for (; i < length; i++) {
        result[i] = malloc(sizeof(int) * (width + 1));
        if (!result[i])
            return;
        for (int i_two = 0; i_two < width; i_two++, offset++) {
            result[i][i_two] = tab[offset];
        }
    }
    *res = result;
}