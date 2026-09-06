/*
** EPITECH PROJECT, 2019
** is_minishell.c
** File description:
** is_minishell
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_shell.h"

int exec_arg(variable_t *var, char *data)
{
    if (var->arg_two_d != NULL)
        destroy_arg_two_d(var);
    var->arg = data;
    if ((var->arg_two_d = my_str_to_word_array(var->arg)) == NULL)
        return (84);
    if (search_my_command(var) == 1)
        return (my_command(var));
    if (search_command_in_path(var) == 1)
        return (exec_command_in_path(var));
    if (var->arg_two_d[0] != NULL) {
        write(2, var->arg_two_d[0], my_strlen(var->arg_two_d[0]));
        write(2, ": Command not found.\n", 21);
        return (84);
    }
    return (0);
}

int is_minishell(variable_t *var)
{
    var->value_return = 0;
    while (var->quit == 0 && var->value_return != -1) {
        display();
        var->arg = get_next_line(0);
        if (var->arg == NULL)
            return (0);
        var->value_return = is_operator(var);
    }
    var->value_return = 0;
    return (var->value_return);
}