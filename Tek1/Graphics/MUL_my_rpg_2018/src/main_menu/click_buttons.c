/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** click buttons
*/

#include "my_rpg.h"

void click_button(game_t *game, sfVector2f pos_1920, sfVector2f pos_1664)
{
    if (game->win.event.type == sfEvtMouseButtonReleased &&
    game->win.event.mouseButton.button == sfMouseLeft &&
    game->vector.mouse.x >= pos_1920.x &&
    game->vector.mouse.x <= pos_1920.x + 380 * game->win.ratio &&
    game->vector.mouse.y >= pos_1920.y &&
    game->vector.mouse.y <= pos_1920.y + 110 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        game->win.ratio = 1;
        reset_ratio(game, 0);
    } if (game->win.event.type == sfEvtMouseButtonReleased &&
    game->win.event.mouseButton.button == sfMouseLeft &&
    game->vector.mouse.x >= pos_1664.x &&
    game->vector.mouse.x <= pos_1664.x + 380 * game->win.ratio &&
    game->vector.mouse.y >= pos_1664.y &&
    game->vector.mouse.y <= pos_1664.y + 110 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        reset_ratio(game, 1);
    }
}

void click_button_set(game_t *game, sfVector2f pos_1280)
{
    if (game->win.event.type == sfEvtMouseButtonReleased &&
    game->win.event.mouseButton.button == sfMouseLeft &&
    game->vector.mouse.x >= pos_1280.x &&
    game->vector.mouse.x <= pos_1280.x + 380 * game->win.ratio &&
    game->vector.mouse.y >= pos_1280.y &&
    game->vector.mouse.y <= pos_1280.y + 110 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        game->win.ratio = 0.66666667;
        scale_resize(game);
        sfRenderWindow_setMouseCursorVisible(game->win.dow, sfFalse);
    }
}

void click_set_menu(game_t *game, sfVector2f pos_vsync, sfVector2f pos_full)
{
    if (game->win.event.type == sfEvtMouseButtonReleased &&
    game->win.event.mouseButton.button == sfMouseLeft &&
    game->vector.mouse.x >= pos_vsync.x &&
    game->vector.mouse.x <= pos_vsync.x + 55 * game->win.ratio &&
    game->vector.mouse.y >= pos_vsync.y &&
    game->vector.mouse.y <= pos_vsync.y + 55 * game->win.ratio &&
    game->press.click && game->press.vsync) {
        game->press.click = false;
        game->press.vsync = false;
        sfRenderWindow_setVerticalSyncEnabled(game->win.dow, sfFalse);
    }
    change_fullscreen(game, pos_full);
    click_music_but(game);
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->press.click)
        game->press.click = 0;
}

void click_buttons_set_menu(game_t *game)
{
    sfVector2f pos_1920 = sfSprite_getPosition(game->sprite->size_1920_1);
    sfVector2f pos_1664 = sfSprite_getPosition(game->sprite->size_1664_1);
    sfVector2f pos_1280 = sfSprite_getPosition(game->sprite->size_1280_1);
    sfVector2f pos_vsync = sfSprite_getPosition(game->sprite->vsync);
    sfVector2f pos_full = sfSprite_getPosition(game->sprite->fullscreen);

    click_button(game, pos_1920, pos_1664);
    click_button_set(game, pos_1280);
    if (game->win.event.type == sfEvtMouseButtonReleased &&
    game->win.event.mouseButton.button == sfMouseLeft &&
    game->vector.mouse.x >= pos_vsync.x &&
    game->vector.mouse.x <= pos_vsync.x + 55 * game->win.ratio &&
    game->vector.mouse.y >= pos_vsync.y &&
    game->vector.mouse.y <= pos_vsync.y + 55 * game->win.ratio &&
    !game->press.click && !game->press.vsync) {
        game->press.click = true;
        game->press.vsync = true;
        sfRenderWindow_setVerticalSyncEnabled(game->win.dow, sfTrue);
    }
    click_set_menu(game, pos_vsync, pos_full);
}
