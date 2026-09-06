/*
** EPITECH PROJECT, 2018
** test_my_is_extension_printf
** File description:
** test my is extension printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my_extension.h"

int my_printf(char *str, ...);

void redirect_al(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_extension_two_printf, pourcent_h_o, .init = redirect_al)
{
    int nbr = 109;

    my_printf("%#o", nbr);
    cr_stdout_match_str("0155");
}

Test(is_extension_two_printf, pourcent_htag_x, .init = redirect_al)
{
    int nbr = 109;

    my_printf("%#x", nbr);
    cr_stdout_match_str("0x6d");
}

Test(is_extension_two_printf, pourcentd_htagx, .init = redirect_al)
{
    int nbr = 109;

    my_printf("%#X", nbr);
    cr_stdout_match_str("0X6D");
}

Test(is_extension_two_printf, pourcent_pourcent_espace, .init = redirect_al)
{
    my_printf("%   1");
    cr_stdout_match_str("% 1");
}

Test(is_extension_two_printf, pourcent_posi_espace_chif, .init = redirect_al)
{
    my_printf("%+ 91");
    cr_stdout_match_str("%+91");
}

Test(is_extension_two_printf, pourcent_posi_espace_neg, .init = redirect_al)
{
    my_printf("%+ -91");
    cr_stdout_match_str("%+-91");
}

Test(is_extension_two_printf, pourcent_posi_posi, .init = redirect_al)
{
    my_printf("%++ 91");
    cr_stdout_match_str("%+91");
}

Test(is_extension_two_printf, pourcent_posi_posi_two, .init = redirect_al)
{
    my_printf("%++91");
    cr_stdout_match_str("%+91");
}

Test(is_extension_two_printf, pourcent_neg_other, .init = redirect_al)
{
    my_printf("; %- ++2 %-+2 %-   3 %--2 %---3 %-+++3 %- 1");
    cr_stdout_match_str("; %+-2 %+-2 % -3 %-2 %-3 %+-3 % -1");
}

Test(is_extension_two_printf, pourcent_neg_nbr, .init = redirect_al)
{
    my_printf("%-91");
    cr_stdout_match_str("%-91");
}
