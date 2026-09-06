/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include "csfml.h"
#include "struct.h"

void display(variable_t *sf);

void is_extension_create_dino(variable_t *sf)
{
    sf->var_norm.level = 2;
    sf->var_norm.obstacle_touch = 0;
    sf->var_norm.health_point = 3;
    sf->var_norm.offset_dino = 128;
    sf->var_norm.slow_dino = 0;
    sf->var_norm.dino_jump = 0;
    sf->var_norm.dino_down_two = -2;
    sf->vector.dino.x = -130;
    sf->vector.dino.y = 638;
    sf->rect.dino.top = 0;
    sf->rect.dino.left = 256;
    sf->rect.dino.width = 128;
    sf->rect.dino.height = 135;
}