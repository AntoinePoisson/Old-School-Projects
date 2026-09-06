/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** set vsync
*/

#include "my_rpg.h"

void set_vsync_button(game_t *game, sfVector2f *vsync_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && game->vector.mouse.x >= vsync_pos->x
        && game->vector.mouse.x <= vsync_pos->x + 55 * game->win.ratio
        && game->vector.mouse.y >= vsync_pos->y
        && game->vector.mouse.y <= vsync_pos->y + 55 * game->win.ratio
        && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->vsync,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->vsync,
        (sfVector2f){1252 * game->win.ratio, 272 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->vsync,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->vsync,
        (sfVector2f){1250 * game->win.ratio, 270 * game->win.ratio});
    }
}
