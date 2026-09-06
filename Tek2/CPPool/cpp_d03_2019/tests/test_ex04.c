/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

Test(clear, null)
{
    string_t *this = NULL;

    clear(this);
    cr_expect_neq(this, -1);
}

Test(clear, clear)
{
    string_t *this = malloc(sizeof(*this));

    this->str = strdup("eeeeeeee");
    clear(this);
    cr_expect_neq(this, -1);
}