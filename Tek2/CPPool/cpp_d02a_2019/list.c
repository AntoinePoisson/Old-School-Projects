/*
** EPITECH PROJECT, 2020
** help
** File description:
** me
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL) {
        list = list->next;
    }
    return (list->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    if ((!list) || (position > double_list_get_size(list)))
        return (0);
    if (position == double_list_get_size(list))
        return (double_list_get_elem_at_back(list));
    if (position == 0)
        return (double_list_get_elem_at_front(list));
    for (unsigned int i = 0; i < position; i++)
        list = list->next;
    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    if (list == NULL)
        return (NULL);
    while (list && list->value != value)
        list = list->next;
    if (list == NULL)
        return (NULL);
    return (&(*list));
}