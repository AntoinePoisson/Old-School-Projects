/*
** EPITECH PROJECT, 2018
** test my infin mod
** File description:
** unit test for infin mod
*/

#include <criterion/criterion.h>

char *infin_mod(char *divided, char* divisor);

Test(infin_mod, test_basic_mod)
{
    char one[] = "11";
    char two[] = "10";

    cr_expect_str_eq(infin_mod(one, two), "1");
}

Test(infin_mod, test_neg_mod)
{
    char one[] = "10";
    char two[] = "12";

    cr_expect_str_eq(infin_mod(one, two), "10");
}

Test(infin_mod, test_neg_mod_second)
{
    char one[] = "-10";
    char two[] = "12";

    cr_expect_str_eq(infin_mod(one, two), "-10");
}
