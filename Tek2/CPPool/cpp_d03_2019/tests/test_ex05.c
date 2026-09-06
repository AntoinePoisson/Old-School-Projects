/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

Test(size, null)
{
    string_t *this = NULL;

    cr_expect_eq(size(this), -1);
}

Test(size, size)
{
    string_t *this = malloc(sizeof(*this));

    this->str = strdup("eeeeeeee");
    cr_expect_neq(size(this), -1);
}