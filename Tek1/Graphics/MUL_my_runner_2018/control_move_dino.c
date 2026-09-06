/*
** EPITECH PROJECT, 2018
** control_move_dino
** File description:
** control_move_dino
*/

#include "control_move_dino.h"

void dino_move_down_gestion_jump(variable_t *sf)
{
    if (sf->var_norm.dino_jump == 1 && sf->vector.dino.y <= 300) {
        sf->var_norm.dino_jump -= 1;
        sf->var_norm.dino_sinus *= -1;
    }
    if (sf->var_norm.dino_jump != 0) {
        sf->vector.dino.y -= 30;
        sf->var_norm.dino_sinus += 0.7;
    }
    if (sf->var_norm.dino_jump <= 0) {
        if (sf->vector.dino.y < 638) {
            sf->vector.dino.y += 33;
            sf->var_norm.dino_sinus += 0.8;
        }
        if (sf->vector.dino.y > 638) {
            sf->vector.dino.y = 638;
            sf->var_norm.dino_sinus = 0;
        }
    }
}

void dino_move_down(variable_t *sf)
{
    if (sf->var_norm.slow_dino >= 3)
        sf->var_norm.slow_dino = 0;
    else
        sf->var_norm.slow_dino += 1;
    if (sf->vector.dino.y == 638) {
        sf->rect.dino.top = 51;
        sf->rect.dino.width = 174;
        sf->rect.dino.height = 84;
    }
    is_extension_dino_move_down(sf);
    if (sf->var_norm.dino_jump != 0 || sf->vector.dino.y != 638) {
        dino_move_down_gestion_jump(sf);
        sf->vector.dino.y += sf->var_norm.dino_sinus;
        sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    }
    dino_move_down_display(sf);
}
