/*
** EPITECH PROJECT, 2018
** create_d_o
** File description:
** create_d_o
*/

#include "create.h"

void create_mccree_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mccree.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_robot_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Robot.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_mf_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mf.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_lucky_luke_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Lucky.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_boss_d_o(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Boss.png", NULL);

    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->vector.door_one.y = 103;
    sf->vector.door_one.x = 1475;
    sf->var_norm.choose_person_d_o = 1;
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}
