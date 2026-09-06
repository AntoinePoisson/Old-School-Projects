/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create a custom rpg
*/

#include "my_rpg.h"

void event_move_mouse(game_t *game)
{
    game->vector.mouse.x =
    sfMouse_getPositionRenderWindow(game->win.dow).x;
    game->vector.mouse.y =
    sfMouse_getPositionRenderWindow(game->win.dow).y;
    sfSprite_setPosition(game->sprite->cursor,
    (sfVector2f){game->vector.mouse.x, game->vector.mouse.y});
}

void event_close(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win.dow, &game->win.event)) {
        if (game->win.event.type == sfEvtClosed ||
        (sfKeyboard_isKeyPressed(sfKeyEscape) &&
        !game->press.escape))
            sfRenderWindow_close(game->win.dow);
    }
}

void event_skip(bool *close, game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyEscape) && !game->press.escape) ||
        (sfMouse_isButtonPressed(sfMouseLeft)) ||
        (sfKeyboard_isKeyPressed(sfKeySpace)) ||
        (sfKeyboard_isKeyPressed(sfKeyA)) ||
        (sfKeyboard_isKeyPressed(sfKeyQ))) {
        close[0] = true;
        game->intro->alpha = 0;
        game->press.escape = true;
        game->intro->fade = 0;
        game->intro->alpha = 0;
        sfRectangleShape_setFillColor(game->intro->rectangle,
        sfColor_fromRGBA(0, 0, 0, 0));
    }
}

void event_menu(game_t *game)
{
    event_close(game);
    if (game->win.event.type == sfEvtKeyReleased &&
        game->win.event.key.code == sfKeyEscape && game->press.escape)
        game->press.escape = false;
}

void event_intro(game_t *game, bool *close)
{
    event_skip(close, game);
    event_close(game);
    if (game->win.event.type == sfEvtKeyReleased &&
        game->win.event.key.code == sfKeyEscape && game->press.escape)
        game->press.escape = false;
}
