/*
** EPITECH PROJECT, 2019
** my_unsetenv.c
** File description:
** my_unsetenv
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

int check_error_my_unsetenv(variable_t const *var)
{
    if (count_arg(var->arg_two_d) < 2) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (1);
    }
    return (0);
}

int my_unsetenv(variable_t *var)
{
    if (var->env == NULL || var->env[0] == NULL)
        return (0);
    if (check_error_my_unsetenv(var) == 1)
        return (84);
    if (var->env == NULL || var->env[0] == NULL)
        return (0);
    for (int i = count_arg(var->arg_two_d) - 1; i >= 1; i--) {
        if (var->arg_two_d[1] != NULL && pop(var) == 84)
            return (84);
        if (i != 1 && var->arg_two_d[1] != NULL) {
            free(var->arg_two_d[1]);
            var->arg_two_d[1] = my_strdup(var->arg_two_d[i]);
        }
    }
    return (0);
}
