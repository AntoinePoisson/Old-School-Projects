/*
** EPITECH PROJECT, 2019
** event_move_shift
** File description:
** Event move with shift
*/

#include "my_rpg.h"

void event_key_shift_right(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        sfSprite_move(game->sprite->player,
        (sfVector2f){2 * game->win.ratio, 0});
}

void event_key_shift_left(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        sfSprite_move(game->sprite->player,
        (sfVector2f){-2 * game->win.ratio, 0});
}

void event_key_shift_up(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        sfSprite_move(game->sprite->player,
        (sfVector2f){0, -2 * game->win.ratio});
}

void event_key_shift_down(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        sfSprite_move(game->sprite->player,
        (sfVector2f){0, 2 * game->win.ratio});
}