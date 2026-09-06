/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** utile funct for linked list
*/

#include "lem_in.h"

path_t *add_element_path(path_t *path, int index)
{
    path_t *temp = malloc(sizeof(path_t));

    if (temp == NULL)
        return (NULL);
    temp->index = index;
    temp->next = path;
    path = temp;
    return (path);
}

path_t *delete_element_path(path_t *path)
{
    if (path && path->next)
        path = path->next;
    return (path);
}

path_t *reverse_list(path_t *path)
{
    path_t *result = NULL;
    path_t *node = NULL;
    path_t *save = path;

    for (; save; save = save->next) {
        if ((node = malloc(sizeof(path_t))) == NULL)
            return (NULL);
        node->index = save->index;
        node->next = result;
        result = node;
    }
    return (result);
}

int count_element_path(path_t *path)
{
    int count = 0;

    for (path_t *temp = path; temp; temp = temp->next, count++) {
    }
    return (count);
}
