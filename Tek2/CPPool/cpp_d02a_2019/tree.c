/*
** EPITECH PROJECT, 2020
** tree
** File description:
** no
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <float.h>
#include "double_btree.h"

bool double_btree_create_node(double_btree_t *node_ptr, double value)
{
    double_btree_t new = malloc(sizeof(*new));

    if (!new || !node_ptr)
        return (false);
    new->value = value;
    new->right = NULL;
    new->left = NULL;
    (*node_ptr) = new;
    return (true);
}

bool double_btree_delete(double_btree_t *root_ptr)
{
    if (root_ptr == NULL)
        return (false);
    if (root_ptr && (*root_ptr)->left)
        double_btree_delete(&((*root_ptr)->left));
    if (root_ptr && (*root_ptr)->right)
        double_btree_delete(&((*root_ptr)->right));
    free(*root_ptr);
    root_ptr = NULL;
    return (true);
}

double double_btree_get_max_value(double_btree_t tree)
{
    double next_value_left = 0;
    double next_value_right = 0;

    if (tree == NULL)
        return (0);
    next_value_left = double_btree_get_max_value(tree->left);
    next_value_right = double_btree_get_max_value(tree->right);
    if (tree->value >= next_value_left && tree->value >= next_value_right)
        return (tree->value);
    if (next_value_left >= next_value_right && next_value_left >= tree->value)
        return (next_value_left);
    if (next_value_right >= next_value_left && next_value_right >= tree->value)
        return (next_value_right);
    return (DBL_MIN);
}

double double_btree_get_min_value(double_btree_t tree)
{
    static int i = 0;
    double next_value_left = 0;
    double next_value_right = 0;

    if (tree == NULL && i == 0)
        return (0);
    if (tree == NULL)
        return (DBL_MAX);
    i++;
    next_value_left = double_btree_get_min_value(tree->left);
    next_value_right = double_btree_get_min_value(tree->right);
    if (tree->value <= next_value_left && tree->value <= next_value_right)
        return (tree->value);
    if (next_value_left <= next_value_right && next_value_left <= tree->value)
        return (next_value_left);
    if (next_value_right <= next_value_left && next_value_right <= tree->value)
        return (next_value_right);
    return (DBL_MAX);
}
