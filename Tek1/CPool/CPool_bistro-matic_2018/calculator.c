/*
** EPITECH PROJECT, 2018
** calculator
** File description:
** calculator for bistro-matic
*/

#include <stdlib.h>
#include "my.h"

char *calculator(char *first, char operator, char *second)
{
    if (operator == '+')
        return (infin_add(first, second));
    if (operator == '-')
        return (infin_sub(first, second));
    if (operator == '*')
        return (infin_mul(first, second));
    if (operator == '/')
        return (infin_div(first, second));
    if (operator == '%')
        return (infin_mod(first, second));
}
