/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static int create_path(variable_t *var)
{
    int i = 0;
    char *path =
        "a PATH /usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin";

    if (research_env(var, "PATH", &i) == 1)
        return (0);
    var->arg = path;
    var->arg_two_d = my_str_to_word_array(path);
    return (push(var, path));
}

static int create_path_two_d(variable_t *var)
{
    int i = 0;

    if (research_env(var, "PATH", &i) == 0)
        create_path(var);
    var->path = my_str_to_selec_array(&var->env[i][5], ':');
    if (var->path == NULL)
        return (1);
    return (0);
}

static int cpy_env(variable_t *var, char *env[])
{
    int count = 0;
    int i = 0;

    if (env == NULL)
        return (0);
    for (count = 0; env[count] != NULL; count++) {
    }
    if ((var->env = malloc(sizeof(char *) * (count + 3))) == NULL)
        return (1);
    for (; env[i] != NULL; i++) {
        if ((var->env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1)))
            == NULL)
            return (1);
        for (int i_two = 0; env[i][i_two] != '\0'; i_two++) {
            var->env[i][i_two] = env[i][i_two];
            var->env[i][i_two + 1] = '\0';
        }
    }
    var->env[i] = NULL;
    return (0);
}

static int is_init_struct(variable_t *var, char *env[])
{
    if (var == NULL)
        return (1);
    var->quit = 0;
    var->prev_pwd = NULL;
    var->arg = NULL;
    var->pwd = NULL;
    var->arg_two_d = NULL;
    var->env = NULL;
    var->alias = NULL;
    var->path = NULL;
    var->tree = NULL;
    if (cpy_env(var, env) == 1)
        return (1);
    if (create_path_two_d(var) == 1)
        return (1);
    return (0);
}

int check_error(variable_t *var, char *env[])
{
    if (is_init_struct(var, env) != 0) {
        write(2, "Error malloc.\n", 14);
        return (84);
    }
    return (0);
}
