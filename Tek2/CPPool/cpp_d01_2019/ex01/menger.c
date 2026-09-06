/*
** EPITECH PROJECT, 2020
** my
** File description:
** all header of my lib
*/

#include <stdio.h>

void menger(int level, int size, int abs, int ord)
{
    size /= 3;
    printf("%03d %03d %03d\n", size, abs + size, ord + size);
    if (level <= 1)
        return;
    menger(level - 1, size, abs, ord);
    menger(level - 1, size, abs, ord + size);
    menger(level - 1, size, abs, ord + 2 * size);
    menger(level - 1, size, abs + size, ord);
    menger(level - 1, size, abs + size, ord + size * 2);
    menger(level - 1, size, abs + size * 2, ord);
    menger(level - 1, size, abs + size * 2, ord + size);
    menger(level - 1, size, abs + size * 2, ord + size * 2);
}