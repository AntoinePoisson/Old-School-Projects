/*
** EPITECH PROJECT, 2019
** event_move_shift_view
** File description:
** Move the camera when you clic on shift
*/

#include "my_rpg.h"

void event_view_shift_right(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){2 * game->win.ratio, 0});
        game->view.offset.x += 2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){2 * game->win.ratio, 0});
    }
}

void event_view_shift_left(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){-2 * game->win.ratio, 0});
        game->view.offset.x += -2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){-2 * game->win.ratio, 0});
    }
}

void event_view_shift_up(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){0, -2 * game->win.ratio});
        game->view.offset.y += -2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){0, -2 * game->win.ratio});
    }
}

void event_view_shift_down(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfSprite_move(game->sprite->player,
        (sfVector2f){0, 2 * game->win.ratio});
        game->view.offset.y += 2 * game->win.ratio;
        sfView_move(game->view.view, (sfVector2f){0, 2 * game->win.ratio});
    }
}