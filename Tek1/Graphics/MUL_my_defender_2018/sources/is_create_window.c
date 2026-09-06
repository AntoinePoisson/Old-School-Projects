/*
** EPITECH PROJECT, 2018
** is_window_create
** File description:
** is_window_create
*/

#include "is_create_window.h"

void create_bg_menu(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./resources/picture/bg_menu.jpeg", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.bg_menu = Sprite;
    sf->texture.bg_menu = Texture;
    sfSprite_setTexture(sf->sprite.bg_menu, sf->texture.bg_menu, sfTrue);
}

void open_window(variable_t *sf)
{
    sfVideoMode Mode = {1600, 800, 32};

    sf->win.mode = Mode;
    sf->win.dow = sfRenderWindow_create(sf->win.mode, "My Defender",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(sf->win.dow, 60);
    sfRenderWindow_setKeyRepeatEnabled(sf->win.dow, 1);
}

void create_end_level(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./resources/picture/end_level.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.end_level = Sprite;
    sf->texture.end_level = Texture;
    sf->rect.end_level.left = 0;
    sf->rect.end_level.top = 0;
    sf->rect.end_level.width = 1600;
    sf->rect.end_level.height = 800;
    sfSprite_setTexture(sf->sprite.end_level, sf->texture.end_level, sfTrue);
}

void create_ressources(variable_t *sf)
{
    sfTexture *Texture;
    sfSprite *Sprite = sfSprite_create();

    if (sf->var_norm.mode_debug == 0)
        Texture =
            sfTexture_createFromFile("./resources/picture/resources.png", NULL);
    else
        Texture =
            sfTexture_createFromFile("./resources/picture/debug.png", NULL);
    sf->sprite.resources = Sprite;
    sf->texture.resources = Texture;
    sfSprite_setTexture(sf->sprite.resources, sf->texture.resources, sfTrue);
}
