/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

Test(compare_s, null)
{
    string_t *this = NULL;
    string_t *str = NULL;

    cr_expect_eq(compare_s(this, str), 0);
}

Test(compare_s, compare_s)
{
    string_t *this = malloc(sizeof(*this));
    string_t *str = malloc(sizeof(*this));

    this->str = strdup("0123");
    str->str = strdup("01D23");
    cr_expect_neq(compare_s(this, str), 0);
}

Test(compare_c, null)
{
    string_t *this = NULL;
    char *str = "eeeeee";

    cr_expect_eq(compare_c(this, str), 0);
}

Test(compare_c, compare_s)
{
    string_t *this = malloc(sizeof(*this));
    char *str = "eeeeee";

    this->str = strdup("0123");
    cr_expect_neq(compare_c(this, str), 0);
}