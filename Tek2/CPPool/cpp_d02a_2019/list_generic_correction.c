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

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int pos)
{
    unsigned int size = list_get_size(*front_ptr);
    list_t tmp = malloc(sizeof(*tmp));
    list_t save = *front_ptr;

    if (pos > size || !tmp)
        return (false);
    if (pos == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    if (pos == size)
        return (list_add_elem_at_back(front_ptr, elem));
    tmp->value = elem;
    tmp->next = NULL;
    for (unsigned int i = 0; i + 1 < pos; i++)
        (*front_ptr) = (*front_ptr)->next;
    tmp->next = (*front_ptr)->next;
    (*front_ptr)->next = tmp;
    (*front_ptr) = save;
    return (true);
}

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t save = *front_ptr;

    if (*front_ptr == NULL)
        return (false);
    *front_ptr = (*front_ptr)->next;
    free(save);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t save = *front_ptr;
    list_t delete = NULL;

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

bool list_del_elem_at_position(list_t *front_ptr,
unsigned int position)
{
    list_t save = *front_ptr;
    list_t delete = NULL;

    if ((!front_ptr) || (position > list_get_size(*front_ptr)))
        return (false);
    if (position == list_get_size(*front_ptr))
        return (list_del_elem_at_back(front_ptr));
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    for (unsigned int i = 0; i + 1 < position; i++)
        *front_ptr = (*front_ptr)->next;
    delete = (*front_ptr)->next;
    (*front_ptr)->next = (*front_ptr)->next->next;
    (*front_ptr) = save;
    free(delete);
    return (true);
}

void list_clear(list_t *front)
{
    list_t save = *front;

    while (*front) {
        save = *front;
        *front = (*front)->next;
        free(save);
    }
    *front = NULL;
}