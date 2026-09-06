/*
** EPITECH PROJECT, 2018
** test_my_put_nbr_base
** File description:
** test my put nbr base
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my_put_nbr_base.h"

int my_put_nbr_base(int nb, char *base);

void redirect_all_st(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_put_nbr_base, base10, .init = redirect_all_st)
{
    int nbr = 1234567;

    my_put_nbr_base(nbr, "0123456789");
    cr_stdout_match_str("1234567");
}

Test(my_put_nbr_base, base10neg, .init = redirect_all_st)
{
    int nbr = -1234567;

    my_put_nbr_base(nbr, "0123456789");
    cr_stdout_match_str("1234567");
}

Test(my_put_nbr_base, base8, .init = redirect_all_st)
{
    int nbr = 2257;

    my_put_nbr_base(nbr, "01234567");
    cr_stdout_match_str("4321");
}

Test(my_put_nbr_base, base2, .init = redirect_all_st)
{
    int nbr = 1234567;

    my_put_nbr_base(nbr, "01");
    cr_stdout_match_str("100101101011010000111");
}

Test(my_put_nbr_base, base16_maj, .init = redirect_all_st)
{
    int nbr = 1234567;

    my_put_nbr_base(nbr, "0123456789ABCDEF");
    cr_stdout_match_str("12D687");
}

Test(my_put_nbr_base, base16_min, .init = redirect_all_st)
{
    int nbr = 1234567;

    my_put_nbr_base(nbr, "0123456789abcdef");
    cr_stdout_match_str("12d687");
}
