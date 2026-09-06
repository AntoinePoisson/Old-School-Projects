/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

Test(append_s, null)
{
    string_t *this = NULL;
    string_t *str = NULL;

    append_s(this, str);
    cr_expect_eq(this, NULL);
}

Test(append_c, null)
{
    string_t *this = NULL;
    char *str = NULL;

    append_c(this, str);
    cr_expect_eq(this, NULL);
}

Test(append_s, test)
{
    string_t *this = malloc(sizeof(*this));
    string_t *str = malloc(sizeof(*str));

    str->str = strdup("eeeee");
    append_s(this, str);
    cr_expect_neq(this->str, "eeeee");
}

Test(append_c, test)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("eeeee");

    append_c(this, str);
    cr_expect_neq(this->str, "eeeee");
}

Test(append_s, test2)
{
    string_t *this = malloc(sizeof(*this));
    string_t *str = malloc(sizeof(*str));

    this->str =  strdup("aaaaa");
    str->str = strdup("eeeee");
    append_s(this, str);
    cr_expect_neq(this->str, "eeeee");
}

Test(append_c, test3)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("eeeee");

    this->str =  strdup("aaaaa");
    append_c(this, str);
    cr_expect_neq(this->str, "eeeee");
}

Test(string_init, string_init)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("eeeee");

    string_init(this, str);
    cr_expect_neq(this, NULL);
}

Test(string_init, AZERTY)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("eeeee");

    string_init(this, NULL);
    cr_expect_neq(this, NULL);
}

Test(string_init, AZTY)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("eeeee");

    this->str = strdup("eee");
    string_init(this, NULL);
    cr_expect_neq(this, NULL);
}

Test(string_init, AZETY)
{
    string_t *this = malloc(sizeof(*this));
    char *str = strdup("eeeee");

    string_init(NULL, NULL);
    cr_expect_neq(this, NULL);
}

Test(string_destroy, string_destroy)
{
    string_t *this = malloc(sizeof(*this));

    string_destroy(this);
    cr_expect_neq(this, NULL);
}

Test(string_destroy, null)
{
    string_t *this = malloc(sizeof(*this));

    string_destroy(NULL);
    cr_expect_neq(this, NULL);
}