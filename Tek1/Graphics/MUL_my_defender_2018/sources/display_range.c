/*
** EPITECH PROJECT, 2019
** display_range
** File description:
** display range
*/

#include "defender.h"

sfIntRect is_extension_display_range(variable_t *sf, sfIntRect rect)
{
    if (sf->var_norm.id_of_take_build == 13) {
        rect.top = 443;
        rect.left = 971;
        rect.width = 369;
        rect.height = 343;
    }
    if (sf->var_norm.id_of_take_build != 11 &&
        sf->var_norm.id_of_take_build != 13) {
        rect.top = 204;
        rect.left = 1021;
        rect.width = 52;
        rect.height = 48;
    }
    if (sf->var_norm.id_of_take_build == 15) {
        rect.top = 204;
        rect.left = 1021;
        rect.width = 65;
        rect.height = 41;
    }
    return (rect);
}

void display_range(variable_t *sf, sfVector2i posi)
{
    sfIntRect rect;
    sfVector2f vector;

    rect = is_extension_display_range(sf, rect);
    vector.x = ((posi.x * 1.0) - (rect.width / 2));
    vector.y = ((posi.y * 1.0) - (rect.height / 2));
    sfSprite_setPosition(sf->sprite.resources, vector);
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
}
