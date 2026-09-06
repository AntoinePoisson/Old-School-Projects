/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** move in dungeon
*/

#include "my_rpg.h"

void event_key_up_dungeon(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyUp) && control_move_player(game, 1))
    || (sfKeyboard_isKeyPressed(sfKeyZ) && control_move_player(game, 1))) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){0, -2 * game->win.ratio});
        if (control_move_player(game, 1))
            event_view_shift_up(game);
        game->view.offset.y -= 2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){0, -2 * game->win.ratio});
        manage_footsteps_sound(game);
    }
}

void event_key_down_dungeon(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyDown) && control_move_player(game, 2))
    || (sfKeyboard_isKeyPressed(sfKeyS) && control_move_player(game, 2))) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){0, 2 * game->win.ratio});
        if (control_move_player(game, 2))
            event_view_shift_down(game);
        game->view.offset.y += 2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){0, 2 * game->win.ratio});
        manage_footsteps_sound(game);
    }
}

void event_key_left_dungeon(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) && control_move_player(game, 3))
    || (sfKeyboard_isKeyPressed(sfKeyQ) && control_move_player(game, 3))) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){-2 * game->win.ratio, 0});
        if (control_move_player(game, 3))
            event_view_shift_left(game);
        game->view.offset.x -= 2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){-2 * game->win.ratio, 0});
        manage_footsteps_sound(game);
    }
}

void event_key_right_dungeon(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyRight) && control_move_player(game, 4))
    || (sfKeyboard_isKeyPressed(sfKeyD) && control_move_player(game, 4))) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){2 * game->win.ratio, 0});
        if (control_move_player(game, 4))
            event_view_shift_right(game);
        game->view.offset.x += 2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){2 * game->win.ratio, 0});
        manage_footsteps_sound(game);
    }
}
