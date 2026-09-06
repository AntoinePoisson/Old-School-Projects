/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** high_score_loop.c
*/

#include "my_rpg.h"

static void display_high_score(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->menu, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->back_hs, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.hs, NULL);
    display_highscore(game);
}

static void event_high_score(game_t *game, int *close)
{
    while (sfRenderWindow_pollEvent(game->win.dow, &game->win.event)) {
        if (game->win.event.type == sfEvtClosed)
            sfRenderWindow_close(game->win.dow);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
            !game->press.escape)
            close[0] = 1;
    }
}

static void destroy_high_score(game_t *game)
{
    sfSprite_destroy(game->sprite->back_hs);
    sfTexture_destroy(game->texture->back_hs);
    sfText_destroy(game->text.hs);
    sfFont_destroy(game->text.font_highscore);
}

void high_score_loop(game_t *game)
{
    int close = 0;

    create_high_score(game);
    while (sfRenderWindow_isOpen(game->win.dow)) {
        event_high_score(game, &close);
        display_high_score(game);
        if (close)
            break;
        sfRenderWindow_display(game->win.dow);
        sfRenderWindow_clear(game->win.dow, sfBlack);
    }
    destroy_high_score(game);
}