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
#include "my_lib.h"
#include "my_struct.h"

static int create_path_two_d(var_t *var);
static int cpy_env(var_t *var, char *env[]);
static int is_init_struct(var_t *var, char *env[]);
int check_error(var_t *var, char *env[]);

Test(check_error, check_error)
{
    var_t *var = malloc(sizeof(*var));
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
    var_t *var = malloc(sizeof(*var));
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
    var_t *var = malloc(sizeof(*var));
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