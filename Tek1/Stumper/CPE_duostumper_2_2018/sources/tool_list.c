/*
** EPITECH PROJECT, 2019
** tool_list.c
** File description:
** tool_list
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_struct.h"

void add_element(variable_t *var, int x, int y)
{
    node_t *node = malloc(sizeof(node_t));

    node->x = x;
    node->y = y;
    node->next = var->list;
    var->list = node;
}

void delete_element(variable_t *var)
{
    if (var->list != NULL)
        var->list = var->list->next;
}

int research_list(variable_t *var, int x, int y)
{
    node_t *save = var->list;

    for (; save; save =save->next)
        if (save->x == x && save->y == y)
            return (1);
    return (0);
}

void recovery_last_posi(variable_t *var, int *x, int *y)
{
    if (var->list->next != NULL) {
        *x = var->list->next->x;
        *y = var->list->next->y;
    }
}
