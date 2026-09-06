/*
** EPITECH PROJECT, 2018
** create_sprite_five
** File description:
** create_sprite_five
*/

#include "create_sprite_five.h"

void create_heal_point_mid(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/50hp.png", NULL);

    sf->texture.heal_point = Texture;
    sf->sprite.heal_point = Sprite;
    sf->vector.heal_point.x = 560;
    sf->vector.heal_point.y = 853;
    sfSprite_setTexture(sf->sprite.heal_point, sf->texture.heal_point, sfTrue);
    sfSprite_setPosition(sf->sprite.heal_point, sf->vector.heal_point);
}

void create_heal_point_less_than_mid(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/25hp.png", NULL);

    sf->texture.heal_point = Texture;
    sf->sprite.heal_point = Sprite;
    sf->vector.heal_point.x = 560;
    sf->vector.heal_point.y = 853;
    sfSprite_setTexture(sf->sprite.heal_point, sf->texture.heal_point, sfTrue);
    sfSprite_setPosition(sf->sprite.heal_point, sf->vector.heal_point);
}

void create_heal_point_low(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/0hp.png", NULL);

    sf->texture.heal_point = Texture;
    sf->sprite.heal_point = Sprite;
    sf->vector.heal_point.x = 560;
    sf->vector.heal_point.y = 853;
    sfSprite_setTexture(sf->sprite.heal_point, sf->texture.heal_point, sfTrue);
    sfSprite_setPosition(sf->sprite.heal_point, sf->vector.heal_point);
}

void create_game_over(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Tex = sfTexture_createFromFile("./images/game_over.png", NULL);

    sf->texture.game_over = Tex;
    sf->sprite.game_over  = Sprite;
    sfSprite_setTexture(sf->sprite.game_over, sf->texture.game_over, sfTrue);
    sfSprite_setPosition(sf->sprite.game_over, sf->vector.bg_h_o);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.game_over, NULL);
}

void create_window_one(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Void.png", NULL);

    sf->vector.window_one.y = -181;
    sf->vector.window_one.x = -842;
    sf->var_norm.choose_person = 0;
    sf->texture.window_one = Texture;
    sf->sprite.window_one = Sprite;
    sf->var_norm.pause_window_one = rand_pause_window_o(sf);
    sfSprite_setTexture(sf->sprite.window_one, sf->texture.window_one, sfTrue);
    sfSprite_setPosition(sf->sprite.window_one, sf->vector.window_one);
}
