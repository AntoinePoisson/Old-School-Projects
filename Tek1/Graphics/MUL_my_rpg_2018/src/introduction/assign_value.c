/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** assign value
*/

#include "my_rpg.h"

void assign_value_four(int j, char *value, game_t *game)
{
    switch (j) {
    case (24) : game->player.regen_hp = my_getnbr(value);
        return;
    case (25) : game->player.regen_mana = my_getnbr(value);
        return;
    case (26) : game->player.speed_move = my_getnbr(value);
        return;
    case (27) : game->player.speed_attack = my_getnbr(value);
        return;
    case (28) : game->player.armor = my_getnbr(value);
        return;
    case (29) : game->player.attack_spell = my_getnbr(value);
        return;
    case (30) : game->player.animation = my_getnbr(value);
        return;
    default : write(1, "value not assign\n", 17);
        return;
    }
}

void assign_value_third(int j, char *value, game_t *game)
{
    switch (j) {
    case (16) : game->var.enemy_spider_earn = my_getnbr(value);
        return;
    case (17) : game->var.enemy_evil_tick_range = my_getnbr(value);
        return;
    case (18) : game->var.enemy_evil_tick_dmg = my_getnbr(value);
        return;
    case (19) : game->var.enemy_evil_tick_earn = my_getnbr(value);
        return;
    case (20) : game->player.status = my_getnbr(value);
        return;
    case (21) : game->player.mana = my_getnbr(value);
        return;
    case (22) : game->player.gold = my_getnbr(value);
        return;
    case (23) : game->player.xp = my_getnbr(value);
        return;
    default : assign_value(j, value, game);
        return;
    }
}

void assign_value_two(int j, char *value, game_t *game)
{
    switch (j) {
    case (8) : game->var.spell_range = my_getnbr(value);
        return;
    case (9) : game->var.spell_speed = my_getnbr(value);
        return;
    case (10) : game->var.spell_dmg = my_getnbr(value);
        return;
    case (11) : game->var.enemy_eye_agro_range = my_getnbr(value);
        return;
    case (12) : game->var.enemy_eye_dmg = my_getnbr(value);
        return;
    case (13) : game->var.enemy_eye_earn = my_getnbr(value);
        return;
    case (14) : game->var.enemy_spider_range = my_getnbr(value);
        return;
    case (15) : game->var.enemy_spider_dmg = my_getnbr(value);
        return;
    default : assign_value_third(j, value, game);
        return;
    }
}

void assign_value(int j, char *value, game_t *game)
{
    switch (j) {
    case (0) : game->var.level = my_getnbr(value);
        return;
    case (1) : game->var.fullscreen = my_getnbr(value);
        return;
    case (2) : game->var.quit_donjon = my_getnbr(value);
        return;
    case (3) : game->var.quit_beach = my_getnbr(value);
        return;
    case (4) : game->var.player_hp = my_getnbr(value);
        return;
    case (5) : game->var.player_mana = my_getnbr(value);
        return;
    case (6) : game->var.player_speed = my_getnbr(value);
        return;
    case (7) : game->var.player_xp = my_getnbr(value);
        return;
    default : assign_value_two(j, value, game);
        return;
    }
}
