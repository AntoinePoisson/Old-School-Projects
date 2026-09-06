/*
** EPITECH PROJECT, 2018
** is_close
** File description:
** is_close
*/

#include "create.h"

void is_extension_close(variable_t *sf)
{
    sfSprite_destroy(sf->sprite.bg_h_t_s);
    sfTexture_destroy(sf->texture.bg_h_t_s);
    sfSprite_destroy(sf->sprite.bg_h_o_s);
    sfTexture_destroy(sf->texture.bg_h_o_s);
    sfTexture_destroy(sf->texture.ghost);
    sfTexture_destroy(sf->texture.duck);
    sfSprite_destroy(sf->sprite.window_one);
    sfTexture_destroy(sf->texture.window_one);
    sfSprite_destroy(sf->sprite.window_two);
    sfTexture_destroy(sf->texture.window_two);
    sfSprite_destroy(sf->sprite.door_one);
    sfTexture_destroy(sf->texture.door_one);
    sfSprite_destroy(sf->sprite.door_two);
    sfTexture_destroy(sf->texture.door_two);
    sfSprite_destroy(sf->sprite.back);
    sfTexture_destroy(sf->texture.back);
    sfSprite_destroy(sf->sprite.girl);
    sfTexture_destroy(sf->texture.girl);
    sfTexture_destroy(sf->texture.shoot);
}

void is_close_prog(variable_t *sf)
{
    sfSprite_destroy(sf->sprite.bg);
    sfSprite_destroy(sf->sprite.ghost);
    sfSprite_destroy(sf->sprite.duck);
    sfTexture_destroy(sf->texture.bg);
    sfSprite_destroy(sf->sprite.bg_h_t);
    sfTexture_destroy(sf->texture.bg_h_t);
    sfSprite_destroy(sf->sprite.bg_h_o);
    sfTexture_destroy(sf->texture.bg_h_o);
    sfMusic_destroy(sf->music.bg);
    sfMusic_destroy(sf->music.shoot);
    sfSprite_destroy(sf->sprite.game_over);
    sfTexture_destroy(sf->texture.game_over);
    sfSprite_destroy(sf->sprite.heal_point);
    sfTexture_destroy(sf->texture.heal_point);
    sfFont_destroy(sf->text.font);
    sfText_destroy(sf->text.time);
    sfText_destroy(sf->text.score);
    sfSprite_destroy(sf->sprite.shoot);
    is_extension_close(sf);
}
