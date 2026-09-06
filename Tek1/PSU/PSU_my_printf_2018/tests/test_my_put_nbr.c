/*
** EPITECH PROJECT, 2018
** test_my_put_nbr
** File description:
** test my put nbr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_put_nbr(int nb);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_put_nbr, nbr_posi, .init = redirect_all_stdout)
{
    int nbr = 123;

    my_put_nbr(nbr);
    cr_expect_stdout_eq_str("123");
}

Test(my_put_nbr, nbr_neg, .init = redirect_all_stdout)
{
    int nbr = -123;

    my_put_nbr(nbr);
    cr_expect_stdout_eq_str("-123");
}

Test(my_put_nbr, nbr_big, .init = redirect_all_stdout)
{
    my_put_nbr(999999999);
    cr_expect_stdout_eq_str("999999999");
}

Test(my_put_nbr, nbr_zero, .init = redirect_all_stdout)
{
    my_put_nbr(0);
    cr_expect_stdout_eq_str("0");
}
