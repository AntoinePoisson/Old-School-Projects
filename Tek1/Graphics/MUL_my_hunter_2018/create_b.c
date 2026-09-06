/*
** EPITECH PROJECT, 2018
** create_b
** File description:
** create_b
*/

#include "create.h"

void create_mccree_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mccree.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_robot_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Robot.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_mf_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mf.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_lucky_luke_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Lucky.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}

void create_boss_b(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Boss.png", NULL);

    sf->texture.back = Texture;
    sf->sprite.back = Sprite;
    sf->vector.back.y = 379;
    sf->vector.back.x = 787;
    sf->var_norm.acceleration_back = 1;
    sfSprite_setTexture(sf->sprite.back, sf->texture.back, sfTrue);
    sfSprite_setPosition(sf->sprite.back, sf->vector.back);
}
