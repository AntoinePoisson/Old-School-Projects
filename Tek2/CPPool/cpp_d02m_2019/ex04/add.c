/*
** EPITECH PROJECT, 2020
** add.c
** File description:
** daytwo
*/

#include <math.h>
#include <stddef.h>
#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    int value_a = (a < 0) ? a * -1 : a;
    int value_b = (b < 0) ? b * -1 : b;

    return (value_a + value_b);
}

void exec_add(addition_t * operation)
{
    if (operation && operation->add_type == NORMAL) {
        operation->add_op.res =
            normal_add(operation->add_op.a, operation->add_op.b);
    }
    if (operation && operation->add_type == ABSOLUTE) {
        operation->add_op.res =
            absolute_add(operation->add_op.a, operation->add_op.b);
    }
}