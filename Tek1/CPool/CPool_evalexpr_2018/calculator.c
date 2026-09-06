/*
** EPITECH PROJECT, 2018
** calculator
** File description:
** calculator for eval_expr
*/

#include "my.h"

char *calculator(char *first_number, char operator, char *second_number)
{
    int first = my_getnbr(first_number);
    int second = my_getnbr(second_number);
    int result = 0;

    if (operator == '+')
        result = first + second;
    if (operator == '-')
        result = first - second;
    if (operator == '*')
        result = first * second;
    if (operator == '/')
        result = first / second;
    if (operator == '%')
        result = first % second;
    if (result < 0)
        return (my_itoa(-result, 1));
    return (my_itoa(result, 0));
}
