/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char const *str)
{
    int count = word_count(str);
    char **array = malloc(sizeof(char *) * (count + 1));
    int a = 0;
    int length = 0;

    for (int i = 0; str != 0 && str[i] != '\0'; i++) {
        for (i; str[i] != ' ' && str[i] != '\0'; i++)
            length++;
        if (str[i] == ' ' || str[i] == '\0') {
            array[a] = malloc(sizeof(char) * (length + 1));
            my_strncpy(array[a], &str[i - length], length);
            length = 0;
            a++;
        }
    }
    array[a] = NULL;
    return (array);
}
