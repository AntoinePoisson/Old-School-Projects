/*
** EPITECH PROJECT, 2018
** create_sprite
** File description:
** create_sprite
*/

#include "create_sprite.h"

void create_ghost(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Ghost.png", NULL);

    sf->vector.ghost.y = 427;
    sf->vector.ghost.x = rand_ghost_x();
    sf->rect.ghost.top = 0;
    sf->rect.ghost.left = 0;
    sf->rect.ghost.width = 124;
    sf->rect.ghost.height = 130;
    sf->texture.ghost = Texture;
    sf->sprite.ghost = Sprite;
    sf->var_norm.acceleration_ghost = 25;
}

void create_background_one(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/H_o_s.png", NULL);
    sfSprite *Sprite_two = sfSprite_create();
    sfTexture *Tex_two = sfTexture_createFromFile("./images/H_t_s.png", NULL);

    sf->texture.bg_h_o_s = Texture;
    sf->sprite.bg_h_o_s = Sprite;
    sf->texture.bg_h_t_s = Tex_two;
    sf->sprite.bg_h_t_s = Sprite_two;
    sf->vector.bg_h_o_s.x = 0;
    sf->vector.bg_h_o_s.y = 0;
    sf->vector.bg_h_t_s.x = 1344;
    sf->vector.bg_h_t_s.y = 0;
    sfSprite_setTexture(sf->sprite.bg_h_o_s, sf->texture.bg_h_o_s, sfTrue);
    sfSprite_setTexture(sf->sprite.bg_h_t_s, sf->texture.bg_h_t_s, sfTrue);
    sfSprite_setPosition(sf->sprite.bg_h_t_s, sf->vector.bg_h_t_s);
    sfSprite_setPosition(sf->sprite.bg_h_o_s, sf->vector.bg_h_o_s);
}

void create_background_two(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/H_o.png", NULL);
    sfSprite *Sprite_two = sfSprite_create();
    sfTexture *Tex_two = sfTexture_createFromFile("./images/H_t.png", NULL);

    sf->texture.bg_h_o = Texture;
    sf->sprite.bg_h_o = Sprite;
    sf->texture.bg_h_t = Tex_two;
    sf->sprite.bg_h_t = Sprite_two;
    sf->vector.bg_h_o.x = 0;
    sf->vector.bg_h_o.y = 0;
    sf->vector.bg_h_t.x = 1012;
    sf->vector.bg_h_t.y = 0;
    sfSprite_setTexture(sf->sprite.bg_h_o, sf->texture.bg_h_o, sfTrue);
    sfSprite_setTexture(sf->sprite.bg_h_t, sf->texture.bg_h_t, sfTrue);
    sfSprite_setPosition(sf->sprite.bg_h_t, sf->vector.bg_h_t);
    sfSprite_setPosition(sf->sprite.bg_h_o, sf->vector.bg_h_o);
}

void create_door_one(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Void.png", NULL);

    sf->vector.door_one.y = -475;
    sf->vector.door_one.x = -1475;
    sf->var_norm.choose_person_d_o = 0;
    sf->texture.door_one = Texture;
    sf->sprite.door_one = Sprite;
    sf->var_norm.pause_door_one = rand_pause_window_d_o(sf);
    sfSprite_setTexture(sf->sprite.door_one, sf->texture.door_one, sfTrue);
    sfSprite_setPosition(sf->sprite.door_one, sf->vector.door_one);
}

void create_door_two(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/Void.png", NULL);

    sf->vector.door_two.y = -475;
    sf->vector.door_two.x = -1475;
    sf->var_norm.choose_person_d_t = 0;
    sf->texture.door_two = Texture;
    sf->sprite.door_two = Sprite;
    sf->var_norm.pause_door_two = rand_pause_window_d_t(sf);
    sfSprite_setTexture(sf->sprite.door_two, sf->texture.door_two, sfTrue);
    sfSprite_setPosition(sf->sprite.door_two, sf->vector.door_two);
}
