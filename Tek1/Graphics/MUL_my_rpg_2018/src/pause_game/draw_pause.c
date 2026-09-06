/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** draw_pause.c
*/

#include "my_rpg.h"

static void draw_resume(game_t *game)
{
    sfVector2f resume = sfSprite_getPosition(game->sprite->resume_1);

    resume.x -= game->view.offset.x;
    resume.y -= game->view.offset.y;
    resume.x *= game->win.ratio;
    resume.y *= game->win.ratio;
    if (game->vector.mouse.x >= resume.x &&
        game->vector.mouse.x <= resume.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= resume.y &&
        game->vector.mouse.y <= resume.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->resume_2, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->resume_1, NULL);
}

static void draw_quit(game_t *game)
{
    sfVector2f quit = sfSprite_getPosition(game->sprite->quit_1);

    quit.x -= game->view.offset.x;
    quit.y -= game->view.offset.y;
    quit.x *= game->win.ratio;
    quit.y *= game->win.ratio;
    if (game->vector.mouse.x >= quit.x &&
        game->vector.mouse.x <= quit.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= quit.y &&
        game->vector.mouse.y <= quit.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->quit_2, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->quit_1, NULL);
}

static void draw_btm(game_t *game)
{
    sfVector2f btm = sfSprite_getPosition(game->sprite->btm_1);

    btm.x -= game->view.offset.x;
    btm.y -= game->view.offset.y;
    btm.x *= game->win.ratio;
    btm.y *= game->win.ratio;
    if (game->vector.mouse.x >= btm.x &&
        game->vector.mouse.x <= btm.x + 430 * game->win.ratio &&
        game->vector.mouse.y >= btm.y &&
        game->vector.mouse.y <= btm.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->btm_2, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->btm_1, NULL);
}

void draw_buttons_pause(game_t *game)
{
    draw_resume(game);
    draw_btm(game);
    draw_quit(game);
}