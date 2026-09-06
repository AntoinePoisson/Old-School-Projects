/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** core of evalexpr
*/

#include "my.h"

char *array_rewriter(char **array, char current_operator, char *result)
{
    int a;
    int index_to_rewrite;
    char *first_number;
    char *second_number;

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

int array_manager(char **array, char *str_rpn)
{
    char current_operator;
    int oper_count = 0;
    char *result;

    for (int j = 0; str_rpn[j] != '\0'; j++)
        if (is_operator(str_rpn[j]) == 1)
            oper_count++;
    for (int i = 0; i < oper_count; i++) {
        result = array_rewriter(array, current_operator, result);
    }
    return (my_getnbr(result));
}

int eval_expr(char const *str)
{
    char **array;
    char *str_rpn;

    str_rpn = malloc(sizeof(char) * (my_strlen(str) * 2));
    str_rpn = my_rpn(str);
    array = malloc(sizeof(char *) * (word_count(str_rpn) + 1));
    array = my_str_to_word_array(str_rpn);
    return (array_manager(array, str_rpn));
}
