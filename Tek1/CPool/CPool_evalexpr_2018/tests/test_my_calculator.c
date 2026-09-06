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
    cr_expect_str_eq(calculator("1", '+', "1"), "2"); 
}

Test(calculator, test_basic_minus)
{
    cr_expect_str_eq(calculator("4", '-', "2"), "2");
}

Test(calculator, test_minus_to_0)
{
    cr_expect_str_eq(calculator("5", '-', "5"), "0");
}

Test(calculator, test_minus_to_neg)
{
    cr_expect_str_eq(calculator("5", '-', "8"), "-3");
}

Test(calculator, test_basic_mult)
{
    cr_expect_str_eq(calculator("1", '*', "1"), "1");
}

Test(calculator, test_mult)
{
    cr_expect_str_eq(calculator("2", '*', "5"), "10");
}

Test(calculator, test_basic_div)
{
    cr_expect_str_eq(calculator("1", '/', "1"), "1");
}

Test(calculator, test_div)
{
    cr_expect_str_eq(calculator("40", '/', "20"), "2");
}

Test(calculator, test_basic_mod)
{
    cr_expect_str_eq(calculator("1", '%', "1"), "0");
}

Test(calculator, test_mod)
{
    cr_expect_str_eq(calculator("11", '%', "10"), "1");
}
