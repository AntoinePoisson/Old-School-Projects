/*
** EPITECH PROJECT, 2018
** my_str_isupper
** File description:
** D6, function return 1 if she contains only upper alpha
*/

#include <stddef.h>

int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    if (str == NULL || str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' && str[i] > 'Z')
            return (0);
    }
    return (1);
}
