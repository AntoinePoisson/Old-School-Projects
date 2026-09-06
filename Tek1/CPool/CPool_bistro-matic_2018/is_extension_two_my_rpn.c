/*
** EPITECH PROJECT, 2018
** is_extension_my_two_my_rpn.c
** File description:
** this files contains of rpn
*/

#include <stddef.h>
#include "my.h"

int is_extension_my_rpm_four(int i, int a, pile_t *pile, char const *str)
{
    while (compare_precedence(str, pile, i) == 0)
        a = is_extension_my_rpm_two(pile, a, i, str);
    push(pile, str[i]);
    return (a);
}

char *is_extension_my_rpm(pile_t *pile, int a, int i, char const *str)
{
    for (a; pile->first != NULL; a++) {
        if (result_rpn[a - 1] != ' ') {
            result_rpn[a] = ' ';
            a++;
        }
        result_rpn[a] = pop(pile);
    }
    result_rpn[a] = '\0';
    return (result_rpn);
}

int is_extension_my_rpm_two(pile_t *pile, int a, int i, char const *str)
{
    if (result_rpn[a - 1] != ' ') {
        result_rpn[a] = ' ';
        a++;
    }
    result_rpn[a] = pop(pile);
    a++;
    return (a);
}

int is_extension_my_rpm_three(int a, char const *str, int i)
{
    if (is_operator(str[i - 1]) == 1 &&
        checkage_if_nbr_negative((i-1), str) == 0 && result_rpn[a - 1] != ' '
        && str[i] >= '0' && str[i] <= '9') {
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
