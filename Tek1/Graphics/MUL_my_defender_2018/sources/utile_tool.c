/*
** EPITECH PROJECT, 2018
** utile_tool.c
** File description:
** utile_tool
*/

#include "defender.h"

void is_extension_reparation(build_t *save)
{
    if (save->id == 12) {
        save->data->rect.left = 0;
        save->data->rect.top = 160;
        save->data->rect.width = 21;
        save->data->rect.height = 32;
    }
    if (save->id == 13) {
        save->data->rect.left = 0;
        save->data->rect.top = 160;
        save->data->rect.width = 21;
        save->data->rect.height = 32;
    }
}

static void is_ext_reparation_build(build_t *save)
{
    if (save->data->hp <= 0)
        is_extension_reparation(save);
}

int reparation_build(variable_t *sf)
{
    build_t *save = sf->build;

    if (sf->var_norm.money < REPERATION_BUILD_COST)
        return (1);
    else
        sf->var_norm.money -= REPERATION_BUILD_COST;
    for (; save; save = save->next) {
        if (save->id != 11) {
            is_ext_reparation_build(save);
            save->data->hp = check_hp(save->id, 1);
        }
    }
    return (0);
}

int accelerer_time(variable_t *sf)
{
    if (sf->var_norm.wave == 1 || sf->var_norm.time_wave <= 30)
        return (1);
    sf->var_norm.time_wave = 335;
    return (0);
}

void change_cursor(variable_t *sf, int status)
{
    static int display = 1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(sf->win.dow);
    sfVector2f pos_m = {mouse.x * 1.0 - (23 / 2), mouse.y * 1.0 - (32.5 / 2)};
    sfIntRect rect;

    if (status == 0)
        display = 0;
    if (status == 1)
        display = 1;
    if (status == 0 || status == 1 || display == 0)
        return;
    rect.left = 0;
    rect.top = 2175;
    rect.width = 46;
    rect.height = 65;
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    sfSprite_setPosition(sf->sprite.resources, pos_m);
    sfRenderWindow_setMouseCursorVisible(sf->win.dow, sfFalse);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
}
