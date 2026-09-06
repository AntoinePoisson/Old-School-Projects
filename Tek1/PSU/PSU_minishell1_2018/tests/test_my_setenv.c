/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_lib.h"
#include "my_struct.h"

int my_setenv(var_t *var);
int check_error(var_t *var, char *env[]);

Test(my_setenv, my_setenv)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "setenv PATHE";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_setenv(var), 0);
        free(var);
        free(env);
    }
}

Test(my_setenv, my_setenv_too_many_arg)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "setenv PATHE azer AZER";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_setenv(var), 84);
        free(var);
        free(env);
    }
}

Test(my_setenv, my_setenv_one_arg)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "setenv";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_setenv(var), 84);
        free(var);
        free(env);
    }
}

Test(my_setenv, my_setenv_invalid_chif)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "setenv 5zae";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_setenv(var), 84);
        free(var);
        free(env);
    }
}

Test(my_setenv, my_setenv_invalid_charac)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "setenv Eza-e";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(my_setenv(var), 84);
        free(var);
        free(env);
    }
}