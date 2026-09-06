/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void is_extension_damage_dino_check(variable_t *sf, int *i, int *value_return);
int touch_bird_left_top(variable_t *sf, int *value_return);

int touch_bird_left_mid(variable_t *sf, int *value_return)
{
    if (sfSprite_getPosition(sf->sprite.dino).x <=
        (sf->bird->position.x + (sf->bird->rect.width / 2)) &&
        (sf->bird->position.y + (sf->bird->rect.height)) >=
        (sfSprite_getPosition(sf->sprite.dino).y)) {
        if ((sfSprite_getPosition(sf->sprite.dino).y + (sf->rect.dino.height)
            >= (sf->bird->position.y + (sf->bird->rect.height))) &&
            (sf->bird->position.x + (sf->bird->rect.width / 2)) <=
            (sfSprite_getPosition(sf->sprite.dino).x +
            sf->rect.dino.width - 49)) {
            sf->var_norm.health_point -= 1;
            sf->bird->position.x = -110;
            *value_return = 1;
            return (1);
        }
    }
    return (0);
}

int touch_bird_bot_left(variable_t *sf, int *value_return)
{
    if (sfSprite_getPosition(sf->sprite.dino).x <= (sf->bird->position.x +
        (sf->bird->rect.width)) && (sf->bird->position.y +
        (sf->bird->rect.height / 2)) >=
        (sfSprite_getPosition(sf->sprite.dino).y)) {
        if ((sfSprite_getPosition(sf->sprite.dino).y + (sf->rect.dino.height)
            >= (sf->bird->position.y + (sf->bird->rect.height / 2))) &&
            (sf->bird->position.x + (sf->bird->rect.width)) <=
            (sfSprite_getPosition(sf->sprite.dino).x +
            sf->rect.dino.width - 49)) {
            sf->var_norm.health_point -= 1;
            sf->bird->position.x = -110;
            *value_return = 1;
            return (1);
        }
    }
    return (0);
}

void is_extension_damage_bird_check(variable_t *sf, int *value_return)
{
    if (touch_bird_left_top(sf, value_return) == 1) {
        return;
    }
    if (touch_bird_left_mid(sf, value_return) == 1) {
        return;
    }
    if (touch_bird_bot_left(sf, value_return) == 1) {
        return;
    }
}

int damage_dino_check(variable_t *sf)
{
    int value_return = 0;

    for (int i = 1; i <= sf->var_norm.nbr_obstacle; i++) {
        if (i != sf->var_norm.obstacle_touch)
            is_extension_damage_dino_check(sf, &i, &value_return);
        if (sf->var_norm.bird_mode == 1 && i <= 2) {
            is_extension_damage_bird_check(sf, &value_return);
            sf->bird = sf->bird->next;
        }
        sf->obj = sf->obj->next;
    }
    return (value_return);
}
