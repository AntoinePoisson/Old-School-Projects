/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** D6, function that puts every letter of every word in lowercase.
*/

#include <stddef.h>

static char *is_capitalize(char *str, int i)
{
    int continuer = 0;
    int a = 0;

    for (a = i; str[a] != '\0' && continuer == 0; a++) {
        if (str[a] >= 'A' && str[a] <= 'Z') {
            str[a] = str[a] + 32;
            continuer = 1;
        }
    }
    return (str);
}

char *my_strlowcase(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            is_capitalize(str, i);
    }
    return (str);
}
