/*
** EPITECH PROJECT, 2019
** management_trap.c
** File description:
** management trap
*/

#include "my_rpg.h"

void management_trap(game_t *game)
{
    if ((sfClock_getElapsedTime(game->clock->trap).microseconds / 1000000.0)
        < 0.40)
        return;
    game->player.hp -= TRAP_DMG;
    sfClock_restart(game->clock->trap);
}