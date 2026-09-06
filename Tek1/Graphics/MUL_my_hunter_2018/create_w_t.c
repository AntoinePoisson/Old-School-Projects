/*
** EPITECH PROJECT, 2018
** create_w_t
** File description:
** create_w_t
*/

#include "create.h"

void create_mccree_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mccree.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_robot_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Robot.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_mf_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Mf.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_lucky_luke_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Lucky.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}

void create_boss_w_t(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Boss.png", NULL);

    sf->texture.window_two = Texture;
    sf->sprite.window_two = Sprite;
    sf->vector.window_two.y = 196;
    sf->vector.window_two.x = 1036;
    sf->var_norm.choose_person_w_t = 1;
    sfSprite_setTexture(sf->sprite.window_two, sf->texture.window_two, sfTrue);
    sfSprite_setPosition(sf->sprite.window_two, sf->vector.window_two);
}
