/*
** EPITECH PROJECT, 2018
** is_create_game.c
** File description:
** create element necessary for th party
*/

#include "defender.h"

void create_bg_game(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./resources/picture/bg_game.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.bg_game = Sprite;
    sf->texture.bg_game = Texture;
    sfSprite_setTexture(sf->sprite.bg_game, sf->texture.bg_game, sfTrue);
    sf->music.canon = sfMusic_createFromFile("./resources/music/canon.ogg");
    sf->music.attak = sfMusic_createFromFile("./resources/music/epee.wav");
    sf->music.bombe = sfMusic_createFromFile("./resources/music/explo.wav");
    sf->music.trampo = sfMusic_createFromFile("./resources/music/trampo.wav");
    sf->music.loss = sfMusic_createFromFile("./resources/music/wasted.ogg");
}

void is_initialization(variable_t *sf)
{
    sf->clock.game = sfClock_create();
    sf->var_norm.take_build = 0;
    sf->var_norm.id_of_take_build = -1;
    sf->var_norm.level = 0;
    sf->var_norm.quit_game = 0;
    sf->var_norm.nbr_node_list_obj = 0;
    sf->var_norm.nbr_node_list_build = 0;
    sf->vector.hdv.x = 0;
    sf->vector.hdv.y = 0;
    sf->var_norm.wave = 0;
    sf->enemy = NULL;
    sf->var_norm.money = GOLD;
    sf->text.font_money =
        sfFont_createFromFile("resources/font/Fipps-Regular.ttf");
    sf->text.text_money = sfText_create();
    sfText_setFont(sf->text.text_money, sf->text.font_money);
    sfText_setCharacterSize(sf->text.text_money, 25);
    sfText_setString(sf->text.text_money, my_itoa(sf->var_norm.money, 0));
    sf->build = NULL;
    sf->obj = NULL;
}

void create_pause(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./resources/picture/pause_game.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.pause_menu = Sprite;
    sf->texture.pause_menu = Texture;
    sfSprite_setTexture(sf->sprite.pause_menu, sf->texture.pause_menu, sfTrue);
}

int is_create_game(variable_t *sf)
{
    change_cursor(sf, 1);
    sfRenderWindow_setMouseCursorVisible(sf->win.dow, sfFalse);
    sf->var_norm.time_wave = WAIT_WAVE;
    sf->var_norm.effet = 0;
    sf->var_norm.kill = 0;
    sf->var_norm.timer = 0;
    sf->var_norm.reparation = 0;
    sf->var_norm.acceleration = 0;
    create_board_time(sf);
    is_initialization(sf);
    create_bg_game(sf);
    create_pause(sf);
    return (0);
}
