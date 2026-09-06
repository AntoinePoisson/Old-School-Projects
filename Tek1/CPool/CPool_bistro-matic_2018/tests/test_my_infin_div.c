/*
** EPITECH PROJECT, 2018
** test my infin div
** File description:
** unit test for infin div
*/

#include <criterion/criterion.h>

char *infin_div(char *divided, char* divisor);

Test(infin_div, test_divisor_neg)
{
    char one[] = "10";
    char two[] = "-5";

    cr_expect_str_eq(infin_div(one, two), "-2");
}

Test(infin_div, test_div_both_neg)
{
    char one[] = "-100";
    char two[] = "-5";

    cr_expect_str_eq(infin_div(one, two), "20");
}

Test(infin_div, test_div_zero)
{
    char one[] = "0";
    char two[] = "10";

    cr_expect_str_eq(infin_div(one, two), "0");
}
