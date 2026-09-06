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

void redirect_all_stdo(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(chose_good_operator, chose_good_operator)
{
    tree_t *tree = malloc(sizeof(tree_t));

    tree->operator = 87;
    cr_expect_neq(chose_good_operator(NULL, tree), 84);
}

Test(purge_name_file, purge_name_file_null)
{
    cr_expect_eq(purge_name_file(NULL), NULL);
}

Test(is_create_tree, is_create_tree_normal)
{
    tree_t *tree = malloc(sizeof(tree_t));

    tree->operator = -1;
    tree->left = NULL;
    tree->right = NULL;
    tree->data = "ls > toto ; cat < main.c";
    cr_expect_eq(is_create_tree(tree), tree);
}

Test(display_error_fork, display_error_fork_error_case)
{
    char *str = "main.c";

    cr_expect_eq(display_error_fork(1, str), 84);
}

Test(display_error_fork, display_error_fork_error_cas)
{
    char *str = "main.c";

    cr_expect_eq(display_error_fork(0, str), 84);
}

Test(purge_name_file, purge_name_file)
{
    char *arg = " file  ";
    char *result = "file";

    cr_expect_neq(purge_name_file(arg), result);
}

Test(check_element_is_operator, check_element_is_operator)
{
    tree_t *tree = malloc(sizeof(tree_t));

    tree->operator = 1;
    cr_expect_eq(check_element_is_operator(tree), 1);
}

Test(check_element_is_operator, check_element_is_operator2)
{
    tree_t *tree = malloc(sizeof(tree_t));

    tree->operator = -1;
    cr_expect_eq(check_element_is_operator(tree), 0);
}

Test(check_element_is_operator, check_element_is_operator_null)
{
    cr_expect_eq(check_element_is_operator(NULL), 0);
}

Test(is_operator, is_operator_pipe, .init = redirect_all_stdo)
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
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_operator(var), 0);
        free(var);
        free(env);
    }
}

Test(is_operator, is_operator_left_chevron, .init = redirect_all_stdo)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "cat < toto.c";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_operator(var), 0);
        free(var);
        free(env);
    }
}

Test(is_operator, is_operator_right_chevron, .init = redirect_all_stdo)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "cat Makefile > toto.c";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_operator(var), 0);
        free(var);
        free(env);
    }
}

Test(is_operator, is_operator_double_right_chevron, .init = redirect_all_stdo)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls >> toto.c";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_operator(var), 0);
        free(var);
        free(env);
    }
}

Test(is_operator, is_operator_semi_colon, .init = redirect_all_stdo)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls ; ls -l";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->alias = NULL;
    var->quit = 1;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_operator(var), 0);
        free(var);
        free(env);
    }
}

Test(is_operator, is_operator_multi_cmd)
{
    variable_t *var = malloc(sizeof(variable_t));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char arg[] = "ls ; ls -l | grep m ; cat < main.c > toto.c ; ; ls";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = arg;
    var->quit = 1;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(is_operator(var), 0);
        free(var);
        free(env);
    }
}
