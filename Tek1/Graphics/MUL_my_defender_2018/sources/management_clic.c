/*
** EPITECH PROJECT, 2019
** management_clic
** File description:
** manage the clic
*/

#include "defender.h"

float is_shift_click(variable_t *sf, int cas)
{
    if (cas == 1)
        switch (sf->var_norm.id_of_take_build) {
            case 11: return (52);
            case 12: return (10.5);
            case 13: return (36.5);
            case 14: return (13);
            case 15: return (30);
        }
    if (cas != 1)
        switch (sf->var_norm.id_of_take_build) {
            case 11: return (60);
            case 12: return (16);
            case 13: return (31.5);
            case 14: return (17);
            case 15: return (39);
        }
    return (0);
}

int click_in_map(sfVector2i posi)
{
    float equation_one = -0.75 * posi.x + 407.35;
    float equation_two = 0.75 * posi.x - 412.38;
    float equation_three = -0.75 * posi.x + 1192.18;
    float equation_four = 0.75 * posi.x + 384.79;

    if (equation_one > posi.y || equation_two > posi.y ||
        equation_three < posi.y || equation_four < posi.y)
        return (0);
    return (1);
}

void management_click(variable_t *sf, int click)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(sf->win.dow);
    sfVector2f converte = {0, 0};

    if (posi.x < 1094 && click_in_map(posi) == 1) {
        if (sf->var_norm.take_build
            && control_hitbox_place_build(sf, posi) == 0
            && control_money(sf) == 0) {
            converte.x = posi.x * 1.0 - is_shift_click(sf, 1);
            converte.y = posi.y * 1.0 - is_shift_click(sf, 2);
            sf->var_norm.effet = 0;
            add_build(sf, converte, click);
        }
    } else {
        converte.x = posi.x;
        converte.y = posi.y;
        management_select_game_tool(sf, converte);
    }
}

void management_mouse(variable_t *sf)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(sf->win.dow);
    sfVector2f pos_mouse = {0, 0};
    sfIntRect rect = find_rect(sf);

    if (sf->var_norm.id_of_take_build == 11 && check_multiple_hdv(sf) == 1) {
        sf->var_norm.take_build = 0;
        sf->var_norm.id_of_take_build = 0;
        return;
    }
    if (sf->var_norm.take_build == 0)
        return;
    pos_mouse.x = mouse.x * 1.0 - (rect.width / 2);
    pos_mouse.y = mouse.y * 1.0 - (rect.height / 2);
    rect = check_rect(sf, rect, mouse);
    display_range(sf, mouse);
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    sfSprite_setPosition(sf->sprite.resources, pos_mouse);
    change_cursor(sf, 0);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
}
