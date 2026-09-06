/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** D6, Function that capitalizes the first letter of each word.
*/

#include <stddef.h>

static char *is_capitalize_espace(char *str, int i)
{
    int continuer = 0;
    int a = 0;

    for (a = i; str[a] != '\0' && continuer == 0; a++) {
        if (str[a] >= 'A' && str[a] <= 'Z')
            continuer = 1;
        if (str[a] >= 'a' && str[a] <= 'z') {
            str[a] = str[a] - 32;
            continuer = 1;
        }
    }
    return (str);
}

static char *start_capitalize(char *str)
{
    int i = 0;
    int continuer = 0;

    while (continuer == 0) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            continuer = 1;
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
            continuer = 1;
        }
        i++;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    start_capitalize(str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '.' || str[i] == '!' ||
            str[i] == ':' || str[i] == '?' || str[i] == ';')
            is_capitalize_espace(str, i);
    }
    return (str);
}
