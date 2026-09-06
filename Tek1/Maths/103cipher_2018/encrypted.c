/*
** EPITECH PROJECT, 2018
** encrypted
** File description:
** encrypted
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int **converted_char_to_int(char *av[], int *size_tab, struct math *math)
{
    int size = my_strlen(av[1]);
    int save = size;
    int *tab_int = malloc(sizeof(int) * size);
    int **tab_2d_int = NULL;

    for (int i = 0; i < size; i++)
        tab_int[i] = av[1][i];
    size = nbr_line_for_malloc(size, math);
    tab_2d_int = malloc(sizeof(int *) * (size));
    tab_2d_int = is_ext_atio(tab_int, tab_2d_int, save, math);
    *size_tab = size;
    free(tab_int);
    return (tab_2d_int);
}

int is_ext_product_matrix(int i, int i_two, int **message_2d,
struct math *math)
{
    int result = 0;

    result = message_2d[i][0] * math->key[0][i_two];
    result += message_2d[i][1] * math->key[1][i_two];
    result +=message_2d[i][2] * math->key[2][i_two];
    return (result);
}

void product_matrix(int **message_2d, struct math *math, int size_message_row,
int size_key)
{
    int **tab_resul = malloc(sizeof(int *) * size_message_row);
    int result = 0;

    for (int i = 0; i < size_message_row; i++) {
        tab_resul[i] = malloc(sizeof(int) * (math->size_key - 1));
        for (int i_two = 0; i_two < math->size_key; i_two++) {
            result = (size_key == 4) ?
        is_ext_product_matrix_two(i, i_two, message_2d, math) : result;
            result = (size_key == 3) ?
        is_ext_product_matrix(i, i_two, message_2d, math) : result;
            result = (size_key == 2) ? (message_2d[i][0] * math->key[0][i_two] +
        message_2d[i][1] * math->key[1][i_two]) : result;
            result = (size_key == 1) ?
        (message_2d[i][0] * math->key[0][i_two]) : result;
            tab_resul[i][i_two] = result;
        }
    }
    display_tab_2d_int(tab_resul, size_message_row, size_key);
}

void encrypted(char *av[], struct math *math, int size_key)
{
    int size_message_row = 0;
    int **message_2d = converted_char_to_int(av, &size_message_row, math);

    product_matrix(message_2d, math, size_message_row, size_key);
}
