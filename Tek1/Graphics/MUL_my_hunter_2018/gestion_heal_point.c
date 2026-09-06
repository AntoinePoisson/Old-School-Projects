/*
** EPITECH PROJECT, 2018
** gestion_heal_point
** File description:
** gestion_heal_point
*/

#include "gestion_heal_point.h"

void is_extension_change_heal_point_two(variable_t *sf)
{
    if (sf->var_norm.heal_point == 4) {
        sfSprite_destroy(sf->sprite.heal_point);
        sfTexture_destroy(sf->texture.heal_point);
        create_heal_point_more_than_mid(sf);
    }
    if (sf->var_norm.heal_point == 3) {
        sfSprite_destroy(sf->sprite.heal_point);
        sfTexture_destroy(sf->texture.heal_point);
        create_heal_point_mid(sf);
    }
    if (sf->var_norm.heal_point == 2) {
        sfSprite_destroy(sf->sprite.heal_point);
        sfTexture_destroy(sf->texture.heal_point);
        create_heal_point_less_than_mid(sf);
    }
    if (sf->var_norm.heal_point == 1) {
        sfSprite_destroy(sf->sprite.heal_point);
        sfTexture_destroy(sf->texture.heal_point);
        create_heal_point_low(sf);
    }
}

void change_heal_point(variable_t *sf)
{
    float seconds = 0;

    if (sf->var_norm.heal_point == 5)
        create_heal_point_high(sf);
    is_extension_change_heal_point_two(sf);
    if (sf->var_norm.heal_point <= 0) {
        create_game_over(sf);
        sf->time.global = sfClock_getElapsedTime(sf->clock.global);
        seconds = sf->time.global.microseconds / 1000000.0;
        sf->var_norm.pause_door_one = seconds + 3;
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.game_over, NULL);
        sfRenderWindow_display(sf->win.dow);
        while (seconds <= (sf->var_norm.pause_door_one)) {
            sf->time.global = sfClock_getElapsedTime(sf->clock.global);
            seconds = sf->time.global.microseconds / 1000000.0;
        }
        sf->var_norm.end_game = 1;
    }
}
