/*
** EPITECH PROJECT, 2018
** test_option_h
** File description:
** test_option_h
*/

#include <criterion/criterion.h>

int is_case_zero(int nbr);
char *my_itoa(int nbr, int neg);

Test(case_zero, no_is_case_zero)
{
    cr_assert_eq(0, is_case_zero(1));
}

Test(is_case_zero, no_is_case_zero)
{
    cr_assert_eq(1, is_case_zero(0));
}

Test(my_itoa, my_itoa_zero)
{
    cr_assert_str_eq("0", my_itoa(0, 0));
}

Test(my_itoa, my_itoa_nbr)
{
    cr_assert_str_eq("1234", my_itoa(1234, 0));
}

Test(my_itoa, my_itoa_neg)
{
    cr_assert_str_eq("-1234", my_itoa(1234, 1));
}