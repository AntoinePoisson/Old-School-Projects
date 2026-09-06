/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_shell.h"

Test(pop, pop)
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
        cr_expect_neq(pop(var), 1);
        free(var);
        free(env);
    }
}