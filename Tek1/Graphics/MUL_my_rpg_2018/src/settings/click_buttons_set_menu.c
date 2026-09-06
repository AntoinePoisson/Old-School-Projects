/*
** EPITECH PROJECT, 2019
** click_buttons_set_menu
** File description:
** Click on buttons in settings menu
*/

#include "my_rpg.h"

void scale_resize(game_t *game)
{
    sfRenderWindow_destroy(game->win.dow);
    game->var.fullscreen = 0;
    if (game->var.fullscreen) {
        game->win.dow = sfRenderWindow_create((sfVideoMode)
        {1920 * game->win.ratio, 1080 * game->win.ratio, 32}, "My_RPG",
        sfFullscreen | sfClose, NULL);
    } else {
        game->win.dow = sfRenderWindow_create((sfVideoMode)
        {1920 * game->win.ratio, 1080 * game->win.ratio, 32}, "My_RPG",
        sfClose, NULL);
    }
    sfRenderWindow_setFramerateLimit(game->win.dow, 60);
}

void reset_ratio(game_t *game, int which_one)
{
    if (which_one == 0) {
        game->press.click = true;
        game->win.ratio = 1;
        scale_resize(game);
    } else {
        game->press.click = 1;
        game->win.ratio = 0.86666667;
        scale_resize(game);
    }
    sfRenderWindow_setMouseCursorVisible(game->win.dow, sfFalse);
}
