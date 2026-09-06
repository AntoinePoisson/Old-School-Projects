/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_pause.c
*/

#include "my_rpg.h"

static void set_pos_pause_2(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    sfSprite_setPosition(game->sprite->btm_2,
    (sfVector2f){view.x - 244 * game->win.ratio,
    view.y - 60 * game->win.ratio});
    sfSprite_setPosition(game->sprite->quit_1,
    (sfVector2f){view.x - 220 * game->win.ratio,
    view.y + 200 * game->win.ratio});
    sfSprite_setPosition(game->sprite->quit_2,
    (sfVector2f){view.x - 244 * game->win.ratio,
    view.y + 200 * game->win.ratio});
}

void set_pos_pause(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    sfSprite_setPosition(game->sprite->back_pause,
    (sfVector2f){view.x - 400 * game->win.ratio,
    view.y - 450 * game->win.ratio});
    sfSprite_setPosition(game->sprite->resume_1,
    (sfVector2f){view.x - 220 * game->win.ratio,
    view.y - 320 * game->win.ratio});
    sfSprite_setPosition(game->sprite->resume_2,
    (sfVector2f){view.x - 244 * game->win.ratio,
    view.y - 320 * game->win.ratio});
    sfSprite_setPosition(game->sprite->btm_1,
    (sfVector2f){view.x - 220 * game->win.ratio,
    view.y - 60 * game->win.ratio});
    set_pos_pause_2(game);
}

static void texture_scale_pause(game_t *game)
{
    sfSprite_setTexture(game->sprite->resume_1,
    game->texture->resume_1, sfTrue);
    sfSprite_setTexture(game->sprite->resume_2,
    game->texture->resume_2, sfTrue);
    sfSprite_setTexture(game->sprite->btm_1,
    game->texture->btm_1, sfTrue);
    sfSprite_setTexture(game->sprite->btm_2,
    game->texture->btm_2, sfTrue);
    sfSprite_setTexture(game->sprite->quit_1,
    game->texture->quit_1, sfTrue);
    sfSprite_setTexture(game->sprite->quit_2,
    game->texture->quit_2, sfTrue);
    sfSprite_setScale(game->sprite->back_pause,
    (sfVector2f){9 * game->win.ratio, 9 * game->win.ratio});
    sfSprite_setScale(game->sprite->resume_1,
    (sfVector2f){6 * game->win.ratio, 6 * game->win.ratio});
    sfSprite_setScale(game->sprite->btm_1,
    (sfVector2f){6 * game->win.ratio, 6 * game->win.ratio});
    sfSprite_setScale(game->sprite->quit_1,
    (sfVector2f){6 * game->win.ratio, 6 * game->win.ratio});
}

static void create_texture_from_file(game_t *game)
{
    game->texture->back_pause =
    sfTexture_createFromFile("assets/img/pause/back_pause.png", NULL);
    game->texture->resume_1 =
    sfTexture_createFromFile("assets/img/pause/resume_1.png", NULL);
    game->texture->resume_2 =
    sfTexture_createFromFile("assets/img/pause/resume_2.png", NULL);
    game->texture->quit_1 =
    sfTexture_createFromFile("assets/img/pause/exit1.png", NULL);
    game->texture->quit_2 =
    sfTexture_createFromFile("assets/img/pause/exit2.png", NULL);
    game->texture->btm_1 =
    sfTexture_createFromFile("assets/img/pause/btm1.png", NULL);
    game->texture->btm_2 =
    sfTexture_createFromFile("assets/img/pause/btm_2.png", NULL);
}

void create_pause(game_t *game)
{
    game->sprite->back_pause = sfSprite_create();
    game->sprite->resume_1 = sfSprite_create();
    game->sprite->resume_2 = sfSprite_create();
    game->sprite->btm_1 = sfSprite_create();
    game->sprite->btm_2 = sfSprite_create();
    game->sprite->quit_1 = sfSprite_create();
    game->sprite->quit_2 = sfSprite_create();
    create_texture_from_file(game);
    sfSprite_setTexture(game->sprite->back_pause,
    game->texture->back_pause, sfTrue);
    texture_scale_pause(game);
}
