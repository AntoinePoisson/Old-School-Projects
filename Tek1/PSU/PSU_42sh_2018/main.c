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
    variable_t *var = malloc(sizeof(*var));
    int value_return = 0;

    if (ac || av) {
    }
    if (check_error(var, env) != 0)
        return (84);
    is_initialization_alias(var);
    value_return = is_minishell(var);
    if (value_return == -1)
        return (0);
    else
        my_exit(var, my_itoa(value_return, 0), 1);
    return (value_return);
}
