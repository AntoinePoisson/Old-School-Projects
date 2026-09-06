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

bool double_btree_is_empty(double_btree_t tree)
{
    if (tree == NULL)
        return (true);
    return (false);
}

unsigned int double_btree_get_size(double_btree_t tree)
{
    if (tree == NULL)
        return (0);
    if (tree->left && tree->right)
        return (1 + double_btree_get_size(tree->left) +
        double_btree_get_size(tree->right));
    if (tree->left && !tree->right)
        return (1 + double_btree_get_size(tree->left));
    if (!tree->left && tree->right)
        return (1 + double_btree_get_size(tree->right));
    return (1);
}

unsigned int double_btree_get_depth(double_btree_t tree)
{
    int depth_left = 0;
    int depth_right = 0;

    if (tree == NULL)
        return (0);
    depth_left = double_btree_get_depth(tree->left);
    depth_right = double_btree_get_depth(tree->right);
    if (depth_left > depth_right)
        return (1 + depth_left);
    else
        return (1 + depth_right);
}