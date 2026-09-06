/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_shell.h"

Test(check_error, check_error)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    if (var != NULL || env != NULL) {
        cr_expect_eq(check_error(var, env), 0);
        free(var);
        free(env);
    }
}

Test(create_path_two_d, create_path_two_d_null)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 1);

    env[0] = NULL;
    var->env = env;
    if (var != NULL || env != NULL) {
        cr_expect_eq(check_error(var, env), 0);
        free(var);
        free(env);
    }
}

Test(create_path_two_d, create_path_two_d_no_path)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PWD=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    if (var != NULL || env != NULL) {
        cr_expect_neq(check_error(var, env), 1);
        free(var);
        free(env);
    }
}
