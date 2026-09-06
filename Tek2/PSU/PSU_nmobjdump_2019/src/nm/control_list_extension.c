/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** control_list_extension
*/

#include "nm.h"

void my_swap_node(node_t *one, node_t *two)
{
    unsigned int value = one->value;
    char type = one->type;
    char *name = one->name;
    char *name_sort = one->name_sort;

    one->name_sort = two->name_sort;
    one->value = two->value;
    one->type = two->type;
    one->name = two->name;
    two->name_sort = name_sort;
    two->value = value;
    two->type = type;
    two->name = name;
}

bool swap_eq(node_t *one, node_t *two)
{
    if (strcasecmp(one->name, two->name) != 0) {
        if (strcasecmp(one->name, two->name) < 0)
            my_swap_node(one, two);
        return (true);
    }
    if (one->value == two->value)
        return (false);
    if (one->value > two->value)
        my_swap_node(one, two);
    else
        my_swap_node(two, one);
    return (true);
}

bool is_extension_sort_list(data_elf_t *elf)
{
    node_t *init = elf->list_sym;
    bool change = false;

    for (node_t *i = init; i != NULL; i = i->next) {
        for (node_t *s = init; s != NULL; s = s->next) {
            if (strcasecmp(i->name_sort, s->name_sort) < 0) {
                my_swap_node(i, s);
                change = true;
            } else if (strcasecmp(i->name_sort, s->name_sort) == 0) {
                change = swap_eq(i, s);
            }
        }
    }
    elf->list_sym = init;
    return (change);
}