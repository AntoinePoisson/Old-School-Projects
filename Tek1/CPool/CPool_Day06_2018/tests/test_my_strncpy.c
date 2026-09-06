/*
** EPITECH PROJECT, 2018
** test_my_strncpy
** File description:
** We continue the unit testing with the my_strncpy function.
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_arra)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}
