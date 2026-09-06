/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** Third state of buttons of the settings menu
*/

#include "my_rpg.h"

void third_states_buttons_set_menu(game_t *game)
{
    sfVector2f size1_pos = sfSprite_getPosition(game->sprite->size_1920_1);
    sfVector2f size2_pos = sfSprite_getPosition(game->sprite->size_1664_1);
    sfVector2f size3_pos = sfSprite_getPosition(game->sprite->size_1280_1);
    sfVector2f size4_pos = sfSprite_getPosition(game->sprite->key_bindings_1);
    sfVector2f full_pos = sfSprite_getPosition(game->sprite->fullscreen);
    sfVector2f vsync_pos = sfSprite_getPosition(game->sprite->vsync);

    set_size1_button(game, &size1_pos);
    set_size2_button(game, &size2_pos);
    set_size3_button(game, &size3_pos);
    set_size4_button(game, &size4_pos);
    set_full_button(game, &full_pos);
    set_vsync_button(game, &vsync_pos);
}
