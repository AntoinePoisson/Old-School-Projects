/*
** EPITECH PROJECT, 2018
** test_my_revstr
** File description:
** We continue the unit testing with the my_revstr function.
*/
#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, return_value_is_reversed)
{
    char str[6] = "Hello";
 
    cr_assert_str_eq(my_revstr(str), "olleH");
}
