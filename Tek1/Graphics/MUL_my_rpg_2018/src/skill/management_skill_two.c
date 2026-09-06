/*
** EPITECH PROJECT, 2019
** management_skill.c
** File description:
** management skill
*/

#include "my_rpg.h"

void incremente_hp(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->player.regen_hp *= 4;
}

void deal_more_dmg(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->var.spell_dmg *= 5;
}

void gain_more_xp(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->player.xp /= 2;
}

void restaure_potion(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->var.potion = 93;
}

void go_to_the_end(game_t *game, int element)
{
    if (game->var.slot_skill_one == element)
        game->var.slot_skill_one = element * -1;
    if (game->var.slot_skill_two == element)
        game->var.slot_skill_two = element * -1;
    if (game->var.slot_skill_three == element)
        game->var.slot_skill_three = element * -1;
    if (game->var.slot_skill_four == element)
        game->var.slot_skill_four = element * -1;
    game->var.go_to_end = 1;
}