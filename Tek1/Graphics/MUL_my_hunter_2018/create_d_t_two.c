/*
** EPITECH PROJECT, 2018
** create_d_t
** File description:
** create_d_t
*/

#include "create.h"

void create_dalton_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Dalton.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_riven_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Riven.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_mccree_two_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mc_two.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_cowboy_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Cowboy.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_jinx_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Jinx.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}
