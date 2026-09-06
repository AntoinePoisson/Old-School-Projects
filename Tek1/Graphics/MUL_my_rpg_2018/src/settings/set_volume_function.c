/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** set_volume_function.c
*/

#include "my_rpg.h"

static void click_music_but_on(game_t *game)
{
    sfVector2f music_pos = sfSprite_getPosition(game->sprite->music_but);

    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft
        && game->vector.mouse.x >= music_pos.x
        && game->vector.mouse.x <= music_pos.x + 55 * game->win.ratio
        && game->vector.mouse.y >= music_pos.y
        && game->vector.mouse.y <= music_pos.y + 55 * game->win.ratio
        && !game->press.click && !game->var.disp_music) {
        game->press.click = true;
        game->var.disp_music = true;
        sfMusic_stop(game->music->menu);
    }
}

static void click_music_but_off(game_t *game)
{
    sfVector2f music_pos = sfSprite_getPosition(game->sprite->music_but);

    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft
        && game->vector.mouse.x >= music_pos.x
        && game->vector.mouse.x <= music_pos.x + 55 * game->win.ratio
        && game->vector.mouse.y >= music_pos.y
        && game->vector.mouse.y <= music_pos.y + 55 * game->win.ratio
        && !game->press.click && game->var.disp_music) {
        game->press.click = true;
        game->var.disp_music = false;
        sfMusic_play(game->music->menu);
    }
}

void click_music_but(game_t *game)
{
    click_music_but_on(game);
    click_music_but_off(game);
}