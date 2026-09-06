/*
** EPITECH PROJECT, 2018
** my_rev_list
** File description:
** rev_list element
*/

#include <unistd.h>
#include "my_list.h"

void rotation_end_list_two(control_list_t **SRC)
{
    linked_list_t *save = (*SRC)->head;

    write(1, "rrb ", 4);
    (*SRC)->head = (*SRC)->tail;
    (*SRC)->tail = save;
}

void rotation_first_list_one(control_list_t **SRC)
{
    linked_list_t *save = (*SRC)->head;

    write(1, "ra ", 3);
    (*SRC)->head = (*SRC)->head->next;
    (*SRC)->tail = save;
}

void rotation_first_list_two(control_list_t **SRC)
{
    linked_list_t *save = (*SRC)->head;

    write(1, "rb ", 3);
    (*SRC)->head = (*SRC)->head->next;
    (*SRC)->tail = save;
}