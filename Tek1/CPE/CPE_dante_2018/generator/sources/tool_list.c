/*
** EPITECH PROJECT, 2019
** backtracker.c
** File description:
** backtracker algo
*/

#include <time.h>
#include <stdlib.h>
#include "my_struct.h"

int pop(variable_t *var, int *x, int *y)
{
    list_t *save = var->list;

    if (var->list == NULL)
        return (84);
    *x = var->list->x;
    *y = var->list->y;
    var->list = var->list->next;
    free(save);
    return (0);
}

int push(variable_t *var, int x, int y)
{
    list_t *element = malloc(sizeof(list_t));

    if (element == NULL)
        return (84);
    element->x = x;
    element->y = y;
    element->next = var->list;
    var->list = element;
    return (0);
}