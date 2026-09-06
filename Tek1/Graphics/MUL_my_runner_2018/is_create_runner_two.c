/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include "is_create_runner_two.h"

void create_win_or_loss(variable_t *sf)
{
    sfTexture *Texture_two =
        sfTexture_createFromFile("./images/victory.png", NULL);
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture =
        sfTexture_createFromFile("./images/game_over.png", NULL);
    sfSprite *Sprite_two = sfSprite_create();

    sf->sprite.win = Sprite_two;
    sf->sprite.loss = Sprite;
    sf->texture.win = Texture_two;
    sf->texture.loss = Texture;
    sfSprite_setTexture(sf->sprite.win, sf->texture.win, sfTrue);
    sfSprite_setTexture(sf->sprite.loss, sf->texture.loss, sfTrue);
}

void create_end_level(variable_t *sf)
{
    sfTexture *Texture =
        sfTexture_createFromFile("./images/end_level.png", NULL);
    sfSprite *Sprite = sfSprite_create();

    sf->sprite.end_level = Sprite;
    sf->texture.end_level = Texture;
    sf->vector.end_level.x = 0;
    sf->vector.end_level.y = 0;
    sf->rect.end_level.top = 0;
    sf->rect.end_level.left = 0;
    sf->rect.end_level.width = 1600;
    sf->rect.end_level.height = 900;
    sfSprite_setTexture(sf->sprite.end_level, sf->texture.end_level, sfTrue);
    create_win_or_loss(sf);
}

void create_element(variable_t *sf, int i)
{
    if (i == 59)
        create_health_point(sf);
    if (i == 54)
        create_text_score(sf);
    if (i == 48)
        create_dino(sf);
    if (i == 40)
        create_heal(sf);
    if (i == 30)
        create_cactus(sf);
    if (i == 20)
        create_portal(sf);
    if (i == 10)
        create_bird(sf);
    if (i == -10) {
        sf->var_norm.quit_game = 1;
        sf->var_norm.nbr_obstacle_past = 0;
    }
}