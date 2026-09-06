/*
** EPITECH PROJECT, 2018
** create_b
** File description:
** create_b
*/

#include "create.h"

void create_dalton_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Dalton.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_riven_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Riven.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_mccree_two_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mc_two.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_cowboy_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Cowboy.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_jinx_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Jinx.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}
