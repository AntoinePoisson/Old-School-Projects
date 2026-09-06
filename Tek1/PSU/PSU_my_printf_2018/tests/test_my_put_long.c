/*
** EPITECH PROJECT, 2018
** test_my_put_long
** File description:
** test my put long
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_put_long(long nb);

void redirect_all_sd(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_put_long, nbr_posi, .init = redirect_all_sd)
{
    long nbr = 123;

    my_put_long(nbr);
    cr_expect_stdout_eq_str("123");
}

Test(my_put_long, nbr_neg, .init = redirect_all_sd)
{
    long nbr = -123;

    my_put_long(nbr);
    cr_expect_stdout_eq_str("-123");
}
