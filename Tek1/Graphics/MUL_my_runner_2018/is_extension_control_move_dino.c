/*
** EPITECH PROJECT, 2018
** control_move_dino.c
** File description:
** control_move_dino
*/

#include "csfml.h"
#include "struct.h"

void gestion_dino(variable_t *sf);
void display(variable_t *sf);

void dino_move_up(variable_t *sf)
{
    if (sf->var_norm.dino_jump <= 1 && sf->vector.dino.y == 638) {
        sf->var_norm.dino_jump = 1;
        sf->var_norm.dino_sinus = 0;
        sfMusic_play(sf->music.jump);
    }
    sfClock_restart(sf->clock.game);
}

void dino_move_right(variable_t *sf)
{
    if (sf->vector.dino.x < 1467)
        sf->vector.dino.x += 13;
    sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    gestion_dino(sf);
    display(sf);
    sfClock_restart(sf->clock.game);
}

void dino_move_left(variable_t *sf)
{
    if (sf->vector.dino.x > 4)
        sf->vector.dino.x -= 13;
    sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    gestion_dino(sf);
    display(sf);
    sfClock_restart(sf->clock.game);
}

void is_extension_dino_move_down(variable_t *sf)
{
    sf->var_norm.dino_down = 1;
    if (sf->vector.dino.y < 638 && sf->var_norm.dino_jump == 0)
        sf->vector.dino.y += 30;
    if (sf->vector.dino.y >= 300 && sf->var_norm.dino_jump == 1) {
        sf->vector.dino.y += 30;
        sf->var_norm.dino_jump = 0;
    }
    if (sf->var_norm.dino_down_two >= 0 && sf->vector.dino.y == 638) {
        sf->rect.dino.left = 770;
        sf->var_norm.dino_down_two += 1;

        if (sf->var_norm.dino_down_two >= 6)
            sf->var_norm.dino_down_two = -6;
    }
    else if (sf->vector.dino.y == 638) {
        sf->rect.dino.left = 944;
        sf->var_norm.dino_down_two += 1;
    }
}

void dino_move_down_display(variable_t *sf)
{
    sfSprite_setTextureRect(sf->sprite.dino, sf->rect.dino);
    display(sf);
    if (sf->vector.dino.y >= 587 && sf->var_norm.dino_down == 1)
        sf->vector.dino.y -= 51;
    sf->var_norm.dino_down = 0;
    sf->rect.dino.left = 256;
    sf->rect.dino.width = 128;
    sf->rect.dino.top = 0;
    sf->rect.dino.height = 135;
    sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    sfSprite_setTextureRect(sf->sprite.dino, sf->rect.dino);
    sfClock_restart(sf->clock.game);
}
