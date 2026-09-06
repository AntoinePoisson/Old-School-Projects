/*
** EPITECH PROJECT, 2019
** management_wave
** File description:
** management wave
*/

#include "defender.h"

void is_extension_management_wave(variable_t *sf, int *count)
{
    if (*count > 0 && sf->var_norm.wave == 1)
        *count -= 1;
    if ((*count <= 0 && sf->var_norm.wave == 1)
        || (count_nbr_enemy(sf) == 0 && sf->var_norm.wave == 1)) {
        sf->var_norm.wave = 0;
        *count = WAIT_WAVE;
        is_destroy_enemy(sf);
    }
}

void management_wave(variable_t *sf)
{
    static int count = WAIT_WAVE;
    static int begin = 1;

    count = sf->var_norm.time_wave;
    if (sf->vector.hdv.x == 0)
        begin = 1;
    else
        begin = 0;
    if (!begin && count > 0 && sf->var_norm.wave == 0)
        count--;
    if (!begin && count <= 0 && sf->var_norm.wave == 0
        && sf->vector.hdv.x != 0) {
        sf->var_norm.wave = 1;
        count = WAIT_WAVE * 5;
        sf->var_norm.level += 1;
        is_create_enemy(sf);
    }
    if (!begin)
        is_extension_management_wave(sf, &count);
    sf->var_norm.time_wave = count;
}
