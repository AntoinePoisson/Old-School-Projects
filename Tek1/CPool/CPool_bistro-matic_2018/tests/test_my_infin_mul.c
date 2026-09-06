/*
** EPITECH PROJECT, 2018
** test my infin_mul
** File description:
** unit test for infin_mul
*/

#include <criterion/criterion.h>

char *infin_mul(char *first, char *second);

Test(infin_mul, test_basic_mult)
{
    char one[] = "1";
    char two[] = "1";

    cr_expect_str_eq(infin_mul(one, two), "1");
}

Test(infin_mul, test_mult_divided_zero)
{
    char one[] = "0";
    char two[] = "5";

    cr_expect_str_eq(infin_mul(one, two), "0");
}

Test(infin_mul, test_mult_divisor_zero)
{
    char one[] = "5";
    char two[] = "0";

    cr_expect_str_eq(infin_mul(one, two), "0");
}

Test(infin_mul, test_mult_both_zero)
{
    char one[] = "0";
    char two[] = "0";

    cr_expect_str_eq(infin_mul(one, two), "0");
}

Test(infin_mul, test_mult_minus_zero)
{
    char one[] = "-0";
    char two[] = "-0";

    cr_expect_str_eq(infin_mul(one, two), "0");
}

Test(infin_mul, test_mult_carry)
{
    char one[] = "2";
    char two[] = "5";

    cr_expect_str_eq(infin_mul(one, two), "10");
}

Test(infin_mul, test_mult_divided_neg)
{
    char one[] = "-2";
    char two[] = "5";

    cr_expect_str_eq(infin_mul(one, two), "-10");
}

Test(infin_mul, test_mult_double_neg)
{
    char one[] = "-2";
    char two[] = "-5";

    cr_expect_str_eq(infin_mul(one, two), "10");
}
