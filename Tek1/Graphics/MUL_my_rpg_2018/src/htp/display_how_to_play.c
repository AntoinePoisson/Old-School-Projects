/*
** EPITECH PROJECT, 2019
** display_htp.c
** File description:
** display how to play of rpg
*/

#include "my_rpg.h"

static void display_how_to_play(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->menu, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->back_htp, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.text_htp, NULL);
}

static void event_htp(game_t *game, int *close)
{
    while (sfRenderWindow_pollEvent(game->win.dow, &game->win.event)) {
        if (game->win.event.type == sfEvtClosed)
            sfRenderWindow_close(game->win.dow);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
            !game->press.escape)
            close[0] = 1;
    }
}

void htp_loop(game_t *game)
{
    int close = 0;

    create_htp(game);
    while (sfRenderWindow_isOpen(game->win.dow)) {
        event_htp(game, &close);
        display_how_to_play(game);
        if (close)
            break;
        sfRenderWindow_display(game->win.dow);
        sfRenderWindow_clear(game->win.dow, sfBlack);
    }
}