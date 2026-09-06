/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
#include "csfml.h"
#include "my_struct.h"

void create_music(variable_t *sf)
{
    sfMusic *bg =
        sfMusic_createFromFile("./resources/music/music_bg_menu.ogg");

    sf->music.bg = bg;
    sfMusic_play(sf->music.bg);
    sfMusic_setLoop(sf->music.bg, sfTrue);
}

void create_bg_highscore(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./resources/picture/menu_hs.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.bg_highscore = Sprite;
    sf->texture.bg_highscore = Texture;
    sf->vector.bg_highscore.x = 0;
    sf->vector.bg_highscore.y = -900;
    sfSprite_setTexture(sf->sprite.bg_highscore,
        sf->texture.bg_highscore, sfTrue);
    sfSprite_setPosition(sf->sprite.bg_highscore, sf->vector.bg_highscore);
}

void create_text_highscore(variable_t *sf)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./resources/font/segoe_print.ttf");

    sf->text.text_highscore = text;
    sf->text.font_highscore = font;
    sfText_setFont(sf->text.text_highscore, sf->text.font_highscore);
    sf->vector.message_highscore.x = 710;
    sf->vector.message_highscore.y = 445;
}

void create_obj_menu(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./resources/picture/play.png", NULL);
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture_one =
        sfTexture_createFromFile("./resources/picture/highscore.png", NULL);
    sfSprite *Sprite_one = sfSprite_create();
    sfTexture *Texture_two =
        sfTexture_createFromFile("./resources/picture/quit.png", NULL);
    sfSprite *Sprite_two = sfSprite_create();

    sf->sprite.play = Sprite;
    sf->texture.play = Texture;
    sf->sprite.highscore = Sprite_one;
    sf->texture.highscore = Texture_one;
    sf->sprite.quit = Sprite_two;
    sf->texture.quit = Texture_two;
    sfSprite_setTexture(sf->sprite.play, sf->texture.play, sfTrue);
    sfSprite_setTexture(sf->sprite.highscore, sf->texture.highscore, sfTrue);
    sfSprite_setTexture(sf->sprite.quit, sf->texture.quit, sfTrue);
    position_obj_menu(sf);
}

void create_menu(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./resources/picture/menu_full.png", NULL);
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture_one =
        sfTexture_createFromFile("./resources/picture/select.png", NULL);
    sfSprite *Sprite_one = sfSprite_create();

    create_obj_menu(sf);
    sf->sprite.menu = Sprite;
    sf->texture.menu = Texture;
    sf->sprite.select = Sprite_one;
    sf->texture.select = Texture_one;
    sf->vector.select.x = 0;
    sf->vector.select.y = -900;
    sf->var_norm.quit_menu = 0;
    sfSprite_setTexture(sf->sprite.menu, sf->texture.menu, sfTrue);
    sfSprite_setTexture(sf->sprite.select, sf->texture.select, sfTrue);
    sfSprite_setPosition(sf->sprite.select, sf->vector.select);
    create_ressources(sf);
    create_bg_menu(sf);
}
