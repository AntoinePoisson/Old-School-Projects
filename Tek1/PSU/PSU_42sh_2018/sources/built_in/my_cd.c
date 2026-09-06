/*
** EPITECH PROJECT, 2019
** my_cd.c
** File description:
** my_cd
*/

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_shell.h"

static int check_error_cd(variable_t *var, int *nbr_dir)
{
    DIR *result = NULL;
    int i = 1;

    if (is_extension_check_error_cd(var, &i) == 84) return (84);
    for (int save = 0; var->arg_two_d[i] != NULL && save != 1; i++, save++) {
        if ((result = is_extension_check_error_cd_two(var, i)) == NULL)
            return (84);
        if ((result = is_extension_check_error_cd_two(var, i)) != NULL &&
            (closedir(result)) == 0)
            *nbr_dir = i;
        else if (var->arg_two_d[i + 1] != NULL) {
            write(2, "cd: Too many arguments\n", 23);
            return (84);
        }
    }
    if (var->arg_two_d[i] != NULL) {
        write(2, "cd: Too many arguments\n", 23);
        return (84);
    }
    return (0);
}

static char *find_home(variable_t *var, char *home)
{
    int i = 0;
    int i_two = 0;
    int count = 0;

    if (research_env(var, "HOME", &i) == 0)
        return ("~");
    for (; var->env[i][i_two] != '=' && var->env[i][i_two] != '\0'; i_two++);
    if (var->env[i][i_two] == '=')
        i_two++;
    for (int save = i_two; var->env[i][save] != '\0'; count++, save++);
    if ((home = malloc(sizeof(char) * (count + 1))) == NULL)
        return ("~");
    for (count = 0; var->env[i][i_two] != '\0'; count++, i_two++) {
        home[count] = var->env[i][i_two];
        home[count + 1] = '\0';
    }
    return (home);
}

static void is_extension_change_env(variable_t *var)
{
    char pwd[] = "a PWD ";
    char *buf = NULL;
    char *result = NULL;

    if ((buf = malloc(sizeof(char) * 9999)) == NULL ||
        getcwd(buf, sizeof(char) * 9999) == NULL)
        write(2, "Cannot change in env: OLDPWD.\n", 27);
    else {
        result = my_strcat(pwd, buf);
        free(buf);
        if ((var->arg_two_d = my_str_to_word_array(result)) == NULL)
            write(2, "Cannot change in env: OLDPWD.\n", 27);
        else
            push(var, var->arg_two_d[1]);
    }
}

void change_env(variable_t *var)
{
    int i = 0;
    char *pwd = NULL;
    char *old_pwd = NULL;

    if (var->env == NULL || var->env[0] == NULL)
        return;
    if (research_env(var, "PWD", &i) == 0)
        is_extension_change_env(var);
    if ((old_pwd = find_env(var, "PWD")) == NULL)
        return;
    change_value_env(var, "OLDPWD", old_pwd);
    if ((pwd = malloc(sizeof(char) * 9999)) == NULL ||
        getcwd(pwd, sizeof(char) * 9999) == NULL) {
        write(2, "Cannot change in env: PWD.\n", 27);
        return;
    }
    change_value_env(var, "PWD", pwd);
}

int my_cd(variable_t *var)
{
    int nbr_dir = -1;
    static char *home = NULL;

    home == NULL ? (home = find_home(var, home)) : (home = home);
    if (check_error_cd(var, &nbr_dir) != 0)
        return (84);
    if (var->arg_two_d[1] != NULL && var->arg_two_d[1][0] == '-'
        && var->arg_two_d[1][1] == '\0')
        return (cd_flag_back(var));
    if (nbr_dir != -1) {
        if (chdir(var->arg_two_d[nbr_dir]) == -1) {
            perror("chdir");
            return (84);
        }
    } else if (chdir(home) == -1) {
        perror("chdir");
        return (84);
    }
    change_env(var);
    return (0);
}
