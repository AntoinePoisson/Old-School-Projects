/*
** EPITECH PROJECT, 2018
** test_my_put_address
** File description:
** test my put address
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_put_adress(long nb);

void redirect_all_stt(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_put_adress, nbr_posi, .init = redirect_all_stt)
{
    long nbr = 123;

    my_put_adress(nbr);
    cr_expect_stdout_eq_str("7b");
}

Test(my_put_adress, nbr_neg, .init = redirect_all_stt)
{
    long nbr = -123;

    my_put_adress(nbr);
    cr_expect_stdout_eq_str("7b");
}
