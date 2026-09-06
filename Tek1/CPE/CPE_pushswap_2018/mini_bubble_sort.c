/*
** EPITECH PROJECT, 2018
** bubble_sort
** File description:
** bubble_sort
*/

#include "my_lib.h"
char *compare_size(char *size_max, char *element);

char *bubble_sort_array(char *array[], int ac, char *size_max, int *sort)
{
    for (int i = 1; i <= ac; i++) {
        if (*sort == 1 && i < ac && my_getnbr(array[i]) >
            my_getnbr(array[i + 1]))
            *sort = 0;
        size_max = compare_size(size_max, array[i]);
    }
    return (size_max);
}