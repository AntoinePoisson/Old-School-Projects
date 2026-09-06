/*
** EPITECH PROJECT, 2018
** is_create_bg_two
** File description:
** create_bg
*/

#include <stddef.h>
#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void create_bg_five(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/wind_two.png", NULL);

    obj->sprite = Sprite;
    obj->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    obj->offset = ((sf->var_norm.speed_background * 30) / 100);
    obj->position.x = 0;
    obj->position.y = 0;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = 1600;
    obj->rect.height = 900;
    sfSprite_setPosition(sf->bg->sprite, sf->bg->position);
    obj->next = sf->bg;
    sf->bg = obj;
}

void create_bg_six(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/wind.png", NULL);

    obj->sprite = Sprite;
    obj->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    obj->offset = ((sf->var_norm.speed_background * 30) / 100);
    obj->position.x = 0;
    obj->position.y = 0;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = 1600;
    obj->rect.height = 900;
    sfSprite_setPosition(sf->bg->sprite, sf->bg->position);
    obj->next = sf->bg;
    sf->bg = obj;
}

void create_bg_seven(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/mountain.png", NULL);

    obj->sprite = Sprite;
    obj->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    obj->offset = ((sf->var_norm.speed_background * 20) / 100);
    obj->position.x = 0;
    obj->position.y = 0;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = 1600;
    obj->rect.height = 900;
    sfSprite_setPosition(sf->bg->sprite, sf->bg->position);
    obj->next = sf->bg;
    sf->bg = obj;
}

void create_bg_eight(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/sun.png", NULL);

    obj->sprite = Sprite;
    obj->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    obj->offset = ((sf->var_norm.speed_background * 10) / 100);
    obj->position.x = 0;
    obj->position.y = 0;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = 1600;
    obj->rect.height = 900;
    sfSprite_setPosition(sf->bg->sprite, sf->bg->position);
    obj->next = sf->bg;
    sf->bg = obj;
}

void create_bg_nine(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/ground.png", NULL);

    obj->sprite = Sprite;
    obj->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    obj->offset = 0;
    obj->position.x = 0;
    obj->position.y = 0;
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = 1600;
    obj->rect.height = 900;
    sfSprite_setPosition(sf->bg->sprite, sf->bg->position);
    obj->next = sf->bg;
    sf->bg = obj;
}
