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

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    unsigned int size = double_list_get_size(*front_ptr);
    double_list_t tmp = malloc(sizeof(*tmp));
    double_list_t save = *front_ptr;

    if (position > size || !tmp)
        return (false);
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    if (position == size)
        return (double_list_add_elem_at_back(front_ptr, elem));
    tmp->value = elem;
    tmp->next = NULL;
    for (unsigned int i = 0; i + 1 < position; i++)
        (*front_ptr) = (*front_ptr)->next;
    tmp->next = (*front_ptr)->next;
    (*front_ptr)->next = tmp;
    (*front_ptr) = save;
    return (true);
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t save = *front_ptr;

    if (*front_ptr == NULL)
        return (false);
    *front_ptr = (*front_ptr)->next;
    free(save);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t save = *front_ptr;
    double_list_t delete = NULL;

    if (*front_ptr == NULL)
        return (false);
    if ((*front_ptr)->next == NULL) {
        (*front_ptr) = NULL;
        return (true);
    }
    while ((*front_ptr)->next->next != NULL)
        *front_ptr = (*front_ptr)->next;
    delete = (*front_ptr)->next;
    (*front_ptr)->next = NULL;
    (*front_ptr) = save;
    free(delete);
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr,
unsigned int position)
{
    double_list_t save = *front_ptr;
    double_list_t delete = NULL;

    if ((!front_ptr) || (position > double_list_get_size(*front_ptr)))
        return (false);
    if (position == double_list_get_size(*front_ptr))
        return (double_list_del_elem_at_back(front_ptr));
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    for (unsigned int i = 0; i + 1 < position; i++)
        *front_ptr = (*front_ptr)->next;
    delete = (*front_ptr)->next;
    (*front_ptr)->next = (*front_ptr)->next->next;
    (*front_ptr) = save;
    free(delete);
    return (true);
}