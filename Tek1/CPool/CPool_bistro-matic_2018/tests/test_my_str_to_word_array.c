/*
** EPITECH PROJECT, 2018
** test_my_str_to_word_array
** File description:
** unit test for my_str_to_word_array
*/

#include <criterion/criterion.h>

char **my_str_to_word_array(char const *str);

Test(my_str_to_word_array, one_word_to_tab)
{
    char *str[2] = {"Hello", 0};
    char **str2 = my_str_to_word_array("Hello");

    for (int i = 0; i < 1; i++) {
        cr_expect_arr_eq(str2[i], str[i], 2);
    }
}

Test(my_str_to_word_array, two_words_to_tab)
{
    char *str[3] = {"Hello", "World", 0};
    char **str2 = my_str_to_word_array("Hello World");

    for (int i = 0; i < 2; i++) {
        cr_expect_arr_eq(str2[i], str[i], 3);
    }
}
