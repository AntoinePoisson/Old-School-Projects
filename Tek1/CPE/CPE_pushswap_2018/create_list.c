/*
** EPITECH PROJECT, 2018
** create_list
** File description:
** create_list
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_list.h"

control_list_t *create_list_control_l_a(control_list_t *l_a, int ac,
    char *av[])
{
    linked_list_t *element = malloc(sizeof(*element));

    l_a = malloc(sizeof(*l_a));
    if (l_a != NULL) {
        l_a->length = (ac - 1);
        l_a->tail = NULL;
        l_a->head = NULL;
        element->data = av[ac - 1];
        element->previous = NULL;
        element->next = NULL;
        l_a->head = element;
        l_a->tail = element;
        l_a->head->previous = l_a->tail;
        l_a->tail->next = l_a->head;
    }
    return (l_a);
}

control_list_t *create_list_control_l_b(control_list_t *l_b)
{
    linked_list_t *element = malloc(sizeof(*element));

    l_b = malloc(sizeof(*l_b));
    if (l_b != NULL) {
        l_b->length = 0;
        element->previous = element;
        element->next = element;
        l_b->head = element;
        l_b->tail = element;
        l_b->tail->next = l_b->head;
        l_b->head->previous = l_b->tail;
    }
    return (l_b);
}
