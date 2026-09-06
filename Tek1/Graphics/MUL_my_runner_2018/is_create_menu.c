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
#include "struct.h"

void open_window(variable_t *sf);
int is_runner(variable_t *sf, char *av[], int ac);
void check_argument(char *av[], int ac, variable_t *sf);
void create_bg(variable_t *sf);
void create_end_level(variable_t *sf);
int open_file_highscore(void);
int analyse_file(char *file, int nbr);
void position_obj_menu(variable_t *sf);

void create_music(variable_t *sf)
{
    sfMusic *bg_game = sfMusic_createFromFile("./music/music_bg_game.ogg");
    sfMusic *bg_menu = sfMusic_createFromFile("./music/music_bg_menu.ogg");
    sfMusic *jump = sfMusic_createFromFile("./music/jump.ogg");
    sfMusic *win = sfMusic_createFromFile("./music/victory.ogg");
    sfMusic *loss = sfMusic_createFromFile("./music/wasted.ogg");

    sf->music.bg_game = bg_game;
    sf->music.bg_menu = bg_menu;
    sf->music.jump = jump;
    sf->music.win = win;
    sf->music.loss = loss;
    sfMusic_play(sf->music.bg_menu);
    sfMusic_setVolume(sf->music.bg_menu, 30.0);
    sfMusic_setVolume(sf->music.bg_game, 70.0);
    sfMusic_setLoop(sf->music.bg_menu, sfTrue);
}

void create_bg_highscore(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./images/menu_highscore.png", NULL);
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
    sfFont *font = sfFont_createFromFile("./font/segoe_print.ttf");

    sf->text.text_highscore = text;
    sf->text.font_highscore = font;
    sfText_setFont(sf->text.text_highscore, sf->text.font_highscore);
    sf->vector.message_highscore.x = 710;
    sf->vector.message_highscore.y = 445;
}

void create_obj_menu(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./images/play.png", NULL);
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture_one =
        sfTexture_createFromFile("./images/highscore.png", NULL);
    sfSprite *Sprite_one = sfSprite_create();
    sfTexture *Texture_two =
        sfTexture_createFromFile("./images/quit.png", NULL);
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
        sfTexture_createFromFile("./images/menu_full.png", NULL);
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture_one =
        sfTexture_createFromFile("./images/select.png", NULL);
    sfSprite *Sprite_one = sfSprite_create();

    create_obj_menu(sf);
    sf->sprite.menu = Sprite;
    sf->texture.menu = Texture;
    sf->sprite.select = Sprite_one;
    sf->texture.select = Texture_one;
    sf->vector.select.x = 0;
    sf->vector.select.y = -900;
    sfSprite_setTexture(sf->sprite.menu, sf->texture.menu, sfTrue);
    sfSprite_setTexture(sf->sprite.select, sf->texture.select, sfTrue);
    sfSprite_setPosition(sf->sprite.select, sf->vector.select);
}