/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** Write a function that swaps the content of two integers.
*/

void my_swap(int *a, int *b)
{
    int *c = 0;

    c = *a;
    *a = *b;
    *b = c;
}
