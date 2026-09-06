/*
** EPITECH PROJECT, 2019
** check_parentheses.c
** File description:
** check_parentheses
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static int count_parentheses(char *arg)
{
    int n_open = 0;
    int n_close = 0;

    for (int i = 0; arg[i]; i++) {
        if (arg[i] == '(')
            n_open += 1;
        if (arg[i] == ')')
            n_close += 1;
    }
    if (n_open == 0 && n_close == 0)
        return (0);
    if (n_open % 2 != 0 && n_open == n_close)
        return (0);
    if (n_open > n_close)
        return (my_puterror("Too many ('s.\n"));
    else
        return (my_puterror("Too many )'s.\n"));
    return (0);
}

char *check_parentheses(char *arg)
{
    if (count_parentheses(arg) == 84)
        return (NULL);
    for (int i = 0; arg[i]; i++) {
        if (arg[i] == ')')
            arg[i] = ' ';
    }
    return (arg);
}