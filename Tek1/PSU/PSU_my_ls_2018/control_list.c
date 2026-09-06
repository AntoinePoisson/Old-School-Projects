/*
** EPITECH PROJECT, 2019
** control_list
** File description:
** control_list
*/

#include <stdlib.h>
#include <stddef.h>
#include "./include/my_struct.h"

void add_element(flag_t *flag, char *data_element)
{
    recursive_t *element = malloc(sizeof(*element));

    if (element == NULL || flag->r == NULL || (data_element[0] == '.'
        && data_element[1] != '/' && data_element[1] != '\0'))
        return;
    element->data = data_element;
    element->next = flag->r;
    flag->r = element;
    flag->nbr_recursive += 1;
}

void push(flag_t *flag, char *data_element)
{
    recursive_t *element = malloc(sizeof(*element));

    if (flag->r == NULL || element == NULL || flag->r->next == NULL
        || (data_element[0] == '.' && data_element[1] != '/'
        && data_element[1] != '\0')) {
        add_element(flag, data_element);
        return;
    }
    element->data = data_element;
    element->next = flag->r->next;
    flag->r->next = element;
    flag->nbr_recursive += 1;
}

void pop(flag_t *flag)
{
    if (flag->r == NULL)
        return;
    flag->r = flag->r->next;
    flag->nbr_recursive -= 1;
}
