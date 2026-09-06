/*
** EPITECH PROJECT, 2019
** choose_chara_menu
** File description:
** Menu to choose your character
*/

#include "my_rpg.h"

static void event_chara_menu(game_t *game, bool *close)
{
    while (sfRenderWindow_pollEvent(game->win.dow, &game->win.event)) {
        if (game->win.event.type == sfEvtClosed)
            sfRenderWindow_close(game->win.dow);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
        !game->press.escape) {
            close[0] = true;
            game->press.escape = true;
        }
        if (game->win.event.type == sfEvtKeyReleased &&
            game->win.event.key.code == sfKeyEscape && game->press.escape)
            game->press.escape = false;
    }
}

void choose_chara_menu(game_t *game)
{
    bool close = false;

    create_chara_menu(game);
    while (sfRenderWindow_isOpen(game->win.dow)) {
        event_chara_menu(game, &close);
        if (close)
            break;
        follow_cursor(game);
        color_rect_choose_chara_menu(game);
        click_choose_chara_menu(game);
        draw_chara_menu(game);
        sfRenderWindow_display(game->win.dow);
        sfRenderWindow_clear(game->win.dow, sfBlack);
    }
}
