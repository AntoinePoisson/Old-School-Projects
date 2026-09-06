/*
** EPITECH PROJECT, 2018
** word_count
** File description:
** word_count for Eval_expr
*/

#include "my.h"

int word_count(char const *str)
{
    int count = 1;
    int endof_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (endof_word == 0 && str[i] == ' ') {
            endof_word = 1;
            count++;
        }
        if(endof_word == 1 && str[i] != ' ')
            endof_word = 0;
    }
    return (count);
}
