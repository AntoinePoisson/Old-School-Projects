/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my_struct.h"

void change_env(var_t *var);
int is_extension_check_error_cd(var_t *var, int *i);
int research_env(var_t *var, char const *str, int *i);
char *find_env(var_t *var, char const *str);
int change_value_env(var_t *var, char const *element, char const *data);
int push(var_t *var, char const *str);
char my_stat(char const *dir, int cas);
int check_permission(char *dir);
DIR *is_extension_check_error_cd_two(var_t *var, int i);
int check_permission(char *dir);
int cd_flag_back(var_t *var);
int check_flag_cd(char const *arg);
int is_extension_check_error_cd(var_t *var, int *i);
DIR *is_extension_check_error_cd_two(var_t *var, int i);
int check_permission(char *dir);
int cd_flag_back(var_t *var);
int check_error(var_t *var, char *env[]);


Test(cd_flag_back, cd_flag_back_no_oldpwd)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PWD=/home/";
    char data[] = "cd -";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(cd_flag_back(var), 0);
        free(var);
        free(env);
    }
}

Test(cd_flag_back, cd_flag_back_no_pwd)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "OLDPWD=/home/";
    char data[] = "cd -";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(cd_flag_back(var), 0);
        free(var);
        free(env);
    }
}

Test(cd_flag_back, cd_flag_back)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 3);
    char *data_env = "OLDPWD=/home/";
    char *data_env_two = "PWD=/";
    char data[] = "cd -";

    env[0] = data_env;
    env[1] = data_env_two;
    env[2] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(cd_flag_back(var), 0);
        free(var);
        free(env);
    }
}

Test(check_permission, check_permission)
{
    char data[] = "/home";

    cr_expect_eq(check_permission(data), 0);
}

Test(check_permission, check_permission_no_access)
{
    char data[] = "/root";

    cr_expect_eq(check_permission(data), 84);
}

Test(is_extension_check_error_cd_two, is_extension_check_error_cd_two)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 3);
    char *data_env = "./sources/";
    char *data_env_two = "PWD=/";
    char data[] = "cd ./sources/";

    env[0] = data_env;
    env[1] = data_env_two;
    env[2] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_extension_check_error_cd_two(var, 0), NULL);
        free(var);
        free(env);
    }
}

Test(is_extension_check_error_cd_two, is_extension_check_error_cd_two_dir)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 3);
    char *data_env = "/root";
    char *data_env_two = "PWD=/";
    char data[] = "cd /root";

    env[0] = data_env;
    env[1] = data_env_two;
    env[2] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_extension_check_error_cd_two(var, 0), NULL);
        free(var);
        free(env);
    }
}

Test(is_extension_check_error_cd_two, is_extension_check_error_cd_two_fil)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 3);
    char *data_env = "./sources/main.c";
    char *data_env_two = "PWD=/";
    char data[] = "cd ./sources/main.c";

    env[0] = data_env;
    env[1] = data_env_two;
    env[2] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_extension_check_error_cd_two(var, 0), NULL);
        free(var);
        free(env);
    }
}

Test(is_extension_check_error_cd, is_extension_check_error_cd_fault_flag)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 3);
    char *data_env = "./sources/main.c";
    char *data_env_two = "PWD=/";
    char data[] = "cd -hzer";
    int i = 0;

    env[0] = data_env;
    env[1] = data_env_two;
    env[2] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(is_extension_check_error_cd(var, &i), 84);
        free(var);
        free(env);
    }
}

Test(is_extension_check_error_cd, is_extension_check_error_cd_fault)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 3);
    char *data_env = "./sources/main.c";
    char *data_env_two = "PWD=/";
    char data[] = "cd -l";
    int i = 0;

    env[0] = data_env;
    env[1] = data_env_two;
    env[2] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_eq(is_extension_check_error_cd(var, &i), 0);
        free(var);
        free(env);
    }
}

Test(check_flag_cd, check_flag_cd)
{
    char data[] = "-l";

    cr_expect_neq(check_flag_cd(data), 0);
}

Test(check_flag_cd, check_flag_cd_go_back)
{
    char data[2];

    data[0] = '-';
    data[1] = '\0';
    cr_expect_eq(check_flag_cd(data), 0);
}

Test(check_flag_cd, check_flag_cd_fault_flag)
{
    char data[] = "-KAKA";

    cr_expect_eq(check_flag_cd(data), 1);
}

Test(check_flag_cd, check_flag_cd_fault_flag_two)
{
    char data[] = "KAKA";

    cr_expect_eq(check_flag_cd(data), 1);
}