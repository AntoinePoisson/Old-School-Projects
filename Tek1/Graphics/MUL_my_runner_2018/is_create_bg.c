/*
** EPITECH PROJECT, 2018
** is_create_bg
** File description:
** create_bg
*/

#include <stddef.h>
#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void create_bg_five(variable_t *sf);
void create_bg_six(variable_t *sf);
void create_bg_seven(variable_t *sf);
void create_bg_eight(variable_t *sf);
void create_bg_nine(variable_t *sf);

void create_bg_one(variable_t *sf)
{
    list_bg_t *SRC = malloc(sizeof(*SRC));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/floor.png", NULL);

    sf->bg = SRC;
    sf->bg->sprite = Sprite;
    sf->bg->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    sf->bg->offset = sf->var_norm.speed_background;
    sf->bg->position.x = 0;
    sf->bg->position.y = 0;
    sf->bg->rect.top = 0;
    sf->bg->rect.left = 0;
    sf->bg->rect.width = 1600;
    sf->bg->rect.height = 900;
    sfSprite_setPosition(sf->bg->sprite, sf->bg->position);
    sf->bg->next = NULL;
}

void create_bg_two(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/mini_mountain.png", NULL);

    obj->sprite = Sprite;
    obj->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    obj->offset = ((sf->var_norm.speed_background * 65) / 100);
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

void create_bg_three(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/degrade.png", NULL);

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

void create_bg_four(variable_t *sf)
{
    list_bg_t *obj = malloc(sizeof(*obj));
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/layers/rock.png", NULL);

    obj->sprite = Sprite;
    obj->texture = Texture;
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    obj->offset = ((sf->var_norm.speed_background * 40) / 100);
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

void create_bg(variable_t *sf)
{
    list_bg_t *save;

    create_bg_one(sf);
    create_bg_two(sf);
    create_bg_three(sf);
    create_bg_four(sf);
    create_bg_five(sf);
    create_bg_six(sf);
    create_bg_seven(sf);
    create_bg_eight(sf);
    create_bg_nine(sf);
    save = sf->bg;
    for (; sf->bg->next != NULL; sf->bg = sf->bg->next);
    sf->bg->next = save;
    sf->bg = sf->bg->next;
}
