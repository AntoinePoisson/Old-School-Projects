/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void create_text_score(variable_t *sf)
{
    sf->text.score = sfText_create();
    sf->text.font_score =
        sfFont_createFromFile("./font/SFPixelate_BoldOblique.ttf");

    sf->vector.message_score.x = 25;
    sf->vector.message_score.y = 30;
    sf->vector.score.x = 150;
    sf->vector.score.y = -30;
    sf->var_norm.score = 0;
    sfText_setFont(sf->text.score, sf->text.font_score);
}

void create_health_point(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./images/health_point.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.health_point = Sprite;
    sf->texture.health_point = Texture;
    sf->vector.health_point.x = 0;
    sf->vector.health_point.y = 1060;
    sf->rect.health_point.top = 0;
    sf->rect.health_point.left = 0;
    sf->rect.health_point.width = 1600;
    sf->rect.health_point.height = 160;
    sfSprite_setTexture(sf->sprite.health_point, sf->texture.health_point,
        sfTrue);
    sfSprite_setPosition(sf->sprite.health_point, sf->vector.health_point);
    sfSprite_setTextureRect(sf->sprite.health_point, sf->rect.health_point);
}

void create_heal(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./images/heal.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.heal = Sprite;
    sf->texture.heal = Texture;
    sf->vector.heal.x = 0;
    sf->vector.heal.y = 0;
    sf->rect.heal.top = 0;
    sf->rect.heal.left = 0;
    sf->rect.heal.width = 192;
    sf->rect.heal.height = 190;
    sfSprite_setTexture(sf->sprite.heal, sf->texture.heal, sfTrue);
    sfSprite_setPosition(sf->sprite.heal, sf->vector.heal);
    sfSprite_setTextureRect(sf->sprite.heal, sf->rect.heal);
}

void create_portal(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./images/portal.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.portal = Sprite;
    sf->texture.portal = Texture;
    sf->vector.portal.x = -30;
    sf->vector.portal.y = 620;
    sf->rect.portal.top = 0;
    sf->rect.portal.left = 0;
    sf->rect.portal.width = 83;
    sf->rect.portal.height = 162;
    sfSprite_setTexture(sf->sprite.portal, sf->texture.portal, sfTrue);
    sfSprite_setPosition(sf->sprite.portal, sf->vector.portal);
    sfSprite_setTextureRect(sf->sprite.portal, sf->rect.portal);
}

void create_cactus(variable_t *sf)
{
    sfTexture *Text;
    sfSprite *Sprite = sfSprite_create();

    if (sf->var_norm.hitbox_mode == 0)
        Text = sfTexture_createFromFile("./images/cactus.png", NULL);
    else
        Text = sfTexture_createFromFile("./images/hitbox_cactus.png", NULL);
    sf->sprite.cactus = Sprite;
    sf->texture.cactus = Text;
    sfSprite_setTexture(sf->sprite.cactus, sf->texture.cactus, sfTrue);
}