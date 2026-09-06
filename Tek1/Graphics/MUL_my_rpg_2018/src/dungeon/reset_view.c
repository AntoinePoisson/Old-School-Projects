/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void reset_dungeon_view(game_t *game)
{
    unsigned short x = 3200;
    unsigned short y = 1040;
    int cas = rand() % 5;

    if (cas <= 2) {
        x = 1445;
        y = 3230;
    }
    sfView_reset(game->view.view, (sfFloatRect){0, 0, 1920 *
        game->win.ratio, 1080 * game->win.ratio});
    sfSprite_setPosition(game->sprite->player,
        (sfVector2f){1920 / 2 * game->win.ratio, 1080 / 2 * game->win.ratio});
    sfView_move(game->view.view,
        (sfVector2f){x * game->win.ratio, y * game->win.ratio});
    sfSprite_move(game->sprite->player,
        (sfVector2f){x * game->win.ratio, y * game->win.ratio});
    game->view.offset =
        (sfVector2f){x * game->win.ratio, y * game->win.ratio};
    sfRenderWindow_setView(game->win.dow, game->view.view);
}
