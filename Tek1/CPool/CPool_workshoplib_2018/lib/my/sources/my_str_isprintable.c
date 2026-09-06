/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** D6, function return 1 if she contains only charac printable
*/

#include <stddef.h>

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    if (str == NULL || str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= ' ' && str[i] <= '~' && str[i] != 92))
            return (0);
    }
    return (1);
}
