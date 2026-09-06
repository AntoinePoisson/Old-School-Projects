/*
** EPITECH PROJECT, 2018
** kill_objet_two
** File description:
** kill_objet
*/

#include "kill_objet_two.h"

int kill_door_one(variable_t *sf)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        if (is_extension_kill_door_one(sf) == 1)
            return (1);
    }
    return (0);
}

int is_extension_kill_door_two(variable_t *sf)
{
    if (sfSprite_getPosition(sf->sprite.door_two).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.door_two).y)) {
        if (sfSprite_getPosition(sf->sprite.door_two).y + 145 >=
            sf->vector.twoi.y && sf->vector.twoi.x <=
            (sfSprite_getPosition(sf->sprite.door_two).x + 135)) {
            sfSprite_destroy(sf->sprite.door_two);
            sfTexture_destroy(sf->texture.door_two);
            create_door_two(sf);
            change_time_score(sf);
            if (sf->var_norm.acceleration_door_two < 7)
                sf->var_norm.acceleration_door_two += 0.2;
            return (1);
        }
    }
    return (0);
}

int kill_door_two(variable_t *sf)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        if (is_extension_kill_door_two(sf) == 1)
            return (1);
    }
    return (0);
}

int is_extension_kill_back(variable_t *sf)
{
    if (sfSprite_getPosition(sf->sprite.back).x <= sf->vector.twoi.x)
        if (sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.back).y))
        if (sfSprite_getPosition(sf->sprite.back).y + 145 >= sf->vector.twoi.y)
            if (sf->vector.twoi.x <=
                (sfSprite_getPosition(sf->sprite.back).x + 135)) {
            sfSprite_destroy(sf->sprite.back);
            sfTexture_destroy(sf->texture.back);
            create_back(sf);
            change_time_score(sf);
            if (sf->var_norm.acceleration_back < 7)
                sf->var_norm.acceleration_back += 0.2;
            return (1);
        }
    return (0);
}

int kill_back(variable_t *sf)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        if (is_extension_kill_back(sf) == 1)
            return (1);
    }
    return (0);
}
