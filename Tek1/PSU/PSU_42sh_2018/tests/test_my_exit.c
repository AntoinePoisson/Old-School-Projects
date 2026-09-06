/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_shell.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(destroy_arg_two_d, destroy_arg_two_d_null)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data = malloc(sizeof(char) * 4);

    data[0] = 'A';
    data[1] = 'A';
    data[2] = 'A';
    data[3] = '\0';
    env[0] = data;
    env[1] = NULL;
    var->arg_two_d = NULL;
    var->env = env;
    if (var != NULL || env != NULL) {
        cr_expect_eq(destroy_env(var), NULL);
    }
}

Test(destroy_env, destroy_env)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data = malloc(sizeof(char) * 4);

    data[0] = 'A';
    data[1] = 'A';
    data[2] = 'A';
    data[3] = '\0';
    env[0] = data;
    env[1] = NULL;
    var->env = env;
    if (var != NULL || env != NULL) {
        cr_expect_eq(destroy_env(var), 0);
    }
}

Test(destroy_env, destroy_env_all)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data = malloc(sizeof(char) * 4);
    char *other = malloc(sizeof(char) * 4);
    char *other_two = malloc(sizeof(char) * 4);

    data[0] = 'A';
    data[1] = 'A';
    data[2] = 'A';
    data[3] = '\0';
    env[0] = data;
    env[1] = NULL;
    var->env = env;
    var->pwd = my_strcpy(other, data);
    var->prev_pwd = my_strcpy(other_two, data);
    if (var != NULL || env != NULL)
        cr_expect_eq(destroy_env(var), 0);
}

Test(check_error_my_exit, my_exit_too_arg, .init = redirect_all_std)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char data[] = "unsetenv PATH";

    check_error(var, env);
    var->arg_two_d = my_str_to_word_array(data);
    var->path = my_str_to_word_array(data);
    var->env = my_str_to_word_array(data);
    if (var != NULL || env != NULL) {
        my_exit(var, "84aze", 1);
        cr_stdout_match_str("exit: Expression Syntax.\n");
        free(var);
        free(env);
    }
}
