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

unsigned int double_list_get_size(double_list_t list)
{
    int count = 0;

    while (list) {
        list = list->next;
        count++;
    }
    return (count);
}

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void double_list_dump(double_list_t list)
{
    while (list) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t tmp = malloc(sizeof(*tmp));

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

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t tmp = malloc(sizeof(*tmp));
    double_list_t save = *front_ptr;

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