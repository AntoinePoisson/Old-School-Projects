/*
** EPITECH PROJECT, 2018
** is_rand_funct
** File description:
** is_rand_funct
*/

#include "is_rand_funct.h"

int rand_duck_y(void)
{
    return (rand() % (480 - 28) + 28);
}

int rand_ghost_x(void)
{
    return (rand() % (4500 - 2310) + 2310);
}

float rand_pause_window_o(variable_t *sf)
{
    int acceleration = sf->var_norm.acceleration_window_one;

    return (rand() % (10 - acceleration) + acceleration);
}

float rand_pause_window_t(variable_t *sf)
{
    int acceleration = sf->var_norm.acceleration_window_two;

    return (rand() % (10 - acceleration) + acceleration);
}

float rand_pause_window_d_o(variable_t *sf)
{
    int acceleration = sf->var_norm.acceleration_door_one;

    return (rand() % (10 - acceleration) + acceleration);
}
