/*
** EPITECH PROJECT, 2018
** test_my_strstr.c
** File description:
** We continue the unit testing with the my_revstr function.
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, return_value_is_reversed)
{
    char str[] = "Hello World!";
    char to_find[] = "";

    cr_expect_str_eq(my_strstr(str, to_find), str);
}

Test(my_strstr, copy_string_in_empty_array_return_value)
{
    char str[] = "Hello World";
    char to_find[] = "az";

    cr_expect_null(my_strstr(str, to_find));
}

Test(my_strstr, string_eq)
{
    char str[] = "Hello World";
    char to_find[] = "W";
    char *stokage = my_strstr(str, to_find);

    cr_expect_str_eq(stokage, "World");
}
