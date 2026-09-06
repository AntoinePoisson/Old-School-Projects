/*
** EPITECH PROJECT, 2018
** testing cat
** File description:
** You must now write unit tests for all the code composing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int cat(int ac, char *av[], int a);

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(cat, cat_test_val, .init = redirect_all_stdout)
{
    char *t[3] = {"./a.out", "file", 0}; 
    cat(2, t, 1);
    cr_expect_stdout_eq_str("Bonjour, le test marche");
}
