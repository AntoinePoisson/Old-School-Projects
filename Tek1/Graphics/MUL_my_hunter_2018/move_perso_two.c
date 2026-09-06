/*
** EPITECH PROJECT, 2018
** move_perso_two
** File description:
** move_perso
*/

#include "move_perso_two.h"

void move_ghost(int offset, int max_value, variable_t *sf)
{
    sfTime time_ghost;
    sfClock *clock_ghost;
    float seconds = 0;

    clock_ghost = sfClock_create();
    sf->rect.ghost.left += offset;
    is_extension_move_ghost(max_value, sf);
    while (seconds < 0.06 && sf->var_norm.end_game == 0) {
        time_ghost = sfClock_getElapsedTime(clock_ghost);
        seconds = time_ghost.microseconds / 1000000.0;
        sfSprite_setTexture(sf->sprite.ghost, sf->texture.ghost, sfTrue);
        sfSprite_setTextureRect(sf->sprite.ghost, sf->rect.ghost);
        sfSprite_setPosition(sf->sprite.ghost, sf->vector.ghost);
        sfRenderWindow_clear(sf->win.dow, sfBlack);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg, NULL);
        is_extension_move_ghost_two(sf);
        is_extension_move_ghost_three(sf);
        sfRenderWindow_display(sf->win.dow);
    }
}

void is_ext_put_out_map_duck(variable_t *sf)
{
    if (sf->var_norm.acceleration_duck < 40)
        sf->var_norm.acceleration_duck += 0.7;
    if (sf->var_norm.acceleration_duck < 70 &&
        sf->var_norm.acceleration_duck >= 40)
        sf->var_norm.acceleration_duck += 0.4;
    if (sf->var_norm.acceleration_duck > 90)
        sf->var_norm.acceleration_duck += 0.1;
}

void put_out_map_duck(variable_t *sf)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        if ((sfSprite_getPosition(sf->sprite.duck).x <= sf->vector.twoi.x) &&
            (sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.duck).y))) {
            if ((sfSprite_getPosition(sf->sprite.duck).y + 115 >=
                sf->vector.twoi.y) && (sf->vector.twoi.x <=
                (sfSprite_getPosition(sf->sprite.duck).x + 115))) {
                sf->vector.duck.y = rand_duck_y();
                sf->vector.duck.x = rand_duck_x(sf);
                is_ext_put_out_map_duck(sf);
                change_time_score(sf);
            }
        }
    }
}

void is_extension_move_duck(int max_value, variable_t *sf)
{
    if (sf->rect.duck.left >= max_value)
        sf->rect.duck.left = 0;
    if (sf->vector.duck.x < 1330)
        sf->vector.duck.x += sf->var_norm.acceleration_duck;
    if (sf->vector.duck.x >= 1330) {
        sf->var_norm.heal_point--;
        change_heal_point(sf);
        sf->vector.duck.y = rand_duck_y();
        sf->vector.duck.x = rand_duck_x(sf);
    }
}

void is_extension_move_duck_two(variable_t *sf)
{
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.window_one, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.window_two, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.back, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.ghost, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.duck, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_o, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_t, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.door_one, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.door_two, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_o_s, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_t_s, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.girl, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.heal_point, NULL);
    sfRenderWindow_drawText(sf->win.dow, sf->text.score, NULL);
    change_time_text(sf);
    sfRenderWindow_drawText(sf->win.dow, sf->text.time, NULL);
    if (sf->var_norm.shoot == 1)
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.shoot, NULL);
    change_cursor_mouse(sf);
}
