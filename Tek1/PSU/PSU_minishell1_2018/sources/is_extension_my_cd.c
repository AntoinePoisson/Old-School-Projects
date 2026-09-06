/*
** EPITECH PROJECT, 2019
** is_extension_my_cd.c
** File description:
** is_extension_my_cd
*/

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

int check_flag_cd(char const *arg)
{
    if (arg[0] == '-' && arg[1] == '\0')
        return (0);
    for (int i = 0; arg[i] != '\0'; i++) {
        if (i == 0 && arg[i] != '-')
            return (1);
        else if (arg[i] != 'l' && arg[i] != 'p' && arg[i] != 'v' &&
            arg[i] != 'n')
            return (1);
    }
    return (0);
}

int is_extension_check_error_cd(var_t *var, int *i)
{
    int value = 0;

    for (; var->arg_two_d[*i] != NULL && var->arg_two_d[*i][0] == '-';
        *i += 1) {
        if (check_flag_cd(var->arg_two_d[*i]) == 1) {
            write(2, "Usage: cd [-plvn][-|<dir>].\n", 28);
            value++;
            break;
        }
    }
    if (value != 0)
        return (84);
    return (0);
}

DIR *is_extension_check_error_cd_two(var_t *var, int i)
{
    DIR *result = NULL;

    if ((result = opendir(var->arg_two_d[i])) == NULL) {
        if (my_stat(var->arg_two_d[i], 0) != 'd') {
            write(2, var->arg_two_d[i], my_strlen(var->arg_two_d[i]));
            write(2, ": Not a directory.\n", 19);
            return (NULL);
        }
        else if (check_permission(var->arg_two_d[i]) == 84)
            return (NULL);
    }
    return (result);
}

int check_permission(char *dir)
{
    if (my_stat(dir, 1) != 'x') {
        write(2, dir, my_strlen(dir));
        write(2, ": Permission denied.\n", 21);
        return (84);
    }
    return (0);
}
int cd_flag_back(var_t *var)
{
    int i = 0;

    if (research_env(var, "OLDPWD", &i) == 0) {
        write(2, ": No such file or directory.\n", 29);
        return (0);
    }
    if (check_permission(find_env(var, "OLDPWD")) == 84)
        return (84);
    if (chdir(find_env(var, "OLDPWD")) == -1) {
        write(2, ": No such file or directory.\n", 29);
        return (84);
    }
    change_env(var);
    return (0);
}