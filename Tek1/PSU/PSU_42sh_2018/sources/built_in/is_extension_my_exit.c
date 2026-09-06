/*
** EPITECH PROJECT, 2019
** is_extension_my_exit.c
** File description:
** is_extension_my_exit
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_lib.h"

void destroy_arg_two_d(variable_t *var)
{
    if (var->arg_two_d == NULL)
        return;
    for (int i = 0; var->arg_two_d[i] != NULL; i++) {
        if (var->arg_two_d[i] != NULL && var->arg_two_d != NULL)
            free(var->arg_two_d[i]);
    }
    free(var->arg_two_d);
}

int destroy_env(variable_t *var)
{
    if (var->env != NULL) {
        for (int i = 0; var->env[i] != NULL; i++)
            free(var->env[i]);
        free(var->env);
    }
    return (0);
}