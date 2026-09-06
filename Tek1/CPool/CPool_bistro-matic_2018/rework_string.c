/*
** EPITECH PROJECT, 2018
** rework_string
** File description:
** management errors and negative before parenthese
*/

#include <stdlib.h>
#include "my.h"

int first_checkage_errors(char const str[])
{
    int i = 0;
    int count_parent_open = 0;
    int count_parent_close = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' ||
              is_operator(str[i]) == 1 || str[i] == '(' || str[i] == ')')) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_PARENTH);
        }
        if (str[i] == ')')
            count_parent_close++;
        if (str[i] == '(')
            count_parent_open++;
    }
    if (count_parent_open != count_parent_close) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(OP_OPEN_PARENT_IDX);
    }
    return (0);
}

int is_extension_rework(char const str[], int i, int symb_rev_parenth)
{
    if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '(') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(OP_OPEN_PARENT_IDX);
    }
    if (str[i] == '-' && str[i + 1] == '(')
        symb_rev_parenth++;
    if (symb_rev_parenth > 0 && str[i] == '(' && str[i - 1] != '-')
        symb_rev_parenth++;
    if (str[i] == ')' && symb_rev_parenth != 0)
        symb_rev_parenth--;
    return (symb_rev_parenth);
}

char *is_extension_rework_two(char const str[], int *i, int *a, char *result)
{
    if (result[*a - 1] == '-' && is_operator(result[*a - 2]) == 1)
        *a -= 1;
    if (!(str[*i] >= '0' && str[*i] <= '9' &&
          str[*i - 1] >= '0' && str[*i - 1] <= '9')) {
        result[*a] = '-';
        *a += 1;
    }
    result[*a] = str[*i];
    return (result);
}

char *rework_string(char const str[])
{
    int i = 0;
    int symb_rev_parenth = 0;
    char *result = malloc(sizeof(char) * (my_strlen(str) * 2 + 1));
    int a = 0;

    first_checkage_errors(str);
    for (i = 0; str[i] != '\0'; i++, a++) {
        symb_rev_parenth = is_extension_rework(str, i, symb_rev_parenth);
        if (!(str[i] == '-' && str[i + 1] == '(')) {
            if (str[i] >= '0' && str[i] <= '9' && (symb_rev_parenth > 0))
                is_extension_rework_two(str, &i, &a, result);
            else
                result[a] = str[i];
        }
        else
            a--;
    }
    result[a] = '\0';
    return (result);
}
