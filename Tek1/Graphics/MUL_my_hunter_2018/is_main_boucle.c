/*
** EPITECH PROJECT, 2018
** is_main_boucle
** File description:
** is_main_boucle
*/

#include "is_main_boucle.h"

void is_extension_main_boucle_four(variable_t *sf)
{
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.window_two, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.back, NULL);
    move_duck(110, 330, sf);
    move_ghost(124, 1717, sf);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_o, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_t, NULL);
    gestion_door_one(sf);
    gestion_door_two(sf);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.door_one, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.door_two, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_o_s, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_t_s, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.girl, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.heal_point, NULL);
    change_time_text(sf);
    sfRenderWindow_drawText(sf->win.dow, sf->text.time, NULL);
    sfRenderWindow_drawText(sf->win.dow, sf->text.score, NULL);
    if (sf->var_norm.shoot == 1)
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.shoot, NULL);
    change_cursor_mouse(sf);
}

void is_extension_main_boucle_three(variable_t *sf)
{
    sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
    if (sf->vector.twoi.x < 525 && sf->var_norm.last_position == 1) {
        sf->var_norm.last_position = 0;
        sfSprite_destroy(sf->sprite.girl);
        sfTexture_destroy(sf->texture.girl);
        create_girl_rev(sf);
    }
    if (sf->event.event.type == sfEvtMouseButtonPressed) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        sf->vector.shoot.x = sf->vector.twoi.x * 1.0 - 131.5;
        sf->vector.shoot.y = sf->vector.twoi.y * 1.0 - 106;
        sfMusic_play(sf->music.shoot);
        sf->var_norm.shoot = 1;
        sfSprite_setPosition(sf->sprite.shoot, sf->vector.shoot);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.shoot, NULL);
        change_cursor_mouse(sf);
    }
}

void is_extension_main_boucle_two(variable_t *sf)
{
    if (sf->event.event.type == sfEvtMouseMoved) {
        is_extension_main_boucle_three(sf);
        if (sf->vector.twoi.x >= 525 && sf->var_norm.last_position == 0) {
            sf->var_norm.last_position = 1;
            sfSprite_destroy(sf->sprite.girl);
            sfTexture_destroy(sf->texture.girl);
            create_girl_normal(sf);
        }
    }
    if (sf->event.event.type == sfEvtMouseButtonPressed) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        sf->vector.shoot.x = sf->vector.twoi.x * 1.0 - 131.5;
        sf->vector.shoot.y = sf->vector.twoi.y * 1.0 - 106;
        sfMusic_play(sf->music.shoot);
        sf->var_norm.shoot = 1;
        sfSprite_setPosition(sf->sprite.shoot, sf->vector.shoot);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.shoot, NULL);
        change_cursor_mouse(sf);
    }
}

void is_extension_main_boucle(variable_t *sf)
{
    sf->var_norm.shoot = 0;
    put_out_map_duck(sf);
    put_out_map_ghost(sf);
    kill_back(sf);
    kill_door_two(sf);
    kill_door_one(sf);
    kill_window_two(sf);
    kill_window_one(sf);
}

void main_boucle(variable_t *sf)
{
    while (sfRenderWindow_pollEvent(sf->win.dow, &sf->event.event) &&
        sf->var_norm.end_game == 0) {
        is_extension_main_boucle(sf);
        if (sf->event.event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(sf->win.dow);
        is_extension_main_boucle_two(sf);
    }
    sfRenderWindow_clear(sf->win.dow, sfBlack);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg, NULL);
    gestion_window_one(sf);
    gestion_window_two(sf);
    gestion_back(sf);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.window_one, NULL);
    is_extension_main_boucle_four(sf);
    sfRenderWindow_display(sf->win.dow);
}
