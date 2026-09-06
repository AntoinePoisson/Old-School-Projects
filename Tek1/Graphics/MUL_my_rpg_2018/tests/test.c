/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_rpg.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test, test, .init = redirect_all_stdout)
{
    cr_expect_eq(0, 0);
}