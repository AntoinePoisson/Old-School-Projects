/*
** EPITECH PROJECT, 2018
** is_extension
** File description:
** it's extension of infin_mul
*/

#include "my.h"

int size_equal(char *divided, char *divisor)
{
    for (int i = 0; i >= 0; i++) {
        if (divided[i] > divisor[i])
            return (0);
        if (divisor[i] > divided[i])
            return (1);
    }
}

int is_extension_carry(int *result, int *carry)
{
    *carry = 0;
    if (*result > 9) {
        *result = *result % 10;
        *carry = 1;
    }
    return (*result);
}
