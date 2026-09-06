/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_shell.h"

Test(check_echec_exec, check_echec_exec)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    cr_expect_neq(check_echec_exec(var, 30, 123), 0);
}

Test(check_echec_exec, check_echec_exec2)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    cr_expect_neq(check_echec_exec(var, 3120, 123), 0);
}

Test(print_signal, print_signal)
{
    char arg[] = "ls | wc -l";

    cr_expect_eq(print_signal(arg, 123), 1);
}

Test(check_type_bin, check_type_bin)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->arg_two_d = malloc(sizeof(char *) * 2);
    var->arg_two_d[0] = arg;
    var->arg_two_d[1] = NULL;
    var->quit = 1;
    cr_expect_eq(check_type_bin(var), 0);
}

Test(check_type_bin, check_type_bin_true)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "./sources/ ls sqd";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->arg_two_d = malloc(sizeof(char *) * 2);
    var->arg_two_d[0] = arg;
    var->arg_two_d[1] = NULL;
    var->quit = 1;
    cr_expect_neq(check_type_bin(var), 1);
}

Test(check_echec_exec, check_echec_exec_one)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    cr_expect_neq(check_echec_exec(var, 1, 1), 0);
}

Test(check_echec_exec, check_echec_exec_two)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    cr_expect_neq(check_echec_exec(var, 13, 13), 0);
}

Test(check_echec_exec, check_echec_exec_three)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    cr_expect_neq(check_echec_exec(var, 30, 30), 0);
}

Test(check_echec_exec, check_echec_exec_four)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    cr_expect_neq(check_echec_exec(var, 37, 37), 0);
}

Test(check_echec_exec, check_echec_exec_five)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls | wc -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    cr_expect_neq(check_echec_exec(var, 47, 47), 0);
}
