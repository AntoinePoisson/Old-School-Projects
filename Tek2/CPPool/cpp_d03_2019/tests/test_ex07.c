/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

Test(copy, null)
{
    string_t *this = NULL;
    char *str = NULL;
    size_t n = 0;
    size_t pos = 0;

    cr_expect_eq(copy(this, str, n, pos), 0);
}

Test(copy, copy)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("aaaaaaaaaaa");
    size_t n = 2;
    size_t pos = 0;

    this->str = strdup("0123");
    cr_expect_eq(copy(this, str, n, pos), 2);
}

Test(c_str, c_str)
{
    string_t *this = malloc(sizeof(*this));

    this->str = strdup("0123");
    cr_expect_neq(c_str(this), 1);
}

Test(c_str, null)
{
    string_t *this = malloc(sizeof(*this));

    this->str = NULL;
    cr_expect_neq(c_str(NULL), 2);
}

Test(empty, empty)
{
    string_t *this = malloc(sizeof(*this));

    this->str = NULL;
    cr_expect_eq(empty(this), 1);
}

Test(empty, null)
{
    cr_expect_eq(empty(NULL), 0);
}