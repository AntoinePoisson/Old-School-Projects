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

unsigned int list_get_size(list_t list)
{
    int count = 0;

    while (list) {
        list = list->next;
        count++;
    }
    return (count);
}

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list) {
        val_disp(list->value);
        list = list->next;
    }
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t tmp = malloc(sizeof(*tmp));

    if (!tmp)
        return (false);
    tmp->value = elem;
    if (*front_ptr == NULL) {
        tmp->next = NULL;
        *front_ptr = tmp;
        return (true);
    }
    tmp->next = *front_ptr;
    *front_ptr = tmp;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t tmp = malloc(sizeof(*tmp));
    list_t save = *front_ptr;

    if (!tmp)
        return (false);
    (tmp)->value = elem;
    (tmp)->next = NULL;
    while ((*front_ptr) != NULL && (*front_ptr)->next != NULL)
        *front_ptr = (*front_ptr)->next;
    if ((*front_ptr)) {
        (*front_ptr)->next = tmp;
        *front_ptr = save;
    } else {
        (*front_ptr) = tmp;
    }
    return (true);
}