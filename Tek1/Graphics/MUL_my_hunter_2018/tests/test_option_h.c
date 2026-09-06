/*
** EPITECH PROJECT, 2018
** test_option_h
** File description:
** test_option_h
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(main, main_option_h, .init = redirect_all_std)
{
    system("./my_hunter -h");
    cr_stdout_match_str("USAGE\n      ./my_hunter\nDESCRIPTION\n"\
"       This is a small video game based on the"
" rules of Duck Hunt.\n");
}
