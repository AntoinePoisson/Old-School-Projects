/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** state_pause.c
*/

#include "my_rpg.h"

static void state_resume(game_t *game)
{
    sfVector2f resume = sfSprite_getPosition(game->sprite->resume_1);

    resume.x -= game->view.offset.x;
    resume.y -= game->view.offset.y;
    resume.x *= game->win.ratio;
    resume.y *= game->win.ratio;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        game->vector.mouse.x >= resume.x &&
        game->vector.mouse.x <= resume.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= resume.y &&
        game->vector.mouse.y <= resume.y + 110 * game->win.ratio) {
        sfSprite_setScale(game->sprite->resume_2,
        (sfVector2f){5.8 * game->win.ratio, 5.8 * game->win.ratio});
    } else {
        sfSprite_setScale(game->sprite->resume_2,
        (sfVector2f){6 * game->win.ratio, 6 * game->win.ratio});
    }
}

static void state_btm(game_t *game)
{
    sfVector2f btm = sfSprite_getPosition(game->sprite->btm_1);

    btm.x -= game->view.offset.x;
    btm.y -= game->view.offset.y;
    btm.x *= game->win.ratio;
    btm.y *= game->win.ratio;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        game->vector.mouse.x >= btm.x &&
        game->vector.mouse.x <= btm.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= btm.y &&
        game->vector.mouse.y <= btm.y + 110 * game->win.ratio) {
        sfSprite_setScale(game->sprite->btm_2,
        (sfVector2f){5.8 * game->win.ratio, 5.8 * game->win.ratio});
    } else {
        sfSprite_setScale(game->sprite->btm_2,
        (sfVector2f){6 * game->win.ratio, 6 * game->win.ratio});
    }
}

static void state_quit(game_t *game)
{
    sfVector2f quit = sfSprite_getPosition(game->sprite->quit_1);

    quit.x -= game->view.offset.x;
    quit.y -= game->view.offset.y;
    quit.x *= game->win.ratio;
    quit.y *= game->win.ratio;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        game->vector.mouse.x >= quit.x &&
        game->vector.mouse.x <= quit.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= quit.y &&
        game->vector.mouse.y <= quit.y + 110 * game->win.ratio) {
        sfSprite_setScale(game->sprite->quit_2,
        (sfVector2f){5.8 * game->win.ratio, 5.8 * game->win.ratio});
    } else {
        sfSprite_setScale(game->sprite->quit_2,
        (sfVector2f){6 * game->win.ratio, 6 * game->win.ratio});
    }
}

void state_buttons_pause(game_t *game)
{
    state_resume(game);
    state_btm(game);
    state_quit(game);
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->press.click)
        game->press.click = false;
}