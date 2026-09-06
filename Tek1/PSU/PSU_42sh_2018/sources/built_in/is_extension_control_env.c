/*
** EPITECH PROJECT, 2019
** is_extension_control_env.c
** File description:
** is_extension_control_env
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static void is_extension_research_env(variable_t *var, char const *str,
    int *i, int *compare)
{
    for (int i_two = 0; var->env[*i][i_two] != '=' && *compare == 1;
        i_two++) {
        if (var->env[*i][i_two] != str[i_two])
            *compare = 0;
        if (str[i_two] == '\0' || var->env[*i][i_two] == '\0')
            *compare = 0;
    }
}

int research_env(variable_t *var, char const *str, int *i)
{
    int compare = 1;

    for (; var->env[*i] != NULL; *i += 1, compare = 1) {
        is_extension_research_env(var, str, i, &compare);
        if (compare == 1) {
            compare = 2;
            break;
        }
    }
    if (compare == 2)
        return (1);
    return (0);
}

int is_extension_change_value_env(variable_t *var, char *result)
{
    char *new_result = malloc(sizeof(char) * (my_strlen(result) + 3));
    int i_two = 0;

    new_result[i_two] = 'a';
    new_result[i_two + 1] = ' ';
    i_two = 2;
    for (int i = 0; result[i] != '\0'; i++, i_two++) {
        if (result[i] == '=')
            new_result[i_two] = ' ';
        else
            new_result[i_two] = result[i];
        new_result[i_two + 1] = '\0';
    }
    if ((var->arg_two_d = my_str_to_word_array(new_result)) == NULL)
        write(2, "Cannot change env.\n", 22);
    else
        push(var, var->arg_two_d[1]);
    free(result);
    return (0);
}

int change_value_env(variable_t *var, char const *element, char const *data)
{
    int i = 0;
    int i_two = 0;
    char *result = malloc(sizeof(char) * (my_strlen(element) +
        my_strlen(data) + 2));

    for (; element[i_two] != '\0'; i_two++)
        result[i_two] = element[i_two];
    result[i_two] = '=';
    i_two++;
    if (data != NULL)
        for (int i_three = 0; data[i_three] != '\0'; i_three++, i_two++)
            result[i_two] = data[i_three];
    result[i_two] = '\0';
    if (research_env(var, element, &i) == 1) {
        free(var->env[i]);
        var->env[i] = result;
    }
    else
        return (is_extension_change_value_env(var, result));
    return (0);
}

char *find_env(variable_t *var, char const *str)
{
    int i = 0;
    int i_two = 0;
    int count = 0;
    char *result = NULL;

    if (research_env(var, str, &i) == 0)
        return (NULL);
    for (; var->env[i][i_two] != '=' && var->env[i][i_two] != '\0'; i_two++);
    if (var->env[i][i_two] == '=')
        i_two++;
    for (int save = i_two; var->env[i][save] != '\0'; count++, save++);
    if ((result = malloc(sizeof(char) * (count + 1))) == NULL)
        return (NULL);
    for (count = 0; var->env[i][i_two] != '\0'; count++, i_two++) {
        result[count] = var->env[i][i_two];
        result[count + 1] = '\0';
    }
    return (result);
}
