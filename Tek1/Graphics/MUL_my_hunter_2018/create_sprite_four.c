/*
** EPITECH PROJECT, 2018
** create_sprite_four
** File description:
** create_sprite_four
*/

#include "create_sprite_four.h"

void create_text_score(variable_t *sf)
{
    sf->text.score = sfText_create();
    sf->vector.text_score.x = 525;
    sf->vector.text_score.y = 803;
    sf->var_norm.char_text_score = "0";
    sfText_setFont(sf->text.score, sf->text.font);
    sfText_setString(sf->text.score, sf->var_norm.char_text_score);
    sfText_setPosition(sf->text.score, sf->vector.text_score);
}

void is_extension_create_texture_and_sprite(variable_t *sf)
{
    create_duck(sf);
    create_ghost(sf);
    create_background_one(sf);
    create_background_two(sf);
    create_window_two(sf);
    create_window_one(sf);
    create_door_one(sf);
    create_door_two(sf);
    create_back(sf);
    create_girl_normal(sf);
    create_shoot(sf);
    create_music(sf);
    change_heal_point(sf);
    create_text_time(sf);
    create_text_score(sf);
}

void create_texture_and_sprite(variable_t *sf)
{
    sfTexture *Texture = sfTexture_createFromFile("./images/BG.jpeg", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->var_norm.acceleration_window_two = 2;
    sf->var_norm.acceleration_window_one = 2;
    sf->var_norm.acceleration_door_one = 2;
    sf->var_norm.acceleration_door_two = 2;
    sf->var_norm.acceleration_back = 2;
    sf->var_norm.heal_point = 5;
    sf->texture.bg = Texture;
    sf->sprite.bg = Sprite;
    sfSprite_setTexture(sf->sprite.bg, sf->texture.bg, sfTrue);
    is_extension_create_texture_and_sprite(sf);
    sf->var_norm.last_position = 0;
}

void create_heal_point_high(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/100hp.png", NULL);

    sf->texture.heal_point = Texture;
    sf->sprite.heal_point = Sprite;
    sf->vector.heal_point.x = 560;
    sf->vector.heal_point.y = 853;
    sfSprite_setTexture(sf->sprite.heal_point, sf->texture.heal_point, sfTrue);
    sfSprite_setPosition(sf->sprite.heal_point, sf->vector.heal_point);
}

void create_heal_point_more_than_mid(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture = sfTexture_createFromFile("./images/75hp.png", NULL);

    sf->texture.heal_point = Texture;
    sf->sprite.heal_point = Sprite;
    sf->vector.heal_point.x = 560;
    sf->vector.heal_point.y = 853;
    sfSprite_setTexture(sf->sprite.heal_point, sf->texture.heal_point, sfTrue);
    sfSprite_setPosition(sf->sprite.heal_point, sf->vector.heal_point);
}
