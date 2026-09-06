/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_htp.c
*/

#include "my_rpg.h"

static void create_text_htp(game_t *game)
{
    game->text.text_htp = sfText_create();
    sfText_setFont(game->text.text_htp, game->text.font_highscore);
    sfText_setCharacterSize(game->text.text_htp, 35);
    sfText_setString(game->text.text_htp, HTP);
    sfText_setPosition(game->text.text_htp,
    (sfVector2f){725 * game->win.ratio, 275 * game->win.ratio});
    sfText_setColor(game->text.text_htp, sfColor_fromRGB(255, 219, 38));
}

static void create_sprite_htp(game_t *game)
{
    game->sprite->back_htp = sfSprite_create();
    game->text.font_highscore = sfFont_createFromFile("assets/font/game.ttf");
    game->texture->back_htp =
    sfTexture_createFromFile("assets/img/pause/back_pause.png", NULL);
    sfSprite_setTexture(game->sprite->back_htp,
    game->texture->back_htp, sfTrue);
    sfSprite_setPosition(game->sprite->back_htp,
    (sfVector2f){620 * game->win.ratio, 150 * game->win.ratio});
    sfSprite_setScale(game->sprite->back_htp,
    (sfVector2f){8 * game->win.ratio, 8 * game->win.ratio});
}

void create_htp(game_t *game)
{
    create_sprite_htp(game);
    create_text_htp(game);
}
