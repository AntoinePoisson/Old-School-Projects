/*
** EPITECH PROJECT, 2018
** is_extension_my_two_my_rpn.c
** File description:
** this files contains of rpn
*/

#include "my.h"

void is_extension_my_rpm(pile *pile, int a)
{
    for (a; pile->first != NULL; a++) {
        if (result_rpn[a - 1] != ' ') {
            result_rpn[a] = ' ';
            a++;
        }
        result_rpn[a] = pop(pile);
    }
    result_rpn[a] = '\0';
}

int is_extension_my_rpm_two(pile *pile, int a)
{
    if (result_rpn[a - 1] != ' ') {
        result_rpn[a] = ' ';
        a++;
    }
    result_rpn[a] = pop(pile);
    a++;
    return (a);
}

int is_extension_my_rpm_three(pile *pile, int a, char const *str, int i)
{
    if (is_operator(result_rpn[a - 1]) == 1 || result_rpn[a - 1] == '(') {
        result_rpn[a] = ' ';
        a++;
    }
    result_rpn[a] = str[i];
    a++;
    if (!(str[i + 1] >= '0' && str[i + 1] <= '9')) {
        result_rpn[a] = ' ';
        a++;
    }
    return (a);
}
