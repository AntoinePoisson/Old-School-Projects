/*
** EPITECH PROJECT, 2018
** test_my_is_extension_two_printf
** File description:
** test my is extension two printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my_extension.h"

int my_printf(char *str, ...);

void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_extension_two_printf, pourcent_zero_o, .init = redirect_all)
{
    int nbr = 109;

    my_printf("%0o", nbr);
    cr_stdout_match_str("0155");
}

Test(is_extension_two_printf, pourcent_zero_x, .init = redirect_all)
{
    int nbr = 109;

    my_printf("%0x", nbr);
    cr_stdout_match_str("6d");
}

Test(is_extension_two_printf, pourcentd_zero_u, .init = redirect_all)
{
    int nbr = 123456;

    my_printf("%0u", nbr);
    cr_stdout_match_str("123456");
}

Test(is_extension_two_printf, pourcentd_zero_d, .init = redirect_all)
{
    int nbr = 123456;

    my_printf("%0d", nbr);
    cr_stdout_match_str("123456");
}

Test(is_extension_two_printf, pourcentd_zero_i, .init = redirect_all)
{
    int nbr = 123456;

    my_printf("%0i", nbr);
    cr_stdout_match_str("123456");
}

Test(is_extension_two_printf, pourcentd_zero_d_neg, .init = redirect_all)
{
    int nbr = -123456;

    my_printf("%0u", nbr);
    cr_stdout_match_str("-123456");
}

Test(is_extension_two_printf, pourcentd_zero_x_two, .init = redirect_all)
{
    int nbr = 109;

    my_printf("%0X", nbr);
    cr_stdout_match_str("6D");
}
