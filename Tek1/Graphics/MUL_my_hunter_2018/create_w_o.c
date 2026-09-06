/*
** EPITECH PROJECT, 2018
** create_w_o
** File description:
** create_w_o
*/

#include "create.h"

void create_mccree_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mccree.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_robot_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Robot.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_mf_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mf.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_lucky_luke_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Lucky.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}

void create_boss_w_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Boss.png", NULL);

    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->vector.window_one.y = 196;
    sf->vector.window_one.x = 850;
    sf->var_norm.choose_person = 1;
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}
