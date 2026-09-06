/*
** EPITECH PROJECT, 2018
** my_rpn
** File description:
** it's the reverse polish notation
*/

#include <stdlib.h>
#include "my.h"

int is_operator_pile(pile_t *pile, char result[], char const *str, int a)
{
    char reserve[my_strlen(str) * 2];
    int i = 0;

    for (i = 0; pile->first != NULL; i++)
        reserve[i] = pop(pile);
    reserve[i] = '\0';
    if (is_cas_no_parenthese(reserve, i) != 0)
        for (i; reserve[i] != '(' && i >= 0; i--)
            push(pile, reserve[i]);
    reserve[i] = '\0';
    a = is_extension_operator_pile(result, a, reserve, i);
    return (a);
}

int compare_precedence(char const *str, pile_t *pile, int i)
{
    char precedence[] = "(/%*-+";
    int a = 0;
    int position_pile = 0;
    int position_str = 0;

    if (is_top_pile(pile) == 'n' || is_top_pile(pile) == '('
        || is_top_pile(pile) == '\0')
        return (1);
    if (is_extension_compare_precedence_two(str, i, pile) == 1)
        return (0);
    for (a = 0;precedence[a] != '\0'; a++)
        if (precedence[a] == str[i])
            position_str = a;
    for (a = 0;precedence[a] != '\0'; a++)
        if (precedence[a] == is_top_pile(pile))
            position_pile = a;
    if (position_pile > position_str)
        return (1);
    return (0);
}

int checkage_if_nbr_negative(int i, char const *str)
{
    if (str[i] == '-' && is_operator(str[i - 1]) == 1 && str[i + 1] >= '0' &&
        str[i + 1] <= '9' || str[i] == '-' && str[i - 1] == '(' &&
        str[i + 1] >= '0' && str[i + 1] <= '9' || i == 0 && str[i] == '-' ||
        str[i] == '-' && str[i - 1] == '(' && str[i + 1] == ')')
        return (1);
    return (0);
}

int is_case_nbr_negative(int a, int i)
{
    if (is_operator(result_rpn[a - 1]) == 1 || a != 0 &&
        result_rpn[a - 1] != ' ') {
        result_rpn[a] = ' ';
        a++;
    }
    result_rpn[a] = '-';
    a++;
    i++;
    return (a);
}

char *my_rpn(char const *str)
{
    int i = 0;
    int a = 0;
    pile_t *pile = malloc(sizeof(*pile));

    pile->first = NULL;
    for (i = 0; str[i] != '\0'; i++) {
        if (checkage_if_nbr_negative(i, str) == 1) {
            a = is_case_nbr_negative(a, i);
            i++;
        }
        if (str[i] >= '0' && str[i] <= '9')
            a = is_extension_my_rpm_three(a, str, i);
        if (is_operator(str[i]) == 1 || str[i] == '(')
            a = is_extension_my_rpm_four(i, a, pile, str);
        if (str[i] == ')')
            a = is_operator_pile(pile, result_rpn, str, a);
    }
    return (is_extension_my_rpm(pile, a, i, str));
}
