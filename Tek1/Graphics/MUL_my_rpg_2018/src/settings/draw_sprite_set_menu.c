/*
** EPITECH PROJECT, 2019
** change_sprite_set_menu
** File description:
** Change sprite set menu
*/

#include "my_rpg.h"

static void fullscreen_button(game_t *game)
{
    sfVector2f full_pos = sfSprite_getPosition(game->sprite->fullscreen);

    if (game->vector.mouse.x >= full_pos.x &&
        game->vector.mouse.x <= full_pos.x + 55 * game->win.ratio &&
        game->vector.mouse.y >= full_pos.y &&
        game->vector.mouse.y <= full_pos.y + 55 * game->win.ratio) {
        game->rect.full_but.top = 11;
        sfSprite_setTextureRect(game->sprite->fullscreen, game->rect.full_but);
    }
    else {
        game->rect.full_but.top = 0;
        sfSprite_setTextureRect(game->sprite->fullscreen, game->rect.full_but);
    }
}

static void vsync_button(game_t *game)
{
    sfVector2f vsync_pos = sfSprite_getPosition(game->sprite->vsync);

    if (game->vector.mouse.x >= vsync_pos.x &&
        game->vector.mouse.x <= vsync_pos.x + 55 * game->win.ratio &&
        game->vector.mouse.y >= vsync_pos.y &&
        game->vector.mouse.y <= vsync_pos.y + 55 * game->win.ratio) {
        game->rect.full_but.top = 11;
        sfSprite_setTextureRect(game->sprite->vsync, game->rect.full_but);
    }
    else {
        game->rect.full_but.top = 0;
        sfSprite_setTextureRect(game->sprite->vsync, game->rect.full_but);
    }
}

void change_sprite_set_menu(game_t *game)
{
    size_1920(game);
    size_1664(game);
    size_1280(game);
    key_bindings(game);
    fullscreen_button(game);
    vsync_button(game);
    display_particle(game);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
    sfRenderWindow_display(game->win.dow);
    sfRenderWindow_clear(game->win.dow, sfBlack);
}
