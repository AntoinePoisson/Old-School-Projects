/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_shell.h"

Test(my_unsetenv, my_unsetenv)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "unsetenv PATH";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_unsetenv(var), 0);
        free(var);
        free(env);
    }
}

Test(my_unsetenv, my_unsetenv_null)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char data[] = "unsetenv PATH";

    var->env = NULL;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_unsetenv(var), 0);
        free(var);
        free(env);
    }
}

Test(my_unsetenv, my_unsetenv_too_arg)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char data[] = "unsetenv";
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_unsetenv(var), 84);
        free(var);
        free(env);
    }
}

Test(my_unsetenv, my_unsetenv_mult)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 3);
    char data[] = "unsetenv PATH ENV";
    char *data_env = "PATH=/usr/local/bin:/usr/bin";

    env[0] = data_env;
    env[1] = "ENV=ZAEAZE";
    env[2] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_unsetenv(var), 0);
        free(var);
        free(env);
    }
}

Test(check_error_my_unsetenv, check_error_my_unsetenv)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char data[] = "unsetenv PATH";

    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(check_error_my_unsetenv(var), 0);
        free(var);
        free(env);
    }
}

Test(check_error_my_unsetenv, check_error_no_my_unsetenv)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char data[] = "unsetenv";

    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(check_error_my_unsetenv(var), 1);
        free(var);
        free(env);
    }
}
