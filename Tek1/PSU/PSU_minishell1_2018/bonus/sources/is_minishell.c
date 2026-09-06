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
#include "my_struct.h"
#include "gnl.h"
#include "my_lib.h"

void display(void);
int display_env(var_t *var);
int my_exit(var_t *var, char *arg_nbr);
int my_cd(var_t *var);
int my_unsetenv(var_t *var);
int my_setenv(var_t *var);
void destroy_arg_two_d(var_t *var);
char *control_alias(var_t *var, char *arg);
int test_command_in_path(var_t *var);
int search_command_in_path(var_t *var);
int search_my_command(var_t *var);
int exec_command_in_path(var_t *var);
int my_command(var_t *var);

static int analyse_arg(var_t *var)
{
    if (var->arg_two_d != NULL)
        destroy_arg_two_d(var);
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

int is_minishell(var_t *var)
{
    int value_return = 0;

    while (var->quit == 0 && value_return != -1) {
        display();
        var->arg = get_next_line(0);
        if (var->arg == NULL)
            return (0);
        var->arg = control_alias(var, var->arg);
        value_return = analyse_arg(var);
    }
    return (value_return);
}
