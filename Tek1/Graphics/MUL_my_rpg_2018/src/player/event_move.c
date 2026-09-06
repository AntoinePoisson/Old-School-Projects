/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** move perso
*/

#include "my_rpg.h"

void event_key_up(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyUp) && control_move_player(game, 1))
        || (sfKeyboard_isKeyPressed(sfKeyZ) && control_move_player(game, 1))) {
        if (sfSprite_getPosition(game->sprite->player).y > 1936
            * game->win.ratio || sfSprite_getPosition(game->sprite->player).y
            < 500 * game->win.ratio) {
            sfSprite_move(game->sprite->player,
            (sfVector2f){0, -2 * game->win.ratio});
            event_key_shift_up(game);
        } else {
            sfSprite_move(game->sprite->player,
            (sfVector2f){0, -2 * game->win.ratio});
            event_view_shift_up(game);
            game->view.offset.y -= 2 * game->win.ratio;
            sfView_move(game->view.view, (sfVector2f){0, -2 * game->win.ratio});
        }
        manage_footsteps_sound(game);
    }
}

void event_key_down(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyDown) && control_move_player(game, 2))
        || (sfKeyboard_isKeyPressed(sfKeyS) && control_move_player(game, 2))) {
        if (sfSprite_getPosition(game->sprite->player).y > 1936
            * game->win.ratio || sfSprite_getPosition(game->sprite->player).y
            < 500 * game->win.ratio) {
            sfSprite_move(game->sprite->player,
            (sfVector2f){0, 2 * game->win.ratio});
            event_key_shift_down(game);
        } else {
            sfSprite_move(game->sprite->player,
            (sfVector2f){0, 2 * game->win.ratio});
            event_view_shift_down(game);
            game->view.offset.y += 2 * game->win.ratio;
            sfView_move(game->view.view, (sfVector2f){0, 2 * game->win.ratio});
        }
        manage_footsteps_sound(game);
    }
}

void event_key_left(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) && control_move_player(game, 3))
        || (sfKeyboard_isKeyPressed(sfKeyQ) && control_move_player(game, 3))) {
        if (sfSprite_getPosition(game->sprite->player).x > 1540
            * game->win.ratio || sfSprite_getPosition(game->sprite->player).x
            < 950 * game->win.ratio) {
            sfSprite_move(game->sprite->player,
            (sfVector2f){-2 * game->win.ratio, 0});
            event_key_shift_left(game);
        } else {
            sfSprite_move(game->sprite->player,
            (sfVector2f){-2 * game->win.ratio, 0});
            event_view_shift_left(game);
            game->view.offset.x -= 2 * game->win.ratio;
            sfView_move(game->view.view, (sfVector2f){-2 * game->win.ratio, 0});
        }
        manage_footsteps_sound(game);
    }
}

void event_key_right(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyRight) && control_move_player(game, 4))
        || (sfKeyboard_isKeyPressed(sfKeyD) && control_move_player(game, 4))) {
        if (sfSprite_getPosition(game->sprite->player).x > 1540
            * game->win.ratio || sfSprite_getPosition(game->sprite->player).x
            < 950 * game->win.ratio) {
                sfSprite_move(game->sprite->player,
            (sfVector2f){2 * game->win.ratio, 0});
            event_key_shift_right(game);
        } else {
            sfSprite_move(game->sprite->player,
            (sfVector2f){2 * game->win.ratio, 0});
            event_view_shift_right(game);
            game->view.offset.x += 2 * game->win.ratio;
            sfView_move(game->view.view, (sfVector2f){2 * game->win.ratio, 0});
        }
        manage_footsteps_sound(game);
    }
}

void event_move(game_t *game)
{
    if (sfClock_getElapsedTime(game->clock->player_move).microseconds > 13333) {
        if (game->var.level == 0) {
            event_key_up(game);
            event_key_down(game);
            event_key_left(game);
            event_key_right(game);
        } else {
            event_key_up_dungeon(game);
            event_key_down_dungeon(game);
            event_key_left_dungeon(game);
            event_key_right_dungeon(game);
        }
        sfRenderWindow_setView(game->win.dow, game->view.view);
        sfClock_restart(game->clock->player_move);
    }
}
