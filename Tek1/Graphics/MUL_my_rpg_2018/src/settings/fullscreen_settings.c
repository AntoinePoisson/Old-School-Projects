/*
** EPITECH PROJECT, 2019
** fullscreen_settings
** File description:
** fullscreen
*/

#include "my_rpg.h"

void change_fullscreen_one(game_t *game)
{
    sfRenderWindow_destroy(game->win.dow);
    game->win.dow = sfRenderWindow_create((sfVideoMode)
    {1920 * game->win.ratio, 1080 * game->win.ratio, 32}, "My_defender",
    sfFullscreen | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->win.dow, 60);
}

void change_fullscreen_two(game_t *game)
{
    sfRenderWindow_destroy(game->win.dow);
    game->win.dow = sfRenderWindow_create((sfVideoMode)
    {1920 * game->win.ratio, 1080 * game->win.ratio, 32}, "My_defender",
    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->win.dow, 60);
}

void change_fullscreen(game_t *game, sfVector2f full_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->vector.mouse.x >= full_pos.x && game->press.click == 0 &&
    game->vector.mouse.x <= full_pos.x + 50 * game->win.ratio &&
    game->vector.mouse.y >= full_pos.y &&
    game->vector.mouse.y <= full_pos.y + 50 * game->win.ratio) {
        game->press.fullscreen = !game->press.fullscreen;
        if (game->press.fullscreen) {
            change_fullscreen_one(game);
        } else {
            change_fullscreen_two(game);
        }
        game->press.click = false;
        game->press.fullscreen = false;
        sfRenderWindow_setMouseCursorVisible(game->win.dow, sfFalse);
    }
}
