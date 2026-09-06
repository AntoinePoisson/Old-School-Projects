/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "my_lib.h"
#include "csfml.h"
#include "struct.h"

void create_bg(variable_t *sf);
void create_music(variable_t *sf);
void create_menu(variable_t *sf);

void is_extension_destroy_menu(variable_t *sf)
{
    sfMusic_destroy(sf->music.bg_menu);
    sfMusic_destroy(sf->music.bg_game);
    sfMusic_destroy(sf->music.win);
    sfMusic_destroy(sf->music.loss);
    sfMusic_destroy(sf->music.jump);
    sfRenderWindow_close(sf->win.dow);
    sfRenderWindow_destroy(sf->win.dow);
}
void destroy_menu(variable_t *sf)
{
    for (int i = 1; i <= 9; i++, sf->bg = sf->bg->next) {
        sfSprite_destroy(sf->bg->sprite);
        sfTexture_destroy(sf->bg->texture);
    }
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
    is_extension_destroy_menu(sf);
}

void create_is_second_menu(variable_t *sf)
{
    sf->var_norm.speed_background = 10;
    sf->var_norm.quit_game = 1;
    sf->var_norm.menu = 1;
    create_music(sf);
    create_bg(sf);
    create_menu(sf);
    sf->clock.menu = sfClock_create();
}