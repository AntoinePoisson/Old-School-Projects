/*
** EPITECH PROJECT, 2018
** test my calculator
** File description:
** unit test for calculator
*/

#include <criterion/criterion.h>

char *calculator(char *first_number, char operator, char *second_number);

Test(calculator, test_basic_add)
{
    char one[] = "1";
    char two[] = "1";

    cr_expect_str_eq(calculator(one, '+', two), "2");
}

Test(calculator, test_add_from_neg)
{
    char one[] = "-5";
    char two[] = "10";

    cr_expect_str_eq(calculator(one, '+', two), "5");
}

Test(calculator, test_basic_minus)
{
    char one[] = "4";
    char two[] = "2";

    cr_expect_str_eq(calculator(one, '-', two), "2");
}

Test(calculator, test_soustract_neg)
{
    char one[] = "-4";
    char two[] = "6";

    cr_expect_str_eq(calculator(one, '-', two), "-10");
}

Test(calculator, test_soustract_double_neg)
{
    char one[] = "-4";
    char two[] = "-2";

    cr_expect_str_eq(calculator(one, '-', two), "-2");
}

Test(calculator, test_minus_to_pos)
{
    char one[] = "-4";
    char two[] = "-6";

    cr_expect_str_eq(calculator(one, '-', two), "2");
}

Test(calculator, test_minus_to_0)
{
    char one[] = "5";
    char two[] = "5";

    cr_expect_str_eq(calculator(one, '-', two), "0");
}

Test(calculator, test_minus_to_neg)
{
    char one[] = "5";
    char two[] = "8";

    cr_expect_str_eq(calculator(one, '-', two), "-3");
}

Test(calculator, test_basic_mult)
{
    char one[] = "1";
    char two[] = "1";

    cr_expect_str_eq(calculator(one, '*', two), "1");
}

Test(calculator, test_mult)
{
    char one[] = "2";
    char two[] = "5";

    cr_expect_str_eq(calculator(one, '*', two), "10");
}

Test(calculator, test_mod)
{
    char one[] = "11";
    char two[] = "10";

    cr_expect_str_eq(calculator(one, '%', two), "1");
}
