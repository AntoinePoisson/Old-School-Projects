/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** Day06 task04 my_strstr
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] == '\0')
        return (NULL);
    for (int i = 0; to_find[i] != '\0'; i = i + 1)
        if (to_find[i] != str[i])
            return (my_strstr(str + 1, to_find));
    return (str);
}
