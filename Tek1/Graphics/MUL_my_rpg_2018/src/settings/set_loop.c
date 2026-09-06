/*
** EPITECH PROJECT, 2019
** set_loop
** File description:
** Loop of the settings
*/

#include "my_rpg.h"

static void event_set_loop(game_t *game, bool *close)
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

void follow_cursor(game_t *game)
{
    game->vector.mouse.x = sfMouse_getPositionRenderWindow(game->win.dow).x;
    game->vector.mouse.y = sfMouse_getPositionRenderWindow(game->win.dow).y;
    sfSprite_setPosition(game->sprite->cursor,
        (sfVector2f){game->vector.mouse.x, game->vector.mouse.y});
}

static void init_bool_set(game_t *game)
{
    game->press.click = false;
    game->press.vsync = false;
    game->var.disp_music = false;
    game->press.fullscreen = false;
    game->press.click_music = false;
    create_set_loop(game);
}

void set_loop(game_t *game)
{
    bool close = false;

    init_bool_set(game);
    while (sfRenderWindow_isOpen(game->win.dow)) {
        event_set_loop(game, &close);
        event_clik_music_but(game);
        if (close)
            break;
        set_pos_scale_set_menu(game);
        follow_cursor(game);
        third_states_buttons_set_menu(game);
        click_buttons_set_menu(game);
        draw_set_loop(game);
        if (sfClock_getElapsedTime(game->clock->particle).microseconds
            >= 30000) {
            manage_particle(game);
            sfClock_restart(game->clock->particle);
        }
        change_sprite_set_menu(game);
    }
}