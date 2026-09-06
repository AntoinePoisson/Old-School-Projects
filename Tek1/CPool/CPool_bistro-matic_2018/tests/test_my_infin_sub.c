/*
** EPITECH PROJECT, 2018
** test my infin_sub
** File description:
** unit test for infin_sub
*/

#include <criterion/criterion.h>

char *infin_sub(char *first, char *second);

Test(infin_sub, test_basic_minus)
{
    char one[] = "4";
    char two[] = "2";

    cr_expect_str_eq(infin_sub(one, two), "2");
}

Test(infin_sub, test_soustract_neg)
{
    char one[] = "-4";
    char two[] = "6";

    cr_expect_str_eq(infin_sub(one, two), "-10");
}

Test(infin_sub, test_soustract_double_neg)
{
    char one[] = "-4";
    char two[] = "-2";

    cr_expect_str_eq(infin_sub(one, two), "-2");
}

Test(infin_sub, test_minus_to_pos)
{
    char one[] = "-4";
    char two[] = "-6";

    cr_expect_str_eq(infin_sub(one, two), "2");
}

Test(infin_sub, test_minus_to_0)
{
    char one[] = "5";
    char two[] = "5";

    cr_expect_str_eq(infin_sub(one, two), "0");
}

Test(infin_sub, test_minus_to_neg)
{
    char one[] = "5";
    char two[] = "8";

    cr_expect_str_eq(infin_sub(one, two), "-3");
}
