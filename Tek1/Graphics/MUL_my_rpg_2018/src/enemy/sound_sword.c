/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** sound of the sword
*/

#include "my_rpg.h"

void play_sword_sound(game_t *game, bool which)
{
    if (sfClock_getElapsedTime(game->clock->flesh_sound)
    .microseconds > 200000) {
        if (which == true && !game->var.disp_music)
            sfSound_play(game->music->flesh_slice);
        else if (!game->var.disp_music)
            sfSound_play(game->music->sword_slash);
        sfClock_restart(game->clock->flesh_sound);
    }
}
