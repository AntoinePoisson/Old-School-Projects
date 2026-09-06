/*
** EPITECH PROJECT, 2019
** is_operator.c
** File description:
** is_operator
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include "my_shell.h"

char *purge_name_file(char const * file)
{
    int size = 0;
    int i = 0;
    char *new_file = NULL;

    if (file == NULL)
        return (NULL);
    for (; (file[i] == ' ' && file[i]) ||
        (file[i] == '\t' && file[i]); i++);
    for (; file[i] && file[i] != ' ' && file[i] != '\t'; i++, size++);
    if (((new_file = my_malloc(size + 1)) == NULL))
        return (NULL);
    for (i = 0; (file[i] == ' ' && file[i])
        || (file[i] == '\t' && file[i]); i++);
    for (size = 0; file[i] != ' ' && file[i] != '\t' && file[i]; i++, size++)
        new_file[size] = file[i];
    return (new_file);
}

int check_element_is_operator(tree_t *tree)
{
    if (tree == NULL)
        return (0);
    if (tree->operator != -1)
        return (1);
    return (0);
}

int display_error_fork(int cas, char const *file)
{
    if (cas == 1) {
        my_puterror(file);
        return (my_puterror(": No such file or directory.\n"));
    }
    perror("fork");
    return (84);
}

int chose_good_operator(variable_t *var, tree_t *tree)
{
    switch (tree->operator) {
        case 0: return (control_parentheses(var, tree));
        case 1: return (control_semicolon(var, tree));
        case 2: return (control_pipe(var, tree));
        case 3: return (control_double_left_chevron(var, tree));
        case 4: return (control_left_chevron(var, tree));
        case 5: return (control_double_right_chevron(var, tree));
        case 6: return (control_right_chevron(var, tree));
        case 7: return (control_double_pipe(var, tree));
        case 8: return (control_double_ampersand(var, tree));
        default : return (1);
    }
    return (1);
}

int exec_simple(variable_t *var)
{
    int value_return = 0;

    if (var->tree == NULL || var->tree->data == NULL)
        return (84);
    value_return = exec_arg(var, var->tree->data);
    free(var->tree);
    var->tree = NULL;
    return (value_return);
}