/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** rechear in chaine a other chaine
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int a = 0;
    char *pointeur_return = 0;

    if (to_find[0] == '\0')
        return (str);
    for (i = 0; str[i] != '\0'; i++) {
        for (a = 0; to_find[a] != '\0'; a++) {
            if (str[i] == to_find[a]) {
                pointeur_return = &str[i];
                return (pointeur_return);
            }
        }
    }
    return(NULL);
}
