/*
** EPITECH PROJECT, 2018
** kill_objet
** File description:
** kill_objet
*/

#include "kill_objet.h"

int is_extension_kill_window_one(variable_t *sf)
{
    if (sfSprite_getPosition(sf->sprite.window_one).x <=
        sf->vector.twoi.x && sf->vector.twoi.y >=
        (sfSprite_getPosition(sf->sprite.window_one).y)) {
        if ((sfSprite_getPosition(sf->sprite.window_one).y + 145 >=
            sf->vector.twoi.y) && (sf->vector.twoi.x <=
            (sfSprite_getPosition(sf->sprite.window_one).x + 135))) {
            sfSprite_destroy(sf->sprite.window_one);
            sfTexture_destroy(sf->texture.window_one);
            create_window_one(sf);
            change_time_score(sf);
            if (sf->var_norm.acceleration_window_one < 7)
                sf->var_norm.acceleration_window_one += 0.2;
            return (1);
        }
    }
    return (0);
}

int kill_window_one(variable_t *sf)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        if (is_extension_kill_window_one(sf) == 1)
            return (1);
    }
    return (0);
}

int is_extension_kill_window_two(variable_t *sf)
{
    if (sfSprite_getPosition(sf->sprite.window_two).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.window_two).y)) {
        if ((sfSprite_getPosition(sf->sprite.window_two).y + 145 >=
            sf->vector.twoi.y) && (sf->vector.twoi.x <=
            (sfSprite_getPosition(sf->sprite.window_two).x + 135))) {
            sfSprite_destroy(sf->sprite.window_two);
            sfTexture_destroy(sf->texture.window_two);
            create_window_two(sf);
            change_time_score(sf);
            if (sf->var_norm.acceleration_window_two < 7)
                sf->var_norm.acceleration_window_two += 0.2;
            return (1);
        }
    }
    return (0);
}

int kill_window_two(variable_t *sf)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        if (is_extension_kill_window_two(sf) == 1)
            return (1);
    }
    return (0);
}

int is_extension_kill_door_one(variable_t *sf)
{
    if (sfSprite_getPosition(sf->sprite.door_one).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.door_one).y)) {
        if (sfSprite_getPosition(sf->sprite.door_one).y + 145 >=
            sf->vector.twoi.y && sf->vector.twoi.x <=
            (sfSprite_getPosition(sf->sprite.door_one).x + 135)) {
            sfSprite_destroy(sf->sprite.door_one);
            sfTexture_destroy(sf->texture.door_one);
            create_door_one(sf);
            change_time_score(sf);
            if (sf->var_norm.acceleration_door_one < 5)
                sf->var_norm.acceleration_door_one += 0.2;
            return (1);
        }
    }
    return (0);
}
