/*
** EPITECH PROJECT, 2019
** management_event.c
** File description:
** management event of game
*/

#include "defender.h"

int is_extension_control_money(variable_t *sf, int cas)
{
    if (cas == 11)
        return (0);
    if (cas == 12 && sf->var_norm.money < WALL_COST)
        return (1);
    else if (cas == 12 && sf->var_norm.money >= WALL_COST)
        sf->var_norm.money -= WALL_COST;
    if (cas == 13 && sf->var_norm.money < CANON_COST)
        return (1);
    else if (cas == 13 && sf->var_norm.money >= CANON_COST)
        sf->var_norm.money -= CANON_COST;
    if (cas == 14 && sf->var_norm.money < BOMBE_COST)
        return (1);
    else if (cas == 14 && sf->var_norm.money >= BOMBE_COST)
        sf->var_norm.money -= BOMBE_COST;
    if (cas == 15 && sf->var_norm.money < TRANPOLINE_COST)
        return (1);
    else if (cas == 15 && sf->var_norm.money >= TRANPOLINE_COST)
        sf->var_norm.money -= TRANPOLINE_COST;
    return (0);
}

sfIntRect is_extension_find_rect(variable_t *sf, int cas, sfIntRect save)
{
    sfIntRect rect = {1473, 35, 73, 63};

    if (cas == 11) {
        rect.left = 0;
        rect.top = 0;
        rect.width = 104;
        rect.height = 120;
    }
    if (cas == 12) {
        rect.left = 0;
        rect.top = 160;
        rect.width = 21;
        rect.height = 32;
    }
    if (cas == 30) {
        sf->var_norm.take_build = 0;
        sf->var_norm.id_of_take_build = 0;
        return (save);
    }
    return (rect);
}

int is_extension_control_hitbox_place_build_(build_t *save, sfIntRect rect,
    sfVector2i posi, int i)
{
    if (save->data->position.x <= posi.x - (rect.width / 2) && posi.y
        + (rect.height / 2) >= (save->data->position.y))
        if (save->data->position.y + save->data->rect.height >=
            posi.y + (rect.height / 2) &&
            (posi.x - (rect.width / 2) <= (save->data->position.x +
            save->data->rect.width)))
            return (i);
    return (-1);
}

int is_extension_control_hitbox_place_build(build_t *save, sfIntRect rect,
    sfVector2i posi, int i)
{
    if (save->data->position.x <= posi.x && posi.y >=
        (save->data->position.y))
        if ((save->data->position.y + save->data->rect.height >=
            posi.y) && (posi.x <= (save->data->position.x +
            save->data->rect.width)))
            return (i);
    if (save->data->position.x <= (posi.x + (rect.width / 2)) && (posi.y
        + (rect.height / 2)) >= (save->data->position.y))
        if (save->data->position.y + save->data->rect.height >=
            (posi.y + (rect.height / 2)) &&
            ((posi.x + (rect.width / 2)) <= (save->data->position.x +
            save->data->rect.width)))
            return (i);
    return (is_extension_control_hitbox_place_build_(save, rect, posi, i));
}

int is_extension_control_hitbox_place(build_t *save, sfIntRect rect,
    sfVector2i posi, int i)
{
    if (save->data->position.x <= (posi.x - (rect.width / 2)) && (posi.y
        - (rect.height / 2)) >= (save->data->position.y))
        if (save->data->position.y + save->data->rect.height >=
            (posi.y - (rect.height / 2)) &&
            ((posi.x - (rect.width / 2)) <= (save->data->position.x +
            save->data->rect.width)))
            return (i);
    if (save->data->position.x <= posi.x + (rect.width / 2) && posi.y
        - (rect.height / 2) >= (save->data->position.y))
        if (save->data->position.y + save->data->rect.height >=
            posi.y - (rect.height / 2) &&
            (posi.x + (rect.width / 2) <= (save->data->position.x +
            save->data->rect.width)))
            return (i);
    return (is_extension_control_hitbox_place_build(save, rect, posi, i));
}
