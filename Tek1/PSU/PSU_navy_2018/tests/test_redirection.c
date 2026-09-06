/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/navy.h"

int redirect_signal(void);

Test(recover_signal, recover_signal)
{
    char add = '\0';
    char nb[8] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

    cr_expect_neq(recover_signal(add), nb);
}

Test(recover_signal, recover_signal_two)
{
    char add = 'A';
    char nb[8] = {'A', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

    cr_expect_neq(recover_signal(add), nb);
}

Test(redirect_signal, redirect_signal)
{
    cr_expect_eq(redirect_signal(), 0);
}

/*    system();
    cr_expect_eq(0, 0);
    cr_stdout_match_str(0);*/
