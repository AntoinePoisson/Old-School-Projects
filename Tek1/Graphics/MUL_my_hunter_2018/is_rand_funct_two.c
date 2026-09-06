/*
** EPITECH PROJECT, 2018
** is_rand_funct_two
** File description:
** is_rand_funct
*/

#include "is_rand_funct.h"

float rand_pause_window_d_t(variable_t *sf)
{
    int acceleration = sf->var_norm.acceleration_door_two;

    return (rand() % (10 - acceleration) + acceleration);
}

float rand_pause_window_b(variable_t *sf)
{
    int acceleration = sf->var_norm.acceleration_back;

    return (rand() % (10 - acceleration) + acceleration);
}

float rand_person(void)
{
    return (rand() % (10 - 0) - 0);
}

int rand_duck_x(variable_t *sf)
{
    int result = rand() % (900 - 0) + 0;

    if (result > 320)
        result *= -1;
    if (sf->var_norm.acceleration_duck >= 70)
        result = (rand() % (1600 - 700) + 700) * -1;
    return (result);
}
