/*
** EPITECH PROJECT, 2018
** error_check
** File description:
** checks errors
*/

#include <stdlib.h>
#include "my.h"

void check_unary_op(char *expr)
{
    if (my_str_isnum(expr) == 1) {
        my_putstr(expr);
        exit(EXIT_SUCCESS);
    }
    if (my_str_isnum_or_parenth(expr) == 1) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_EXPR);
    }
}

void check_base(char const *base)
{
    if (my_strlen(base) != 10) {
        my_putstr(NOT_HANDLED);
        exit(EXIT_BASE);
    }
    for (int i = 0; base[i] != '\0'; i++)
        if (is_operator(base[i]) == 1) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
}

void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i] != '\0'; i++)
        if (is_operator(ops[i]) == 0 && ops[i] != '(' && ops[i] != ')') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
}

void check_arg_in_string(char *str, char char_to_test)
{
    int symbole_found = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == char_to_test)
            symbole_found++;
    if (symbole_found > 1) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(MULTIPLE_SYM);
    }
}

void check_multiple_symboles(char *base, char *ops)
{
    char char_to_test = '!';

    for (char_to_test = '!'; char_to_test < 127; char_to_test++)
        check_arg_in_string(base, char_to_test);
    for (char_to_test = '!'; char_to_test < 127; char_to_test++)
        check_arg_in_string(ops, char_to_test);
}
