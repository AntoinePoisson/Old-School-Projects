/*
** EPITECH PROJECT, 2018
** test my infin_add
** File description:
** unit test for infin_add
*/

#include <criterion/criterion.h>

char *infin_add(char *first, char *second);

Test(infin_add, test_basic_add)
{
    char one[] = "1";

    cr_expect_str_eq(infin_add(one, one), "2");
}

Test(infin_add, test_big_add)
{
    char one[] = "1";
    char two[] = "99999999999";

    cr_expect_str_eq(infin_add(one, two), "100000000000");
}

Test(infin_add, test_neg_to_pos)
{
    char one[] = "-10";
    char two[] = "20";

    cr_expect_str_eq(infin_add(one, two), "10");
}

Test(infin_add, test_neg_and_neg)
{
    char one[] = "-1";
    char two[] = "-99";

    cr_expect_str_eq(infin_add(one, two), "-100");
}

Test(infin_add, test_neg_pos)
{
    char one[] = "-100";
    char two[] = "5";

    cr_expect_str_eq(infin_add(one, two), "-95");
}

Test(infin_add, test_pos_neg)
{
    char one[] = "50";
    char two[] = "-5";

    cr_expect_str_eq(infin_add(one, two), "45");
}

Test(infin_add, test_pos_to_neg)
{
    char one[] = "100";
    char two[] = "-150";

    cr_expect_str_eq(infin_add(one, two), "-50");
}
