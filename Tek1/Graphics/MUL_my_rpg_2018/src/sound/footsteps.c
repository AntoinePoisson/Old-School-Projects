/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void manage_footsteps_sound(game_t *game)
{
    unsigned short random = 0;

    if (sfClock_getElapsedTime(game->clock->footsteps_sound).microseconds
        > 300000) {
        random = rand() % 3;
        if (random == 0 && !game->var.disp_music)
            sfSound_play(game->music->sand1);
        else if (random == 1 && !game->var.disp_music)
            sfSound_play(game->music->sand2);
        else
            if (!game->var.disp_music)
                sfSound_play(game->music->sand3);
        sfClock_restart(game->clock->footsteps_sound);
    }
}
