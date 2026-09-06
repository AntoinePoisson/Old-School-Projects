/*
** EPITECH PROJECT, 2018
** create_menu
** File description:
** create_menu
*/

#include "create.h"

void create_menu_bg(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Menu.png", NULL);

    sf->clock.menu = sfClock_create();
    sf->sprite.bg_menu = Sprite;
    sf->texture.bg_menu = Texture;
    sfSprite_setTexture(sf->sprite.bg_menu, sf->texture.bg_menu, sfTrue);
    sfSprite_setPosition(sf->sprite.bg_menu, sf->vector.bg_h_o);
}

void create_menu_sprite_and_texture(variable_t *sf)
{
    sfSprite *sp_play = sfSprite_create();
    sfTexture *Tex_play = sfTexture_createFromFile("./images/play.png", NULL);
    sfSprite *sp_end = sfSprite_create();
    sfTexture *Tex_end = sfTexture_createFromFile("./images/end.png", NULL);

    sf->sprite.play = sp_play;
    sf->sprite.end = sp_end;
    sf->texture.end = Tex_end;
    sf->texture.play = Tex_play;
    sf->vector.play.y = 320;
    sf->vector.play.x = 817;
    sf->vector.end.y = 571;
    sf->vector.end.x = 877;
    sf->vector.bg_h_o.x = 0;
    sf->vector.bg_h_o.y = 0;
    sfSprite_setTexture(sf->sprite.play, sf->texture.bg_menu, sfTrue);
    sfSprite_setTexture(sf->sprite.end, sf->texture.bg_menu, sfTrue);
    sfSprite_setPosition(sf->sprite.play, sf->vector.play);
    sfSprite_setPosition(sf->sprite.end, sf->vector.end);
}
