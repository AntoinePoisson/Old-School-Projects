/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** skip dialog
*/

#include "my_rpg.h"

void skip_dialog(game_t *game, bool pos_text)
{
    if (game->press.space && pos_text) {
        sfText_setPosition(game->text.pnj_answ,
        (sfVector2f){123123 * game->win.ratio, 123123 * game->win.ratio});
        sfText_setPosition(game->text.player_answ,
        (sfVector2f){1380 * game->win.ratio, 850 * game->win.ratio});
        sfText_setPosition(game->text.pnj_name,
        (sfVector2f){15615 * game->win.ratio, 15616 * game->win.ratio});
        sfText_setPosition(game->text.player_name,
        (sfVector2f){1140 * game->win.ratio, 630 * game->win.ratio});
        sfText_setPosition(game->text.press_space,
        (sfVector2f){123123 * game->win.ratio, 123123 * game->win.ratio});
    }
    if (game->win.event.type == sfEvtKeyReleased
        && game->win.event.key.code == sfKeySpace
        && game->press.space && pos_text) {
        game->press.space = false;
        pos_text = false;
    }
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
}

void skip_text_dialog(game_t *game)
{
    static bool pos_text = false;

    game->press.space = false;
    sfText_setString(game->text.press_space, "Press Space bar to skip");
    if (!pos_text)
        sfText_setPosition(game->text.press_space,
        (sfVector2f){1400 * game->win.ratio, 1000 * game->win.ratio});
    if (sfKeyboard_isKeyPressed(sfKeySpace)
        && !game->press.space && !pos_text) {
        pos_text = true;
        game->press.space = true;
    }
    skip_dialog(game, pos_text);
}
