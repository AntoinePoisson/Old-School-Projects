/*
** EPITECH PROJECT, 2018
** take_first_element
** File description:
** take_first_element
*/

#include <unistd.h>
#include "my_list.h"

void is_ext_take_element(control_list_t **DEST, linked_list_t *element)
{
    element->previous = (*DEST)->tail;
    element->next = (*DEST)->head;
    (*DEST)->head = element;
    (*DEST)->tail = element;
    (*DEST)->tail->next = (*DEST)->head;
    (*DEST)->head->previous = (*DEST)->tail;
    (*DEST)->length++;
}

void take_element_one(control_list_t **SRC, control_list_t **DEST)
{
    linked_list_t *element = (*SRC)->head;

    write(1, "pb ", 3);
    if (*SRC == NULL || element == NULL || (*SRC)->length == 0)
        return;
    (*SRC)->head = (*SRC)->head->next;
    (*SRC)->tail->next = (*SRC)->head;
    (*SRC)->head->previous = (*SRC)->tail;
    if ((*DEST)->length != 0) {
        element->previous = (*DEST)->tail;
        element->next = (*DEST)->head;
        (*DEST)->head = element;
        (*DEST)->tail->next = (*DEST)->head;
        (*DEST)->length++;
    }
    else
        is_ext_take_element(&(*DEST), element);
    (*SRC)->length--;
}

void take_element_two(control_list_t **DEST, control_list_t **SRC)
{
    linked_list_t *element = (*SRC)->head;

    write(1, "pa ", 3);
    if (*SRC == NULL || element == NULL || (*SRC)->length == 0)
        return;
    (*SRC)->head = (*SRC)->head->next;
    (*SRC)->tail->next = (*SRC)->head;
    (*SRC)->head->previous = (*SRC)->tail;
    if ((*DEST)->length != 0) {
        element->previous = (*DEST)->tail;
        element->next = (*DEST)->head;
        (*DEST)->head = element;
        (*DEST)->tail->next = (*DEST)->head;
        (*DEST)->length++;
    }
    else
        is_ext_take_element(&(*DEST), element);
    (*SRC)->length--;
}
