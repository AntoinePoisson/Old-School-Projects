/*
** EPITECH PROJECT, 2019
** tool_list.c
** File description:
** tool list algo
*/

#include <time.h>
#include <stdlib.h>
#include "my_struct.h"

void pop(variable_t *var, int *x, int *y)
{
    list_t *save = var->list;

    if (var->list == NULL)
        return;
    var->map[*y][*x] = '0';
    *x = var->list->x;
    *y = var->list->y;
    var->list = var->list->next;
    free(save);
}

int push(variable_t *var, int x, int y, int cas)
{
    list_t *element = malloc(sizeof(list_t));

    if (element == NULL)
        return (84);
    element->x = x;
    element->y = y;
    element->cas = cas;
    element->next = var->list;
    var->list = element;
    return (0);
}