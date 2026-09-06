/*
** EPITECH PROJECT, 2019
** display_hud.c
** File description:
** display hud
*/

#include "my_rpg.h"

void use_potion(game_t *game)
{
    if (game->var.potion <= 5 ||
        (sfClock_getElapsedTime(game->player.clock_regen).microseconds
        / 1000000.0) < 1)
        return;
    if (game->player.hp > 0 && game->player.hp != game->var.player_hp) {
        game->player.hp += POTION_HEAL;
        game->var.potion -= 23;
        sfClock_restart(game->player.clock_regen);
    }
    if (game->player.hp > game->var.player_hp)
        game->player.hp = game->var.player_hp;
}

void management_regeneration(game_t *game)
{
    if ((sfClock_getElapsedTime(game->clock->regeneration).microseconds
        / 1000000.0) < 2)
        return;
    if (game->player.hp < game->var.player_hp && game->player.hp > 0)
        game->player.hp += game->player.regen_hp;
    if (game->player.mana < game->var.player_mana)
        game->player.mana += game->player.regen_mana;
    if (game->player.hp > game->var.player_hp)
        game->player.hp = game->var.player_hp;
    if (game->player.mana > game->var.player_mana)
        game->player.mana = game->var.player_mana;
    sfClock_restart(game->clock->regeneration);
}
