/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** init_game_var.c
*/

#include "my_rpg.h"

void attack_player(game_t *game)
{
    game->player.attack -= 1;
    if (game->player.attack > 3)
        game->player.rect_x = 4;
    if (game->player.attack >= 1)
        game->player.rect_x = 3;
    if (game->player.attack == 0)
        game->player.rect_x = 2;
}

static void init_game_var2(game_t *game)
{
    game->var.player_speed = 10;
    game->var.player_xp = 100;
    game->var.spell_range = 42;
    game->var.spell_speed = 8;
    game->var.spell_dmg = 20;
    game->var.enemy_eye_speed = 4.0;
    game->var.enemy_eye_agro_range = 450;
    game->var.enemy_eye_dmg = 3;
    game->var.enemy_spider_speed = 2.0;
    game->var.enemy_evil_tick_speed = 7.5;
}

void init_game_var(game_t *game)
{
    game->player.attack = 0;
    game->var.slot_skill_one = 20;
    game->var.slot_skill_two = 20;
    game->var.slot_skill_three = 20;
    game->var.slot_skill_four = 20;
    game->var.go_to_end = 0;
    game->var.score = 0;
    game->var.time = 0;
    game->var.kill = 0;
    game->var.potion = 0;
    game->var.move = 0;
    game->var.potion = 93;
    game->var.quit_beach = 1;
    game->var.quit_donjon = 1;
    game->var.player_hp = 100;
    game->var.player_mana = 100;
    init_game_var2(game);
}