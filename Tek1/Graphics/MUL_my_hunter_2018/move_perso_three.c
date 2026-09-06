/*
** EPITECH PROJECT, 2018
** move_perso_three
** File description:
** move_perso
*/

#include "move_perso_three.h"

void move_duck(int offset, int max_value, variable_t *sf)
{
    sf->rect.duck.left += offset;
    is_extension_move_duck(max_value, sf);
    sfSprite_setTexture(sf->sprite.duck, sf->texture.duck, sfTrue);
    sfSprite_setTextureRect(sf->sprite.duck, sf->rect.duck);
    sfSprite_setPosition(sf->sprite.duck, sf->vector.duck);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg, NULL);
    put_out_map_duck(sf);
    is_extension_move_duck_two(sf);
    sfRenderWindow_display(sf->win.dow);
}
