/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

Test(assign_s, null)
{
    string_t *this = NULL;
    string_t *str = NULL;

    assign_s(this, str);
    cr_expect_eq(this, NULL);
}

Test(assign_s, ok)
{
    string_t *this = malloc(sizeof(*this));
    string_t *str = malloc(sizeof(*str));

    str->str = strdup("eeeee");
    assign_s(this, str);
    cr_expect_neq(this->str, "eeeee");
}

Test(assign_s, str_null)
{
    string_t *this = malloc(sizeof(*this));
    string_t *str = NULL;

    assign_s(this, str);
    cr_expect_neq(this->str, "eeeee");
}

Test(assign_c, null)
{
    string_t *this = NULL;
    char *str = NULL;

    assign_c(this, str);
    cr_expect_eq(this, NULL);
}

Test(assign_c, ok)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("eeeee");

    assign_c(this, str);
    cr_expect_neq(this->str, "eeeee");
}

Test(assign_c, str_null)
{
    string_t *this = malloc(sizeof(*this));
    char *str = NULL;

    assign_c(this, str);
    cr_expect_neq(this->str, "eeeee");
}