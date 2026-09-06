/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_shell.h"

void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_command, my_command_exit, .init = redirect_all)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "exit";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        my_command(var);
        cr_stdout_match_str("exit\n");
        free(var);
        free(env);
    }
}

Test(my_command, my_command_env, .init = redirect_all)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "env";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        my_command(var);
        cr_stdout_match_str("PATH=/usr/local/bin\n");
        free(var);
        free(env);
    }
}

Test(my_command, my_command_cd)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "cd /";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_command(var), 0);
        free(var);
        free(env);
    }
}

Test(my_command, my_command_setenv, .init = redirect_all)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "setenv";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        my_command(var);
        cr_stdout_match_str("PATH=/usr/local/bin\n");
        free(var);
        free(env);
    }
}

Test(my_command, search_my_command_cd)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "cd /";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(my_command(var), 1);
        free(var);
        free(env);
    }
}

Test(my_command, search_my_command_env)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "env";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(my_command(var), 1);
        free(var);
        free(env);
    }
}

Test(my_command, search_my_command_setenv)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "setenv";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(my_command(var), 1);
        free(var);
        free(env);
    }
}

Test(my_command, search_my_command_unsetenv)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "unsetenv";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(my_command(var), 1);
        free(var);
        free(env);
    }
}

Test(my_command, search_my_command_exit)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "exit";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_command(var), 1);
        free(var);
        free(env);
    }
}

Test(my_command, search_my_command_fault)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "azertyuiop";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_command(var), 0);
        free(var);
        free(env);
    }
}

Test(search_command_in_path, search_command_in_path_fail)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin";
    char data[] = "azertyuiop";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(search_command_in_path(var), 0);
        free(var);
        free(env);
    }
}

Test(search_command_in_path, search_command_in_path)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/bin";
    char data[] = "ls";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(search_command_in_path(var), 1);
        free(var);
        free(env);
    }
}

Test(search_command_in_path, search_command_in_path_null)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 1);
    char data[] = "ls";

    env[0] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(search_command_in_path(var), 1);
        free(var);
        free(env);
    }
}

Test(test_command_in_path, test_command_in_path)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/bin";
    char data[] = "ls";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(test_command_in_path(var), 1);
        free(var);
        free(env);
    }
}

Test(test_command_in_path, test_command_in_path_fault)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/bin/";
    char data[] = "azertyuiop";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = my_strdup(data);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(test_command_in_path(var), 0);
        free(var);
        free(env);
    }
}