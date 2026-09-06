/*
** EPITECH PROJECT, 2019
** control_env.c
** File description:
** control_env
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static char **is_extension_push(variable_t *var, char **cpy, int i)
{
    int i_two = 0;

    if (var->arg_two_d[2] != NULL) {
        if ((cpy[i] = malloc(sizeof(char) * (my_strlen(var->arg_two_d[1]) +
            my_strlen(var->arg_two_d[2]) + 2))) == NULL)
            return (NULL);
    }
    else if ((cpy[i] = malloc(sizeof(char) * (my_strlen(var->arg_two_d[1])
        + 2))) == NULL)
        return (NULL);
    for (; var->arg_two_d[1][i_two] != '\0'; i_two++)
        cpy[i][i_two] = var->arg_two_d[1][i_two];
    cpy[i][i_two] = '=';
    i_two++;
    for (int i_three = 0; var->arg_two_d[2] != NULL &&
        var->arg_two_d[2][i_three] != '\0'; i_three++, i_two++)
        cpy[i][i_two] = var->arg_two_d[2][i_three];
    cpy[i][i_two] = '\0';
    return (cpy);
}

int push(variable_t *var, char const *str)
{
    int count = 0;
    int i = 0;
    char **cpy = NULL;

    for (count = 0; var->env[count] != NULL; count++) {
    }
    if ((cpy = malloc(sizeof(char *) * (count + 3))) == NULL)
        return (84);
    if (research_env(var, str, &i) == 1)
        return (change_value_env(var, str, var->arg_two_d[2]));
    for (i = 0; var->env[i] != NULL; i++)
        cpy[i] = var->env[i];
    if (is_extension_push(var, cpy, i) == NULL)
        return (84);
    cpy[i + 1] = NULL;
    free(var->env);
    var->env = cpy;
    return (0);
}

static char **is_extension_pop(variable_t *var, int *i, int *count, char **cpy)
{
    if (research_env(var, var->arg_two_d[1], i) == 0)
        return (NULL);
    for (; var->env[*count] != NULL; *count += 1);
    if ((cpy = malloc(sizeof(char *) * (*count))) == NULL)
        return (NULL);
    return (cpy);
}

int pop(variable_t *var)
{
    int i = 0;
    int i_two = 0;
    int count = 0;
    char **cpy = NULL;

    if ((cpy = is_extension_pop(var, &i, &count, cpy)) == NULL)
        return (84);
    for (int i_three = 0; var->env[i_three] != NULL; i_three++) {
        if (i_three != i) {
            cpy[i_two] = var->env[i_three];
            i_two++;
        }
        else
            free(var->env[i_three]);
    }
    cpy[i_two] = NULL;
    free(var->env);
    var->env = cpy;
    return (0);
}
