/*
** EPITECH PROJECT, 2020
** add_mul.c
** File description:
** daytwo
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int result_sum = *first + *second;
    int result_product = *second * *first;

    *first = result_sum;
    *second = result_product;
}