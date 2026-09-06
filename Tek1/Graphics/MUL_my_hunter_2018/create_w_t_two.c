/*
** EPITECH PROJECT, 2018
** create_w_t
** File description:
** create_w_t
*/

#include "create.h"

void create_dalton_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Dalton.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_riven_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Riven.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_mccree_two_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mc_two.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_cowboy_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Cowboy.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_jinx_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Jinx.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}
