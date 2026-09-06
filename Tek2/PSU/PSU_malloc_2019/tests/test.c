/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../header.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(malloc, malloc_null, .init = redirect_all_stdout)
{
    cr_expect_eq(malloc(0), NULL);
}

Test(malloc, malloc, .init = redirect_all_stdout)
{
    cr_expect_neq(malloc(100 * sizeof(char)), NULL);
}

Test(calloc, calloc, .init = redirect_all_stdout)
{
    cr_expect_neq(calloc(100, sizeof(char)), NULL);
}

Test(free, free_null, .init = redirect_all_stdout)
{
    void *toto = malloc(10);

    free(toto);
    cr_expect_neq(toto, NULL);
}