/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** D6, function that returns 1 if she contains only digits.
*/

#include <stddef.h>

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    if (str == NULL || str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' && str[i] > '9')
            return (0);
    }
    return (1);
}
