/*
** EPITECH PROJECT, 2018
** test my rpn
** File description:
** unit test for my_rpn
*/

#include <criterion/criterion.h>

char *my_rpn(char const *str);

Test(my_rpn, test_basic_add)
{
    cr_expect_str_eq(my_rpn("1+99"), "1 99 +");
}

Test(my_rpn, test_basic_sub)
{
    cr_expect_str_eq(my_rpn("1000-1"), "1000 1 -");
}

Test(my_rpn, test_basic_mult)
{
    cr_expect_str_eq(my_rpn("1000*9"), "1000 9 *");
}

Test(my_rpn, test_basic_div)
{
    cr_expect_str_eq(my_rpn("42/2"), "42 2 /");
}

Test(my_rpn, test_basic_mod)
{
    cr_expect_str_eq(my_rpn("600%5"), "600 5 %");
}

Test(my_rpn, test_multiple_ops)
{
    cr_expect_str_eq(my_rpn("1+5/4"), "1 5 4 / +");
}

Test(my_rpn, test_parentheses)
{
    cr_expect_str_eq(my_rpn("(1+5)/4"), "1 5 + 4 / ");
}

Test(my_rpn, test_parentheses_2)
{
    cr_expect_str_eq(my_rpn("4*(1+4)"), "4 1 4 + * ");
}
