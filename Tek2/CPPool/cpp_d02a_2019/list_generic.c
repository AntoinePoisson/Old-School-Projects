/*
** EPITECH PROJECT, 2020
** ahhhh
** File description:
** helpme
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL) {
        list = list->next;
    }
    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    if ((!list) || (position > list_get_size(list)))
        return (0);
    if (position == list_get_size(list))
        return (list_get_elem_at_back(list));
    if (position == 0)
        return (list_get_elem_at_front(list));
    for (unsigned int i = 0; i < position; i++)
        list = list->next;
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    if (list == NULL)
        return (NULL);
    while (list && val_comp(list->value, value) != 0)
        list = list->next;
    if (list == NULL)
        return (NULL);
    return (&(*list));
}