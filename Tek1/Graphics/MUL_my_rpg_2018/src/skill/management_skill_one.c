/*
** EPITECH PROJECT, 2019
** management_skill.c
** File description:
** management skill
*/

#include "my_rpg.h"

void resusite_player(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->player.hp = game->var.player_hp;
    game->player.mana = game->var.player_mana;
}

void more_hp(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->var.player_hp = game->var.player_hp * 2;
}

void more_mana(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->var.player_mana = game->var.player_mana * 2;
}

void more_armor(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->player.armor *= 2;
}

void incremente_mana(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->player.regen_mana *= 4;
}
