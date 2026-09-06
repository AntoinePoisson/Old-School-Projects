/*
** EPITECH PROJECT, 2018
** my_puterror
** File description:
** put a string in the erro output
*/

#include "my.h"

void my_puterror(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        write(2, &str[index], 1);
        index += 1;
    }
}
