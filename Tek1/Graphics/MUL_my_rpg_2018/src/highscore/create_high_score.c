/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_high_score.c
*/

#include "my_rpg.h"

static void create_sprite_hs(game_t *game)
{
    game->sprite->back_hs = sfSprite_create();
    game->texture->back_hs =
    sfTexture_createFromFile("assets/img/pause/back_pause.png", NULL);
    sfSprite_setTexture(game->sprite->back_hs, game->texture->back_hs, sfTrue);
    sfSprite_setPosition(game->sprite->back_hs,
    (sfVector2f){620 * game->win.ratio, 150 * game->win.ratio});
    sfSprite_setScale(game->sprite->back_hs,
    (sfVector2f){8 * game->win.ratio, 8 * game->win.ratio});
}

static void create_text_hs2(game_t *game)
{
    sfText_setPosition(game->text.hs,
    (sfVector2f){750 * game->win.ratio, 275 * game->win.ratio});
    sfText_setColor(game->text.hs, sfColor_fromRGB(255, 219, 38));
}

static void create_text_hs(game_t *game)
{
    sfText_setFont(game->text.hs, game->text.font_highscore);
    sfText_setCharacterSize(game->text.hs, 70);
    sfText_setString(game->text.hs, "HIGH SCORE");
    create_text_hs2(game);
}

void create_high_score(game_t *game)
{
    game->text.hs = sfText_create();
    game->text.font_highscore =
    sfFont_createFromFile("assets/font/game.ttf");
    create_sprite_hs(game);
    create_text_hs(game);
}