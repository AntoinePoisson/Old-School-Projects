/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "my_lib.h"
#include "csfml.h"
#include "my_struct.h"

void is_extension_destroy_menu(variable_t *sf)
{
    sfMusic_destroy(sf->music.bg);
    sfRenderWindow_close(sf->win.dow);
    sfRenderWindow_destroy(sf->win.dow);
}

void destroy_menu(variable_t *sf)
{
    sfSprite_destroy(sf->sprite.resources);
    sfTexture_destroy(sf->texture.resources);
    sfSprite_destroy(sf->sprite.menu);
    sfTexture_destroy(sf->texture.menu);
    sfSprite_destroy(sf->sprite.select);
    sfTexture_destroy(sf->texture.select);
    sfSprite_destroy(sf->sprite.play);
    sfTexture_destroy(sf->texture.play);
    sfSprite_destroy(sf->sprite.highscore);
    sfTexture_destroy(sf->texture.highscore);
    sfSprite_destroy(sf->sprite.quit);
    sfTexture_destroy(sf->texture.quit);
    sfSprite_destroy(sf->sprite.bg_menu);
    sfTexture_destroy(sf->texture.bg_menu);
    sfSprite_destroy(sf->sprite.end_level);
    sfTexture_destroy(sf->texture.end_level);
    is_extension_destroy_menu(sf);
}

void create_is_second_menu(variable_t *sf)
{
    sf->var_norm.quit_game = 1;
    sf->var_norm.quit_menu = 1;
    create_music(sf);
    create_menu(sf);
    create_end_level(sf);
    sf->clock.menu = sfClock_create();
}
