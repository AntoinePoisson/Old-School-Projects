/*
** EPITECH PROJECT, 2018
** test my eval expr
** File description:
** unit test for eval expr
*/

#include <criterion/criterion.h>

char *eval_expr(char const *base, char const *ops,
                char const *expr, unsigned int size);

Test(eval_expr, test_basic)
{
    char expr[] = "3+6";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 3);

    cr_expect_str_eq(result, "9");
}

Test(eval_expr, test_add)
{
    char expr[] = "3+9";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 3);

    cr_expect_str_eq(result, "12");
}

Test(eval_expr, test_big_add)
{
    char expr[] = "63+7+8+10+2+10+100-100";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 22);

    cr_expect_str_eq(result, "100");
}

Test(eval_expr, test_basic_mult)
{
    char expr[] = "3*2*10";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 3);

    cr_expect_str_eq(result, "60");
}

Test(eval_expr, test_big_mult)
{
    char expr[] = "3*200*3";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 7);

    cr_expect_str_eq(result, "1800");
}

Test(eval_expr, test_basic_div)
{
    char expr[] = "6/2";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 3);

    cr_expect_str_eq(result, "3");
}

Test(eval_expr, test_big_div)
{
    char expr[] = "100/2/25";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 8);

    cr_expect_str_eq(result, "2");
}

Test(eval_expr, test_basic_modulo)
{
    char expr[] = "10%9";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 4);

    cr_expect_str_eq(result, "1");
}

Test(eval_expr, test_big_mod)
{
    char expr[] = "301%2";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 5);

    cr_expect_str_eq(result, "1");
}

Test(eval_expr, test_advanced_calculus_2)
{
    char expr[] = "3+6";
    char *result = eval_expr("0123456789", "()+-*/%", expr, 3);

    cr_expect_str_eq(result, "9");
}
