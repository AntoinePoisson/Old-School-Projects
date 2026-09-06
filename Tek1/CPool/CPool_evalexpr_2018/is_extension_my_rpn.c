/*
** EPITECH PROJECT, 2018
** is_extension_my_rpn
** File description:
** this files contains of rpn
*/

#include "my.h"

int is_cas_no_parenthese(char reserve[], int i)
{
    int parenth = 0;

    for (int a = 0; a <= i; a++)
        if (reserve[a] == '(')
            parenth++;
    if (parenth == 0)
        return (0);
    return (1);
}

int is_extension_two_operator(char reserve[], int i, int a, char result[])
{
    reserve[i] = ' ';
    if (result[a - 1] != ' ') {
        result[a] = ' ';
        a++;
    }
    return (a);
}

int is_extension_operator_pile(char result[], int a, char reserve[], int i)
{
    char operator[] = "/%*-+";
    int find = 1;

    for (int replacement = 0; operator[replacement] != '\0'; replacement++) {
        for (i = 0; find > 0; i++) {
            if (reserve[i] == '\0') {
                i = 0;
                find = 0;
            }
            if (reserve[i] == operator[replacement]) {
                a = is_extension_two_operator(reserve, i, a, result);
                result[a] = operator[replacement];
                a++;
                find++;
            }
        }
        find = 1;
    }
    return (a);
}

int is_extension_compare_precedence_two(char const *str, int i)
{
    if (str[i] == '+' || str[i] == '-')
        return (1);
    if (str[i] == '/' || str[i] == '%')
        return (1);
}

int is_extension_compare_precedence(char const *str, pile *pile, int i)
{
    if (str[i] == '+' && is_top_pile(pile) == '-'|| str[i] == '-'
        && is_top_pile(pile) == '+')
        return (0);
    if (str[i] == '/' && is_top_pile(pile) == '%'|| str[i] == '%'
        && is_top_pile(pile) == '/')
        return (0);
    return (1);
}
