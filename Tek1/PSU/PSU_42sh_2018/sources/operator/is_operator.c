/*
** EPITECH PROJECT, 2019
** is_operator.c
** File description:
** is_operator
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static int control_void_command(char const *cmd)
{
    int size = my_strlen(cmd);
    int nbr_espace = 0;

    if (size == 0 || cmd == NULL)
        return (1);
    for (int i = 0; (cmd[i] && cmd[i] == ' ') ||
        (cmd[i] && cmd[i] == '\t'); i++, nbr_espace++) {
    }
    if (nbr_espace == size)
        return (1);
    return (0);
}

int display_adapt_message_of_wrong_operator(int nbr_operator)
{
    if (nbr_operator == 1)
        return (my_puterror("Invalid null command.\n"));
    else
        return (my_puterror("Missing name for redirect.\n"));
    return (84);
}

int check_around_operator(char **arg, int i, int nbr_operator)
{
    if (nbr_operator == 0)
        return (0);
    if (i == 0)
        return (display_adapt_message_of_wrong_operator(1));
    if ((arg[i - 1] == NULL && nbr_operator != 1) || (arg[i + 1] == NULL) ||
        (control_void_command(arg[i - 1]) && nbr_operator != 1) ||
        (control_void_command(arg[i + 1])))
        return (display_adapt_message_of_wrong_operator(nbr_operator));
    if (check_operator(arg[i - 1]) != -1 || check_operator(arg[i + 1]) != -1)
        return (display_adapt_message_of_wrong_operator(nbr_operator));
    return (0);
}

static void destroy_tree(tree_t **tree)
{
    tree_t *save = NULL;

    save = (*tree);
    if (save && save->left != NULL)
        destroy_tree(&save->left);
    if (save && save->right != NULL)
        destroy_tree(&save->right);
    free(save->data);
    save->data = NULL;
    free(save);
    save = NULL;
    *tree = save;
}

int is_operator(variable_t *var)
{
    int value = 0;

    if (var->arg == NULL)
        return (0);
    if (((var->arg = check_parentheses(var->arg)) == NULL) ||
        ((var->arg_two_d = my_str_to_operator_array(var->arg)) == NULL) ||
        (check_right_operator(var->arg_two_d) == 84))
        return (1);
    if (is_create_root_tree(var) == 84)
        return (1);
    if ((var->tree = is_create_tree(var->tree)) == NULL)
        return (1);
    if (var->tree && var->tree->left == NULL && var->tree->right == NULL)
        return (exec_simple(var));
    value = chose_good_operator(var, var->tree);
    destroy_tree(&var->tree);
    free(var->tree);
    if (value == 84)
        return (1);
    return (value);
}