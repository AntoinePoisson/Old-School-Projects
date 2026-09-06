/*
** EPITECH PROJECT, 2018
** create_sprite_three
** File description:
** create_sprite_three
*/

#include "create_sprite_three.h"

void create_shoot(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/shoot.png", NULL);

    sf->texture.shoot = Texture;
    sf->sprite.shoot = Sprite;
    sfSprite_setTexture(sf->sprite.shoot, sf->texture.shoot, sfTrue);
    sfSprite_setPosition(sf->sprite.shoot, sf->vector.shoot);
}

void create_music(variable_t *sf)
{
    sfMusic *bg = sfMusic_createFromFile("./music/bg.ogg");
    sfMusic *shoot = sfMusic_createFromFile("./music/shoot.wav");

    sf->music.bg = bg;
    sf->music.shoot = shoot;
    sfMusic_play(sf->music.bg);
    sfMusic_setLoop(sf->music.bg, sfTrue);
}

void change_time_text(variable_t *sf)
{
    int seconds = sf->time.global.microseconds / 1000000.0;

    sfText_setString(sf->text.time, my_itoa(seconds, 0));
}

void create_text_time(variable_t *sf)
{
    sf->text.time = sfText_create();
    sf->text.font = sfFont_createFromFile("./font/Western.ttf");
    sf->vector.text_time.x = 772;
    sf->vector.text_time.y = 830;
    sfText_setFont(sf->text.time, sf->text.font);
    sfText_setPosition(sf->text.time, sf->vector.text_time);
    change_time_text(sf);
}

void change_time_score(variable_t *sf)
{
    int stokage = my_getnbr(sf->var_norm.char_text_score) + 10;

    sf->var_norm.char_text_score = my_itoa(stokage, 0);
    sfText_setString(sf->text.score, sf->var_norm.char_text_score);
}
