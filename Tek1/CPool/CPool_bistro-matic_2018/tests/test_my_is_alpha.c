/*
11;rgb:0000/0000/0000** EPITECH PROJECT, 2018
** test_my_is_alpha
** File description:
** unit test for is_alpha
*/

#include <criterion/criterion.h>

int is_alpha(char c);

Test(is_alpha, test_char_is_a)
{
    cr_expect_eq(is_alpha('a'), 1);
}

Test(is_alpha, char_is_z)
{
    cr_expect_eq(is_alpha('z'), 1);
}

Test(is_alpha, char_is_h)
{
    cr_expect_eq(is_alpha('h'), 1);
}

Test(is_alpha, char_is_curly)
{
    cr_expect_eq(is_alpha('{'), 0);
}

Test(is_alpha, char_is_grave_accent)
{
    cr_expect_eq(is_alpha('`'), 0);
}

Test(is_alpha, char_is_exclamation)
{
    cr_expect_eq(is_alpha('!'), 0);
}

Test(is_alpha, char_is_zero)
{
    cr_expect_eq(is_alpha('0'), 0);
}

Test(is_alpha, char_is_nine)
{
    cr_expect_eq(is_alpha('9'), 0);
}
