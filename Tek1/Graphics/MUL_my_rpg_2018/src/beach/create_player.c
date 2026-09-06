/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create perso
*/

#include "my_rpg.h"

static void create_texture_beach_loop(game_t *game)
{
    if (game->var.chara == 1)
        game->texture->player =
        sfTexture_createFromFile("assets/img/player_skin/knight_a.png", NULL);
    if (game->var.chara == 2)
        game->texture->player =
        sfTexture_createFromFile("assets/img/player_skin/priest_a.png", NULL);
    if (game->var.chara == 3)
        game->texture->player =
        sfTexture_createFromFile("assets/img/player_skin/sorcerer_a.png", NULL);
    if (game->var.chara == 4)
        game->texture->player =
        sfTexture_createFromFile("assets/img/player_skin/thief_a.png", NULL);
    if (game->var.chara == 5)
        game->texture->player =
        sfTexture_createFromFile("assets/img/player_skin/wizard_a.png", NULL);
    game->texture->pnj_beach =
    sfTexture_createFromFile("assets/img/player_skin/pnj_beach.png", NULL);
}

static void create_player_2(game_t *game)
{
    sfSprite_setPosition(game->sprite->player,
    (sfVector2f){1148 * game->win.ratio, 1200 * game->win.ratio});
    sfSprite_setPosition(game->sprite->pnj_beach,
    (sfVector2f){1880 * game->win.ratio, 158 * game->win.ratio});
    sfSprite_setScale(game->sprite->player,
    (sfVector2f){3 * game->win.ratio, 3 * game->win.ratio});
    sfSprite_setScale(game->sprite->pnj_beach,
    (sfVector2f){1.8 * game->win.ratio, 1.8 * game->win.ratio});
    sfSprite_setOrigin(game->sprite->player, (sfVector2f){6, 0});
    sfSprite_setOrigin(game->sprite->pnj_beach, (sfVector2f){6, 0});
    sfSprite_setTextureRect(game->sprite->player, game->rect.player);
    sfSprite_setTextureRect(game->sprite->pnj_beach, game->rect.pnj_beach);
}

void create_player(game_t *game)
{
    game->rect.player = (sfIntRect){0, 0, 25, 25};
    game->rect.pnj_beach = (sfIntRect){0, 316, 60, 64};
    game->sprite->player = sfSprite_create();
    game->sprite->pnj_beach = sfSprite_create();
    game->player.clock_regen = sfClock_create();
    game->text.launch_dial = sfText_create();
    game->text.game_police = sfFont_createFromFile("assets/font/game.ttf");
    sfText_setFont(game->text.launch_dial, game->text.game_police);
    sfText_setString(game->text.launch_dial, "Press e to talk !");
    sfText_setCharacterSize(game->text.launch_dial, 25);
    sfText_setPosition(game->text.launch_dial,
    (sfVector2f){1835 * game->win.ratio, 150 * game->win.ratio});
    sfText_setColor(game->text.launch_dial, sfYellow);
    create_texture_beach_loop(game);
    sfSprite_setTexture(game->sprite->player,
    game->texture->player, sfTrue);
    sfSprite_setTexture(game->sprite->pnj_beach,
    game->texture->pnj_beach, sfTrue);
    create_player_2(game);
    game->clock->player_move = sfClock_create();
}
