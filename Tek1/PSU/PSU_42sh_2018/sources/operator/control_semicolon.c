/*
** EPITECH PROJECT, 2019
** control_semicolon.c
** File description:
** control semi colon execution
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static int management_semicolon(variable_t *var, char *arg)
{
    if (arg == NULL)
        return (0);
    return (exec_arg(var, arg));
}

int control_semicolon(variable_t *var, tree_t *tree)
{
    int return_value = 0;

    if (check_element_is_operator(tree->left))
        return_value = chose_good_operator(var, tree->left);
    else if (tree->left)
        return_value = management_semicolon(var, tree->left->data);
    if (check_element_is_operator(tree->right))
        return_value = chose_good_operator(var, tree->right);
    else if (tree->right)
        return_value = management_semicolon(var, tree->right->data);
    return (return_value);
}