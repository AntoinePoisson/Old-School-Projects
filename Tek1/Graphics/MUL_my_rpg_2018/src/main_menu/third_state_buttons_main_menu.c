/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** Third state of buttons of main menu
*/

#include "my_rpg.h"

void third_states_buttons_main_menu(game_t *game)
{
    sfVector2f play1_pos = sfSprite_getPosition(game->sprite->play1_menu);
    sfVector2f set_pos = sfSprite_getPosition(game->sprite->set1_menu);
    sfVector2f htp_pos = sfSprite_getPosition(game->sprite->htp1_menu);
    sfVector2f score_pos = sfSprite_getPosition(game->sprite->high_score1_menu);
    sfVector2f exit_pos = sfSprite_getPosition(game->sprite->exit1_menu);

    menu_play_button(game, &play1_pos);
    menu_set_button(game, &set_pos);
    menu_htp_button(game, &htp_pos);
    menu_score_button(game, &score_pos);
    menu_exit_button(game, &exit_pos);
}
