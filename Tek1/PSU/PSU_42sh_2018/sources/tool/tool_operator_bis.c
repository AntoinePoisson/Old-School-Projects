/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** tools bis
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

int is_extension_check_operator(char const *str, int i)
{
    if (str[i] == '>')
        return (6);
    if (str[i] == '|' && str[i + 1] == '|')
        return (7);
    if (str[i] == '&' && str[i + 1] == '&')
        return (8);
    return (84);
}

int check_operator(char const *str)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] == '(')
            return (0);
        if (str[i] == ';')
            return (1);
        if ((str[i] == '|' && str[i + 1] != '|' && i == 0) || (str[i] == '|'
            && str[i + 1] != '|' && i > 0 && str[i - 1] != '|'))
            return (2);
        if (str[i] == '<' && str[i + 1] == '<')
            return (3);
        if (str[i] == '<')
            return (4);
        if (str[i] == '>' && str[i + 1] == '>')
            return (5);
        if (is_extension_check_operator(str, i) != 84)
            return (is_extension_check_operator(str, i));
    }
    return (-1);
}
