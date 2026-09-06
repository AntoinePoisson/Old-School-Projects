/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display game of defender
*/

#include <stddef.h>
#include <stdlib.h>
#include "defender.h"

int control_hitbox_place_build(variable_t *sf, sfVector2i posi)
{
    build_t *save = sf->build;
    sfIntRect rect = find_rect(sf);

    for (int i = 1; i < sf->var_norm.nbr_node_list_build + 1 && save; i++) {
        if (is_extension_control_hitbox_place(save, rect, posi, i) != -1)
            return (is_extension_control_hitbox_place(save, rect, posi, i));
        save = save->next;
    }
    return (0);
}

void add_element_list(variable_t *sf, data_t *element, int id)
{
    obj_t *new_element = malloc(sizeof(*new_element));

    if (new_element == NULL)
        return;
    new_element->id = id;
    new_element->data = element;
    sf->var_norm.nbr_node_list_obj += 1;
    if (sf->var_norm.nbr_node_list_obj == 1) {
        new_element->next = NULL;
        sf->obj = new_element;
    } else {
        new_element->next = sf->obj;
        sf->obj = new_element;
    }
    if (id >= 10 && id <= 19)
        add_element_list_build(sf, element, id);
}

void add_element_list_build(variable_t *sf, data_t *element, int id)
{
    build_t *new_element = malloc(sizeof(build_t));

    if (new_element == NULL)
        return;
    new_element->id = id;
    new_element->data = element;
    sf->var_norm.nbr_node_list_build += 1;
    if (sf->var_norm.nbr_node_list_build == 1) {
        new_element->next = NULL;
        sf->build = new_element;
        return;
    }
    new_element->next = sf->build;
    sf->build = new_element;
}

void add_build(variable_t *sf, sfVector2f posi, int click)
{
    switch (sf->var_norm.id_of_take_build) {
        case 11: add_hdv(sf, posi);
            break;
        case 12: add_wall(sf, posi);
            break;
        case 13: add_cannon(sf, posi);
            break;
        case 14: add_bombe(sf, posi);
            break;
        case 15: add_tranpoline(sf, posi);
            break;
        default:
            break;
    }
    if (click == 1) {
        sf->var_norm.id_of_take_build = 0;
        sf->var_norm.take_build = 0;
    }
}
