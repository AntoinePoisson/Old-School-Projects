/*
** EPITECH PROJECT, 2018
** create_w_o
** File description:
** create_w_o
*/

#include "create.h"

void create_dalton_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Dalton.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_riven_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Riven.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_mccree_two_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mc_two.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_cowboy_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Cowboy.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_jinx_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Jinx.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}
