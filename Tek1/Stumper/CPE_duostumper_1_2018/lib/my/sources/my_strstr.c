/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** D6, researche in chaine another chaine
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i_two = 0;

    if (str == NULL || to_find == NULL || to_find[0] == '\0')
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, i_two = 0) {
        for (int i_three = i; to_find[i_two] == str[i_three];
            i_two++, i_three++) {
            if (str[i_three] == to_find[i_two] &&
                to_find[i_two + 1] == '\0') {
                return (&str[i]);
            }
        }
    }
    return (NULL);
}
