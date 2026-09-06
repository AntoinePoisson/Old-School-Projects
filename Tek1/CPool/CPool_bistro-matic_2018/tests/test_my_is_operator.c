/*
** EPITECH PROJECT, 2018
** test_my_is_operator
** File description:
** unit test for is_operator
*/

#include <criterion/criterion.h>

int is_operator(char c);

Test(is_operator, char_is_plus)
{
    cr_expect_eq(is_operator('+'), 1);
}

Test(is_operator, char_is_minus)
{
    cr_expect_eq(is_operator('-'), 1);
}

Test(is_operator, char_is_star)
{
    cr_expect_eq(is_operator('*'), 1);
}

Test(is_operator, char_is_slash)
{
    cr_expect_eq(is_operator('/'), 1);
}

Test(is_operator, char_is_modulo)
{
    cr_expect_eq(is_operator('%'), 1);
}

Test(is_operator, char_is_else)
{
    cr_expect_eq(is_operator('1'), 0);
}
