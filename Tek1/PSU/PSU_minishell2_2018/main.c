/*
** EPITECH PROJECT, 2018
** main
** File description:
** main of 42sh
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_shell.h"

int main(int ac, char const *av[], char *env[])
{
    variable_t *var = malloc(sizeof(variable_t));
    int value_return = 0;

    if (ac || av) {
    }
    if (check_error(var, env) != 0)
        return (84);
    value_return = is_minishell(var);
    if (value_return == -1)
        return (0);
    else
        my_exit(var, my_itoa(value_return , 0));
    return (value_return);
}
