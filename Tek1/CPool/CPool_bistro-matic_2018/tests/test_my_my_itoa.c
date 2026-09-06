/*
** EPITECH PROJECT, 2018
** test my my_itoa
** File description:
** unit test for my_itoa
*/

#include <criterion/criterion.h>

char *my_itoa(int nbr, int neg);

Test(my_itoa, test_basic_itoa)
{
    cr_expect_str_eq(my_itoa(1, 0), "1");
}

Test(my_itoa, test_neg_itoa)
{
    cr_expect_str_eq(my_itoa(1, 1), "-1");
}

Test(my_itoa, test_zero_itoa)
{
    cr_expect_str_eq(my_itoa(0, 0), "0");
}
