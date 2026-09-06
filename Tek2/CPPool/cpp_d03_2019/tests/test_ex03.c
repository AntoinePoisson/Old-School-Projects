/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

Test(at, null)
{
    string_t *this = NULL;
    size_t str = 0;

    cr_expect_eq(at(this, str), -1);
}

Test(at, at)
{
    string_t *this = malloc(sizeof(*this));
    size_t str = 2;

    this->str = strdup("0123");
    cr_expect_neq(at(this, str), -1);
}
