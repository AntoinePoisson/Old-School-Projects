/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** D4, function that sorts an integer array in ascending order
*/

#include <stddef.h>

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int a = 0;
    int j = 0;

    for (a = 0; a < size; a++) {
        for (j = a; j < size; j++) {
            if (tab[a] > tab[j]) {
                i = tab[j];
                tab[j] = tab[a];
                tab[a] = i;
            }
        }
    }
    return;
}
