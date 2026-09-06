/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** click_pause.c
*/

#include "my_rpg.h"

static void click_resume(game_t *game)
{
    sfVector2f resume = sfSprite_getPosition(game->sprite->resume_1);

    resume.x -= game->view.offset.x * game->win.ratio;
    resume.y -= game->view.offset.y * game->win.ratio;
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= resume.x &&
        game->vector.mouse.x <= resume.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= resume.y &&
        game->vector.mouse.y <= resume.y + 110 * game->win.ratio &&
        !game->var.pause)
        game->var.pause = true;
}

static void click_btm(game_t *game)
{
    sfVector2f btm = sfSprite_getPosition(game->sprite->btm_1);

    btm.x -= game->view.offset.x * game->win.ratio;
    btm.y -= game->view.offset.y * game->win.ratio;
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= btm.x &&
        game->vector.mouse.x <= btm.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= btm.y &&
        game->vector.mouse.y <= btm.y + 110 * game->win.ratio &&
        !game->var.pause) {
        game->var.quit_beach = 1;
        game->var.quit_donjon = 1;
        game->var.pause = true;
        sfView_reset(game->view.view, (sfFloatRect){0, 0, 1920, 1080});
    }
}

static void click_quit(game_t *game)
{
    sfVector2f quit = sfSprite_getPosition(game->sprite->quit_1);

    quit.x -= game->view.offset.x * game->win.ratio;
    quit.y -= game->view.offset.y * game->win.ratio;
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= quit.x &&
        game->vector.mouse.x <= quit.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= quit.y &&
        game->vector.mouse.y <= quit.y + 110 * game->win.ratio &&
        !game->var.pause) {
        game->var.pause = true;
        game->var.quit_beach = 1;
        game->var.quit_donjon = 1;
        sfRenderWindow_close(game->win.dow);
    }
}

void click_buttons_pause(game_t *game)
{
    click_resume(game);
    click_btm(game);
    click_quit(game);
}