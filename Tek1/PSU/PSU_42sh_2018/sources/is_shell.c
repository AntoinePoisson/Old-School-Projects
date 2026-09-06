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
    var->arg = control_alias(var, change_backslash(data));
    if ((var->arg_two_d = my_str_to_word_array(var->arg)) == NULL)
        return (1);
    if ((var->arg_two_d = find_globbing(var->arg_two_d)) == NULL)
        return (1);
    if (search_my_command(var) == 1)
        return (my_command(var));
    if (search_command_in_path(var) == 1)
        return (exec_command_in_path(var));
    if (var->arg_two_d[0] != NULL) {
        write(2, var->arg_two_d[0], my_strlen(var->arg_two_d[0]));
        write(2, ": Command not found.\n", 21);
        return (1);
    }
    return (0);
}

int is_minishell(variable_t *var)
{
    var->value_return = 0;
    var->reset = false;
    var->history = NULL;
    while (var->quit == 0 && var->value_return != -1) {
        var->arg = get_cmd(var->env, var->history);
        if (var->arg == NULL)
            break;
        var->history = add_to_history(var->history, var->arg, var->reset);
        var->arg = find_backslash(var->arg);
        if (my_str_has_backtick(var->arg) == true)
            var->arg = backticks(var->arg, var);
        var->value_return = is_operator(var);
    }
    return (var->value_return);
}
