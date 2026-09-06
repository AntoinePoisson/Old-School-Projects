/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void display_bird(variable_t *sf);
void control_score(variable_t *sf);

int touch_dino_left_top(variable_t *sf, int *i, int *value_return)
{
    if (sfSprite_getPosition(sf->sprite.dino).x <= sf->obj->position.x
        && sf->obj->position.y >= (sfSprite_getPosition(sf->sprite.dino).y)) {
        if ((sfSprite_getPosition(sf->sprite.dino).y + (sf->rect.dino.height)
            >= (sf->obj->position.y)) && (sf->obj->position.x <=
            (sfSprite_getPosition(sf->sprite.dino).x +
            sf->rect.dino.width - 49))) {
            sf->var_norm.health_point -= 1;
            sf->var_norm.obstacle_touch = *i;
            *value_return = 1;
            return (1);
        }
    }
    return (0);
}

int touch_dino_right_top(variable_t *sf, int *i, int *value_return)
{
    if (sfSprite_getPosition(sf->sprite.dino).x <= sf->obj->position.x &&
        (sf->obj->position.y + (sf->obj->rect.height / 2)) >=
        (sfSprite_getPosition(sf->sprite.dino).y)) {
        if ((sfSprite_getPosition(sf->sprite.dino).y + (sf->rect.dino.height)
            >= (sf->obj->position.y + (sf->obj->rect.height / 2))) &&
            (sf->obj->position.x <= (sfSprite_getPosition(sf->sprite.dino).x +
            sf->rect.dino.width - 49))) {
            sf->var_norm.health_point -= 1;
            sf->var_norm.obstacle_touch = *i;
            *value_return = 1;
            return (1);
        }
    }
    return (0);
}

int touch_dino_mid_left(variable_t *sf, int *i, int *value_return)
{
    if (sfSprite_getPosition(sf->sprite.dino).x <= (sf->obj->position.x +
        sf->obj->rect.width - 15) && (sf->obj->position.y + 5) >=
        (sfSprite_getPosition(sf->sprite.dino).y)) {
        if ((sfSprite_getPosition(sf->sprite.dino).y + (sf->rect.dino.height)
            >= (sf->obj->position.y + 5)) && ((sf->obj->position.x +
            sf->obj->rect.width - 15) <=
            (sfSprite_getPosition(sf->sprite.dino).x +
            sf->rect.dino.width - 49))) {
            sf->var_norm.health_point -= 1;
            sf->var_norm.obstacle_touch = *i;
            *value_return = 1;
            return (1);
        }
    }
    return (0);
}

void is_extension_damage_dino_check(variable_t *sf, int *i, int *value_return)
{
    if (touch_dino_left_top(sf, i, value_return) == 1) {
        return;
    }
    if (touch_dino_right_top(sf, i, value_return) == 1) {
        return;
    }
    if (touch_dino_mid_left(sf, i, value_return) == 1) {
        return;
    }
}

int touch_bird_left_top(variable_t *sf, int *value_return)
{
    if (sfSprite_getPosition(sf->sprite.dino).x <= sf->bird->position.x &&
        sf->bird->position.y >= (sfSprite_getPosition(sf->sprite.dino).y)) {
        if ((sfSprite_getPosition(sf->sprite.dino).y + (sf->rect.dino.height)
            >= (sf->bird->position.y)) && (sf->bird->position.x <=
            (sfSprite_getPosition(sf->sprite.dino).x +
            sf->rect.dino.width - 49))) {
            sf->var_norm.health_point -= 1;
            sf->bird->position.x = -110;
            *value_return = 1;
            return (1);
        }
    }
    return (0);
}
