/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** set_pos_text_stats.c
*/

#include "my_rpg.h"

static void set_pos_text_stats2(game_t *game, sfVector2f view)
{
    sfText_setPosition(game->text.player_gold,
    (sfVector2f){view.x + 420, view.y + 100});
    sfText_setPosition(game->text.player_attack_speed,
    (sfVector2f){view.x + 420, view.y - 140});
    sfText_setPosition(game->text.player_armor,
    (sfVector2f){view.x + 170, view.y + 100});
    sfText_setPosition(game->text.player_basic_attack,
    (sfVector2f){view.x - 400, view.y + 100});
    sfText_setPosition(game->text.player_spell_attack,
    (sfVector2f){view.x - 140, view.y + 100});
}

void set_pos_text_stats(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    sfText_setPosition(game->text.player_hp,
    (sfVector2f){view.x - 400, view.y - 175});
    sfText_setPosition(game->text.player_hp_max,
    (sfVector2f){view.x - 335, view.y - 175});
    sfText_setPosition(game->text.player_regen_hp,
    (sfVector2f){view.x - 400, view.y - 110});
    sfText_setPosition(game->text.player_mana,
    (sfVector2f){view.x - 160, view.y - 175});
    sfText_setPosition(game->text.player_mana_max,
    (sfVector2f){view.x - 95, view.y - 175});
    sfText_setPosition(game->text.player_regen_mana,
    (sfVector2f){view.x - 140, view.y - 110});
    sfText_setPosition(game->text.player_move_speed,
    (sfVector2f){view.x + 200, view.y - 140});
    set_pos_text_stats2(game, view);
}