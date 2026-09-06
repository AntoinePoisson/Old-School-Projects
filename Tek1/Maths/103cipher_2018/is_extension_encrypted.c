/*
** EPITECH PROJECT, 2018
** is_extension_encrypted
** File description:
** is_extension_encrypted
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/my.h"

int is_ext_product_matrix_two(int i, int i_two, int **message_2d,
struct math *math)
{
    int result = 0;

    result = message_2d[i][0] * math->key[0][i_two];
    result += message_2d[i][1] * math->key[1][i_two];
    result += message_2d[i][2] * math->key[2][i_two];
    result += message_2d[i][3] * math->key[3][i_two];
    return (result);
}

void display_tab_2d_int_2(int i_two, int size_key, int i, int size)
{
    if (!((i_two + 1) == size_key && (i + 1) == size))
        printf(" ");
}

void display_tab_2d_int(int **tab, int size, int size_key)
{
    printf("\nEncrypted message:\n");
    for (int i = 0; i < size; i++) {
        for (int i_two = 0; i_two < size_key; i_two++) {
            printf("%d", tab[i][i_two]);
            display_tab_2d_int_2(i_two, size_key, i, size);
        }
    }
    printf("\n");
}

int nbr_line_for_malloc(int size, struct math *math)
{
    int save = size;

    save = save % math->size_key;
    if (size <= math->size_key)
        return (1);
    size = size / math->size_key;
    if (save != 0)
        size++;
    return (size);
}

int **is_ext_atio(int *tab_int, int **tab_2d_int, int save, struct math *math)
{
    int a = 0;
    int size = nbr_line_for_malloc(save, math);
    for (int i = 0; i < size; i++) {
        tab_2d_int[i] = malloc(sizeof(int) * (math->size_key - 1));
        for (int i_two = 0; i_two < math->size_key; i_two++) {
            a = (a == save) ? -1 : a;
            tab_2d_int[i][i_two] = (a != -1) ? tab_int[a] : 0;
            a = (a != -1) ? (a + 1) : a;
        }
    }
    return (tab_2d_int);
}
