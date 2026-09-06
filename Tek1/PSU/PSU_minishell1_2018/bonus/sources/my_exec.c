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
int check_echec_exec(int signal, int wstatus);
int check_type_bin(var_t *var);

int test_command_in_path(var_t *var)
{
    if (access(var->arg_two_d[0], X_OK) == 0)
        return (1);
    else
        return (0);
    return (0);
}

int search_command_in_path(var_t *var)
{
    int i = 0;
    char *result = NULL;

    if (var->path == NULL || var->arg_two_d == NULL ||
        var->arg_two_d[0] == NULL)
        return (0);
    if (var->arg_two_d[0][0] == '/' || (var->arg_two_d[0][0] == '.' &&
        var->arg_two_d[0][1] == '/'))
        return (test_command_in_path(var));
    for (; var->path[i] != NULL; i += 1) {
        result = my_strcat(var->path[i], var->arg_two_d[0]);
        if (access(result, X_OK) == 0) {
            free(var->arg_two_d[0]);
            var->arg_two_d[0] = result;
            return (1);
        }
        free(result);
    }
    return (0);
}

int search_my_command(var_t *var)
{
    if (my_strcmp(var->arg_two_d[0], "exit") == 0)
        return (1);
    if (my_strcmp(var->arg_two_d[0], "env") == 0)
        return (1);
    if (my_strcmp(var->arg_two_d[0], "cd") == 0)
        return (1);
    if (my_strcmp(var->arg_two_d[0], "unsetenv") == 0)
        return (1);
    if (my_strcmp(var->arg_two_d[0], "setenv") == 0)
        return (1);
    return (0);
}

int exec_command_in_path(var_t *var)
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
        if ((execve(var->arg_two_d[0], var->arg_two_d, var->env)) == -1)
            my_exit(var, "130");
        my_exit(var, "0");
    } else {
        pid = waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
        if (!(WIFSIGNALED(wstatus) == 0))
            check_echec_exec(WTERMSIG(wstatus), wstatus);
    }
    return (0);
}

int my_command(var_t *var)
{
    if (my_strcmp(var->arg_two_d[0], "exit") == 0)
        return (my_exit(var, var->arg_two_d[1]));
    if (my_strcmp(var->arg_two_d[0], "env") == 0)
        return (display_env(var));
    if (my_strcmp(var->arg_two_d[0], "cd") == 0)
        return (my_cd(var));
    if (my_strcmp(var->arg_two_d[0], "unsetenv") == 0)
        return (my_unsetenv(var));
    if (my_strcmp(var->arg_two_d[0], "setenv") == 0)
        return (my_setenv(var));
    return (0);
}
