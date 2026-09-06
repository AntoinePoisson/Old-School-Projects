/*
** EPITECH PROJECT, 2018
** checks_errors
** File description:
** checks the programm's errors
*/

#include "include/my.h"

int my_strlen(char const *str);

int my_str_isnum_custom(char const *str)
{
    int i = 0;
    int chekage = 0;
    int size = my_strlen(str);
    int case_negative = 1;

    if (str[0] == '\0')
        return (1);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            chekage++;
        if (str[i] == '-' && case_negative == 1) {
            chekage++;
            case_negative = 0;
        }
    }
    if (chekage == size)
        return (1);
    return (0);
}

int checks_errors(char *av[], int ac)
{
    if (ac != 3)
        return (0);
    if (my_str_isnum_custom(av[1]) == 0 || my_str_isnum_custom(av[2]) == 0)
        return (0);
    return (1);
}
