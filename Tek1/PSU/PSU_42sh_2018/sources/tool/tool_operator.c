/*
** EPITECH PROJECT, 2019
** tool_operator.c
** File description:
** tool_operator
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

int is_extension_check_operator_in_tree(char const *str, int ope, int i)
{
    if (str[i] == '>' && ope == 6)
        return (1);
    if (str[i] == '|' && str[i + 1] == '|' && ope == 7)
        return (1);
    if (str[i] == '&' && str[i + 1] == '&' && ope == 8)
        return (1);
    return (0);
}

int check_operator_in_tree(char const *str, int ope)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] == '(' && ope == 0)
            return (1);
        if (str[i] == ';' && ope == 1)
            return (1);
        if ((str[i] == '|' && str[i + 1] != '|' && ope == 2 && i == 0) ||
            (str[i] == '|' && str[i + 1] != '|' && ope == 2 && i > 0 &&
            str[i - 1] != '|'))
            return (1);
        if (str[i] == '<' && str[i + 1] == '<' && ope == 3)
            return (1);
        if (str[i] == '<' && ope == 4)
            return (1);
        if (str[i] == '>' && str[i + 1] == '>' && ope == 5)
            return (1);
        if (is_extension_check_operator_in_tree(str, ope, i) != 0)
            return (is_extension_check_operator_in_tree(str, ope, i));
    }
    return (0);
}

int compare_charac_and_operator(char const *str, int i, int ope)
{
    if (str[i] == '(' && ope == 0)
        return (1);
    if (str[i] == ';' && ope == 1)
        return (1);
    if ((str[i] == '|' && str[i + 1] != '|' && ope == 2 && i == 0) || (str[i]
        == '|' && str[i + 1] != '|' && ope == 2 && i > 0 && str[i - 1] != '|'))
        return (1);
    if (str[i] == '<' && str[i + 1] == '<' && ope == 3)
        return (2);
    if (str[i] == '<' && ope == 4)
        return (1);
    if (str[i] == '>' && str[i + 1] == '>' && ope == 5)
        return (2);
    if (str[i] == '>' && ope == 6)
        return (1);
    if (str[i] == '|' && str[i + 1] == '|' && ope == 7)
        return (2);
    if (str[i] == '&' && str[i + 1] == '&' && ope == 8)
        return (2);
    return (0);
}

int is_create_root_tree(variable_t *var)
{
    var->tree = malloc(sizeof(tree_t));

    if (var->tree == NULL)
        return (84);
    var->tree->data = var->arg;
    var->tree->operator = -1;
    var->tree->left = NULL;
    var->tree->right = NULL;
    return (0);
}

tree_t *is_initialisation_tree(tree_t *tree)
{
    if (tree == NULL)
        return (NULL);
    tree->data = NULL;
    tree->operator = -1;
    tree->left = NULL;
    tree->right = NULL;
    return (tree);
}
