/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** core of evalexpr
*/

#include <stdlib.h>
#include "my.h"

char *array_rewriter(char **array, char current_operator, char *result)
{
    int a = 0;
    int index_to_rewrite = 0;
    char *first_number = NULL;
    char *second_number = NULL;

    for (a = 0; is_operator(array[a][0]) == 0 || array[a][1] > 47; a++);
    current_operator = array[a][0];
    index_to_rewrite = a;
    for (--a; array[a][0] == ' '; a--);
    second_number = array[a];
    array[a] = " ";
    for (--a; array[a][0] == ' '; a--);
    first_number = array[a];
    array[a] = " ";
    result = calculator(first_number, current_operator, second_number);
    array[index_to_rewrite] = result;
    return (result);
}

char *array_manager(char **array, char *str_rpn)
{
    char current_operator = 0;
    int oper_count = 0;
    char *result = NULL;

    for (int j = 0; str_rpn[j] != '\0'; j++)
        if ((is_operator(str_rpn[j]) == 1 && str_rpn[j + 1] == ' ')
            || (is_operator(str_rpn[j]) == 1 && str_rpn[j + 1] == '\0'))
            oper_count++;
    for (int i = 0; i < oper_count; i++)
        result = array_rewriter(array, current_operator, result);
    return (result);
}

int scaning_of_rpn(char *str_rpn)
{
    for (int i = 0; str_rpn[i] != '\0'; i++)
        if (str_rpn[i] == '(' || str_rpn[i] == ')') {
            my_putstr(NOT_HANDLED);
            exit(EXIT_PARENTH);
        }
    return (0);
}

char *eval_expr(char const *base, char const *ops,
                char const *expr, unsigned int size)
{
    char **array = NULL;
    char *str_rpn = NULL;
    char *str_rework = NULL;

    str_rework = malloc(sizeof(char) * (my_strlen(expr) * 2));
    str_rpn = malloc(sizeof(char) * (my_strlen(expr) * 2));
    str_rework = rework_string(expr);
    str_rpn = my_rpn(str_rework);
    scaning_of_rpn(str_rpn);
    array = malloc(sizeof(char *) * (word_count(str_rpn) + 1));
    array = my_str_to_word_array(str_rpn);
    return (array_manager(array, str_rpn));
}
