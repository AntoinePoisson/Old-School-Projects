/*
** EPITECH PROJECT, 2019
** is_create_tree.c
** File description:
** is_create_tree
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static tree_t *create_new_data_of_tree(tree_t *tree, char *data, int size,
    int operator)
{
    char *new = NULL;

    for (size = 0; data[size]; size++)
        if ((tree->operator = compare_charac_and_operator(data,
            size, operator)) != 0)
            break;
    if ((new = my_malloc(size + 1)) == NULL)
        return (NULL);
    for (int i = 0; i < size && data[i]; i++)
        new[i] = data[i];
    tree->left->data = new;
    operator = my_strlen(&data[size + tree->operator]);
    if ((new = my_malloc(operator + 1)) == NULL)
        return (NULL);
    operator = 0;
    for (int i = size + tree->operator; data[i]; i++, operator++)
        new[operator] = data[i];
    tree->right->data = new;
    return (tree);
}

static tree_t *is_extension_create_tree_(tree_t *tree, int operator)
{
    int size = 0;

    if ((tree->left = malloc(sizeof(tree_t))) == NULL)
        return (NULL);
    if ((tree->right = malloc(sizeof(tree_t))) == NULL)
        return (NULL);
    tree->left = is_initialisation_tree(tree->left);
    tree->right = is_initialisation_tree(tree->right);
    if ((tree = create_new_data_of_tree(tree, tree->data, size, operator))
        == NULL)
        return (NULL);
    tree->data = NULL;
    return (tree);
}

static tree_t *is_extension_create_tree(tree_t *tree)
{
    int ope = 0;
    int operator = 0;

    for (; operator == 0 && ope < 9; ope++)
        if ((operator = check_operator_in_tree(tree->data, ope)) != 0)
            break;
    if (operator != 0) {
        if ((tree = is_extension_create_tree_(tree, ope)) == NULL)
            return (NULL);
        tree->operator = ope;
    }
    return (tree);
}

tree_t *is_create_tree(tree_t *tree)
{
    if (tree->data)
        if ((tree = is_extension_create_tree(tree)) == NULL)
            return (NULL);
    if (tree->left)
        is_create_tree(tree->left);
    if (tree->right)
        is_create_tree(tree->right);
    return (tree);
}