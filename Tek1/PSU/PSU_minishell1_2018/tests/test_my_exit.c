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

void destroy_arg_two_d(var_t *var);
int destroy_env(var_t *var);
int my_exit(var_t *var, char *arg_nbr);
int check_error(var_t *var, char *env[]);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(destroy_env, destroy_env)
{
    var_t *var = malloc(sizeof(*var));
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
    var_t *var = malloc(sizeof(*var));
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

Test(my_exit, my_exit, .init = redirect_all_std)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "unsetenv PATH";

    check_error(var, env);
    var->arg_two_d = my_str_to_word_array(data);
    var->path = my_str_to_word_array(data);
    var->env = my_str_to_word_array(data);
    if (var != NULL || env != NULL) {
        my_exit(var, "84");
        cr_stdout_match_str("exit");
        free(var);
        free(env);
    }
}

Test(check_error_my_exit, my_exit_too_arg, .init = redirect_all_std)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "unsetenv PATH";

    check_error(var, env);
    var->arg_two_d = my_str_to_word_array(data);
    var->path = my_str_to_word_array(data);
    var->env = my_str_to_word_array(data);
    if (var != NULL || env != NULL) {
        my_exit(var, "84aze");
        cr_stdout_match_str("exit: Expression Syntax.\n");
        free(var);
        free(env);
    }
}