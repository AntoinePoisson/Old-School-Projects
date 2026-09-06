/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** D6, function that returns 1 there is only alpha else if return 0.
*/

#include <stddef.h>

int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    if (str == NULL || str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z')))
            return (0);
    }
    return (1);
}
