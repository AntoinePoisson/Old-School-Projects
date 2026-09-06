/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** sort_array.c
*/

#include "lem_in.h"

static int len(int *line)
{
    int a;

    for (a = 0; line[a] != -1; a++);
    return (a);
}

static int count_lines(int **arr)
{
    int nb;

    for (nb = 0; arr[nb][0] != -1; nb++);
    return (nb);
}

static int not_used(int b, int *stack)
{
    for (int x = 0; stack[x] != -1; x++)
        if (stack[x] == b)
            return (-1);
    return (0);
}

int **sort_array(int **arr)
{
    int **new = malloc(sizeof(int *) * (count_lines(arr) + 1));
    int stack[count_lines(arr) + 1];
    int a, c, b, i = 0;

    stack[0] = -1;
    for (a = 0; a != count_lines(arr); a++) {
        for (b = 0; not_used(b, stack) == -1; b++);
        for (i = b; arr[b][0] != -1; b++)
            i = (not_used(b, stack) == 0 && len(arr[b]) < len(arr[i])) ? b : i;
        new[a] = malloc(sizeof(int) * (len(arr[i]) + 1));
        for (c = 0; arr[i][c] != -1; c++)
            new[a][c] = arr[i][c];
        new[a][c] = -1;
        stack[a] = i;
        stack[a + 1] = -1;
    }
    new[a] = malloc(sizeof(int));
    new[a][0] = -1;
    return (new);
}
