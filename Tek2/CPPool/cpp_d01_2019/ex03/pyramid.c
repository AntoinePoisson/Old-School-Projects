/*
** EPITECH PROJECT, 2020
** pyramid
** File description:
** pyramid
*/

#include <stdlib.h>
#include <stdio.h>

static int find_path(const int **map, int i, int i_two, int size)
{
    int left = 0;
    int right = 0;

    if (i + 1 <= size) {
            left = find_path(map, i + 1, i_two, size);
            right = find_path(map, i + 1, i_two + 1, size);
    } else {
        return (map[i][i_two]);
    }
    if (left > right)
        return (right + map[i][i_two]);
    return (left + map[i][i_two]);
}

int pyramid_path(int size, const int **map)
{
    return (find_path(map, 0, 0, size - 1));
}