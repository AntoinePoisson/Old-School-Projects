/*
** EPITECH PROJECT, 2019
** add_build
** File description:
** add build
*/

#include <stdlib.h>
#include "defender.h"

void add_hdv(variable_t *sf, sfVector2f posi)
{
    data_t *element;

    if (check_multiple_hdv(sf) == 1
        || ((element = malloc(sizeof(data_t))) == NULL))
        return;
    element->status = 1;
    element->hp = HDV_HP;
    element->level = 1;
    element->damage = 0;
    element->move_speed = 0;
    element->position = posi;
    element->rect.left = 0;
    element->rect.top = 0;
    element->rect.width = 104;
    element->rect.height = 120;
    sf->vector.hdv.x = posi.x + (104 / 2);
    sf->vector.hdv.y = posi.y + (120 / 2);
    add_element_list(sf, element, 11);
}

void add_wall(variable_t *sf, sfVector2f posi)
{
    data_t *element;

    if (((element = malloc(sizeof(data_t))) == NULL))
        return;
    element->status = 1;
    element->hp = WALL_HP;
    element->level = 1;
    element->damage = 0;
    element->move_speed = 0;
    element->position = posi;
    element->rect.left = 0;
    element->rect.top = 160;
    element->rect.width = 21;
    element->rect.height = 32;
    add_element_list(sf, element, 12);
}

void add_bombe(variable_t *sf, sfVector2f posi)
{
    data_t *element;

    if (((element = malloc(sizeof(data_t))) == NULL))
        return;
    element->status = 1;
    element->hp = BOMBE_HP;
    element->level = 1;
    element->damage = BOMBE_DMG;
    element->move_speed = 0;
    element->position = posi;
    element->rect.left = 0;
    element->rect.top = 502;
    element->rect.width = 26;
    element->rect.height = 34;
    add_element_list(sf, element, 14);
}

void add_cannon(variable_t *sf, sfVector2f posi)
{
    data_t *element;

    if (((element = malloc(sizeof(data_t))) == NULL))
        return;
    element->status = 1;
    element->hp = CANNON_HP;
    element->level = 1;
    element->damage = CANNON_DMG;
    element->move_speed = 0;
    element->position = posi;
    element->rect.left = 1473;
    element->rect.top = 35;
    element->rect.width = 73;
    element->rect.height = 70;
    add_element_list(sf, element, 13);
}

void add_tranpoline(variable_t *sf, sfVector2f posi)
{
    data_t *element;

    if (((element = malloc(sizeof(data_t))) == NULL))
        return;
    element->status = 1;
    element->hp = TRANPOLINE_HP;
    element->level = 1;
    element->damage = TRANPOLINE_DMG;
    element->move_speed = 0;
    element->position = posi;
    element->rect.left = 0;
    element->rect.top = 652;
    element->rect.width = 72;
    element->rect.height = 78;
    add_element_list(sf, element, 15);
}
