/*
** EPITECH PROJECT, 2020
** add.c
** File description:
** daytwo
*/

#include <stddef.h>
#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return (0);
    return ((a * 1.0) / (b * 1.0));
}

void exec_div(division_t *operation)
{
    decimale_op_t *decimal = NULL;
    integer_op_t *interger = NULL;

    if (operation && operation->div_type == INTEGER) {
        interger = operation->div_op;
        interger->res = integer_div(interger->a, interger->b);
    }
    if (operation && operation->div_type == DECIMALE) {
        decimal = operation->div_op;
        decimal->res = decimale_div(decimal->a, decimal->b);
    }
}