/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_struct.h"

int main(int ac, char *av[]);
int my_put_long(long nb);
int check_error_flag(char *arg);
int display_error_message_big_r(flag_t *flag);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_put_long, my_put_long, .init = redirect_all_std)
{
    long nbr = 123456789;

    my_put_long(nbr);
    cr_stdout_match_str("123456789");
}

Test(check_error_flag, check_error_flag_fail, .init = redirect_all_std)
{
    char *str = "azeertyuiop";

    cr_assert_eq(check_error_flag(str), 84);
}

Test(check_error_flag, check_error_flag_succ, .init = redirect_all_std)
{
    char *str = "-";

    cr_assert_eq(check_error_flag(str), 0);
}