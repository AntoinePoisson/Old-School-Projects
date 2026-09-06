/*
** EPITECH PROJECT, 2018
** create_sprite_two
** File description:
** create_sprite_two
*/

#include "create_sprite_two.h"

void create_window_two(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Void.png", NULL);

    sf->vector.window_two.y = -181;
    sf->vector.window_two.x = -842;
    sf->var_norm.choose_person_w_t = 0;
    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->var_norm.pause_window_two = rand_pause_window_t(sf);
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_back(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Void.png", NULL);

    sf->vector.back.y = -475;
    sf->vector.back.x = -1475;
    sf->var_norm.acceleration_back = 0;
    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->var_norm.pause_back = rand_pause_window_b(sf);
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_duck(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Duck.png", NULL);

    sf->vector.duck.y = rand_duck_y();
    sf->vector.duck.x = (rand() % (320 - 0) + 0);
    sf->rect.duck.top = 0;
    sf->rect.duck.left = 0;
    sf->rect.duck.width = 110;
    sf->rect.duck.height = 110;
    sf->texture.duck = Texture;
    sf->sprite.duck = Sprite;
    sf->var_norm.acceleration_duck = 20;
}

void create_girl_normal(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Girl_n.png", NULL);

    sf->vector.girl.y = 502;
    sf->vector.girl.x = 455;
    sf->texture.girl = Texture;
    sf->sprite.girl = Sprite;
    sfSprite_setTexture(sf->sprite.girl, sf->texture.girl, sfTrue);
    sfSprite_setPosition(sf->sprite.girl, sf->vector.girl);
}

void create_girl_rev(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Girl_r.png", NULL);

    sf->vector.girl.y = 502;
    sf->vector.girl.x = 455;
    sf->texture.girl = Texture;
    sf->sprite.girl = Sprite;
    sfSprite_setTexture(sf->sprite.girl, sf->texture.girl, sfTrue);
    sfSprite_setPosition(sf->sprite.girl, sf->vector.girl);
}
