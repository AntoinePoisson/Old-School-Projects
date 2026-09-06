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
#include "my_struct.h"
#include "gnl.h"
#include "my_lib.h"

int is_minishell(var_t *var);
int check_error(var_t *var, char *env[]);

Test(is_minishell, is_minishell)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "unsetenv PATH";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->quit = 1;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_minishell(var), 0);
        free(var);
        free(env);
    }
}
