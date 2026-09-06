/*
** EPITECH PROJECT, 2018
** test_my_word_count
** File description:
** unit test for word count
*/

#include <criterion/criterion.h>

int word_count(char const *str);

Test(word_count, one_word_test)
{
    cr_expect_eq(word_count("Hello"), 1);
}

Test(word_count, two_words_test)
{
    cr_expect_eq(word_count("Hello World"), 2);
}

Test(word_count, ten_words_test)
{
    cr_expect_eq(word_count("a z e r t y u i o p"), 10);
}
