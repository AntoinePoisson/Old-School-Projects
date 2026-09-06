/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_shell.h"

int check_operator(char const *str);
int check_operator_in_tree(char const *str, int ope);
int is_create_root_tree(variable_t *var);
int compare_charac_and_operator(char const *str, int i, int ope);

Test(is_initialisation_tree, is_initialisation_tree_null)
{
    cr_expect_eq(is_initialisation_tree(NULL), NULL);
}

Test(compare_charac_and_operator, compare_charac_and_operator)
{
    char *str = "str << aze";

    cr_expect_eq(compare_charac_and_operator(str, 4, 3), 2);
}

Test(check_operator, check_operator_double_left)
{
    char *str = "str << aze";

    cr_expect_eq(check_operator(str), 3);
}

Test(check_operator_in_tree, check_operator_in_tree_double_left)
{
    char *str = "str << aze";

    cr_expect_eq(check_operator_in_tree(str, 3), 1);
}

Test(check_operator, check_operator_double_right)
{
    char *str = "str >> aze";

    cr_expect_eq(check_operator(str), 5);
}

Test(check_operator, check_operator_simple_left)
{
    char *str = "str < aze";

    cr_expect_eq(check_operator(str), 4);
}
