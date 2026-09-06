/*
** EPITECH PROJECT, 2019
** my_exec.c
** File description:
** my_exec
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include "my_shell.h"

int test_command_in_path(variable_t const *var)
{
    if (access(var->arg_two_d[0], X_OK) == 0)
        return (1);
    else
        return (0);
    return (0);
}

int search_command_in_path(variable_t *var)
{
    int i = 0;
    char *result = NULL;

    if (var->path == NULL || var->arg_two_d == NULL ||
        var->arg_two_d[0] == NULL)
        return (0);
    if (access(var->arg_two_d[0], X_OK) == 0)
        return (1);
    for (; var->path[i] != NULL; i += 1) {
        result = my_strcat(var->path[i], var->arg_two_d[0]);
        if (access(result, X_OK) == 0 && my_strcmp(var->path[i], "//") != 0) {
            free(var->arg_two_d[0]);
            var->arg_two_d[0] = result;
            return (1);
        }
        free(result);
    }
    return (0);
}

int search_my_command(variable_t *var)
{
    if (my_strcmp(var->arg_two_d[0], "exit") == 0 ||
        my_strcmp(var->arg_two_d[0], "env") == 0 ||
        my_strcmp(var->arg_two_d[0], "cd") == 0 ||
        my_strcmp(var->arg_two_d[0], "alias") == 0 ||
        my_strcmp(var->arg_two_d[0], "unsetenv") == 0 ||
        my_strcmp(var->arg_two_d[0], "setenv") == 0 ||
        my_strcmp(var->arg_two_d[0], "echo") == 0 ||
        my_strcmp(var->arg_two_d[0], "history") == 0)
        return (1);
    return (0);
}

int exec_command_in_path(variable_t *var)
{
    int wstatus = 0;
    pid_t pid;

    if (check_type_bin(var) == 1)
        return (84);
    if ((pid = fork()) == -1) {
        perror("fork");
        return (84);
    }
    if (pid == 0) {
        if ((execve(var->arg_two_d[0], var->arg_two_d, var->env)) == -1
            && errno == ENOEXEC)
            my_exit(var, "99999", 0);
        my_exit(var, "0", 0);
    } else {
        pid = waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
        if (!(WIFSIGNALED(wstatus) == 0) || wstatus == 40704)
            return (check_echec_exec(var, WTERMSIG(wstatus), wstatus));
    }
    return (WEXITSTATUS(wstatus));
}

int my_command(variable_t *var)
{
    if (my_strcmp(var->arg_two_d[0], "exit") == 0)
        return (my_exit(var, var->arg_two_d[1], 1));
    if (my_strcmp(var->arg_two_d[0], "env") == 0)
        return (display_env(var));
    if (my_strcmp(var->arg_two_d[0], "alias") == 0)
        return (exec_my_alias(var));
    if (my_strcmp(var->arg_two_d[0], "cd") == 0)
        return (my_cd(var));
    if (my_strcmp(var->arg_two_d[0], "unsetenv") == 0)
        return (my_unsetenv(var));
    if (my_strcmp(var->arg_two_d[0], "setenv") == 0)
        return (my_setenv(var));
    if (my_strcmp(var->arg_two_d[0], "history") == 0)
        return (my_history(var->history, var->arg_two_d + 1, &var->reset));
    if (my_strcmp(var->arg_two_d[0], "echo") == 0)
        return (my_echo(var));
    return (0);
}
