/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_stats.c
*/

#include "my_rpg.h"

static void create_text_stats(game_t *game)
{
    game->text.player_regen_mana = sfText_create();
    game->text.player_basic_attack = sfText_create();
    game->text.player_spell_attack = sfText_create();
    game->text.player_attack_speed = sfText_create();
    game->text.player_move_speed = sfText_create();
    sfText_setCharacterSize(game->text.player_hp, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_hp_max, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_regen_hp, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_gold, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_mana, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_mana_max, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_armor, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_regen_mana, 30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_basic_attack,
    30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_spell_attack,
    30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_attack_speed,
    30 * game->win.ratio);
    sfText_setCharacterSize(game->text.player_move_speed, 30 * game->win.ratio);
}

static void set_font_stats(game_t *game)
{
    sfText_setFont(game->text.player_hp, game->text.game_police);
    sfText_setFont(game->text.player_hp_max, game->text.game_police);
    sfText_setFont(game->text.player_regen_hp, game->text.game_police);
    sfText_setFont(game->text.player_gold, game->text.game_police);
    sfText_setFont(game->text.player_mana, game->text.game_police);
    sfText_setFont(game->text.player_mana_max, game->text.game_police);
    sfText_setFont(game->text.player_armor, game->text.game_police);
    sfText_setFont(game->text.player_regen_mana, game->text.game_police);
    sfText_setFont(game->text.player_basic_attack, game->text.game_police);
    sfText_setFont(game->text.player_spell_attack, game->text.game_police);
    sfText_setFont(game->text.player_attack_speed, game->text.game_police);
    sfText_setFont(game->text.player_move_speed, game->text.game_police);
}

void set_string_stats(game_t *game)
{
    sfText_setString(game->text.player_hp, my_itoa(game->player.hp, 0));
    sfText_setString(game->text.player_hp_max, "/ 100");
    sfText_setString(game->text.player_regen_hp, "2,20");
    sfText_setString(game->text.player_gold, my_itoa(game->player.gold, 0));
    sfText_setString(game->text.player_mana, my_itoa(game->player.mana, 0));
    sfText_setString(game->text.player_mana_max, "/ 100");
    sfText_setString(game->text.player_regen_mana, "3,42");
    sfText_setString(game->text.player_armor, "20 / 100");
    sfText_setString(game->text.player_basic_attack,
    my_itoa(game->player.attack_basic, 0));
    sfText_setString(game->text.player_spell_attack,
    my_itoa(game->player.attack_spell, 0));
    sfText_setString(game->text.player_attack_speed, "0,96");
    sfText_setString(game->text.player_move_speed,
    my_itoa(game->player.speed_move, 0));
}

void create_stats(game_t *game)
{
    game->press.inventory = false;
    game->var.disp_inventory = false;
    game->player.gold = 0;
    game->player.attack_basic = CLOSE_COMBAT_DAMAGE;
    game->player.attack_spell = SPELL_DAMAGE;
    game->player.regen_hp = REGEN_HP;
    game->player.regen_mana = REGEN_MANA;
    game->player.speed_attack = 2;
    game->player.speed_move = 2;
    game->text.player_hp = sfText_create();
    game->text.player_hp_max = sfText_create();
    game->text.player_gold = sfText_create();
    game->text.player_mana = sfText_create();
    game->text.player_mana_max = sfText_create();
    game->text.player_armor = sfText_create();
    game->text.player_regen_hp = sfText_create();
    create_text_stats(game);
    set_font_stats(game);
}
