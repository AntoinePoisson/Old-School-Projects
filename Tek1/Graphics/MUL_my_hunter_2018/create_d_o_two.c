/*
** EPITECH PROJECT, 2018
** create_d_o
** File description:
** create_d_o
*/

#include "create.h"

void create_dalton_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Dalton.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_riven_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Riven.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_mccree_two_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mc_two.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_cowboy_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Cowboy.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_jinx_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Jinx.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}
