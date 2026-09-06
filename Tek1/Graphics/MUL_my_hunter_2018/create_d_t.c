/*
** EPITECH PROJECT, 2018
** create_d_t
** File description:
** create_d_t
*/

#include "create.h"

void create_mccree_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mccree.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_robot_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Robot.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_mf_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mf.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_lucky_luke_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Lucky.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}

void create_boss_d_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Boss.png", NULL);

    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->vector.door_two.y = 444;
    sf->vector.door_two.x = 117;
    sf->var_norm.choose_person_d_t = 1;
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}
