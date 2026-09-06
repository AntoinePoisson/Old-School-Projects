/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** Day04 task01 my_swap
*/

void my_swap(int *a, int *b)
{
    int *c = 0;

    c = *a;
    *a = *b;
    *b = c;
}
