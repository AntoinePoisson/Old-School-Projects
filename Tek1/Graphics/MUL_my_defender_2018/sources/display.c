/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display game of defender
*/

#include "defender.h"

void display_gold(variable_t *sf)
{
    sfText_setPosition(sf->text.text_money, (sfVector2f) {1350, 70});
    sfText_setColor(sf->text.text_money, sfBlack);
    sfText_setString(sf->text.text_money, my_itoa(sf->var_norm.money, 0));
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_money, NULL);
}

int control_display(obj_t *save, int count, int i, variable_t *sf)
{
    if ((count == 0 && save->data->hp <= 0) || (count == 0 && save->id == 15))
        return (1);
    if (count == 1 && i == 0)
        display_enemy(sf, 0);
    if (save->data->hp <= 0 && count != 2)
        return (0);
    if ((count == 1 && save->id == 13) ||
        (count == 1 && save->id == 11) ||
        (count == 1 && save->id == 12))
        return (1);
    if (count == 2 && i == 0)
        display_enemy(sf, 1);
    if ((count == 3 && save->id == 14))
        return (1);
    return (0);
}

void display_build(variable_t *sf)
{
    obj_t *save = sf->obj;

    for (int count = 0; count != 4; count++, save = sf->obj)
        is_extension_display_build(sf, save, count);
}

sfIntRect find_tool_effet_posi_two(int id, sfVector2f *posi, int cas,
    sfIntRect rect)
{
    if (id == 15 && cas == 0) {
        (*posi).y = 543;
        rect.top = 2595;
    }
    if (id == 5 && cas == 1) {
        rect.top = 2596;
        (*posi).y = 543;
    }
    if ((id == 6 && cas == 1) || (id == 30 && cas == 0)) {
        rect.top = 2725;
        (*posi).y = 672;
    }
    return (rect);
}

void display_game(variable_t *sf)
{
    sfRenderWindow_clear(sf->win.dow, sfBlack);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_game, NULL);
    display_help_in_game(sf);
    display_effet(sf);
    display_gold(sf);
    display_build(sf);
    display_hp(sf);
    if (sf->var_norm.take_build == 1)
        management_mouse(sf);
    else
        change_cursor(sf, 1);
    change_cursor(sf, 3);
    sfRenderWindow_display(sf->win.dow);
}
