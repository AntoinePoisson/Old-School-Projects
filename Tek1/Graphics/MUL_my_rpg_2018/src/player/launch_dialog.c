/*
** EPITECH PROJECT, 2019
** check_pos_dialog
** File description:
** Check position of the player to lunch dialog box
*/

#include "my_rpg.h"

static void create_text_dialog2(game_t *game)
{
    sfText_setPosition(game->text.pnj_answ,
    (sfVector2f){950 * game->win.ratio, 840 * game->win.ratio});
    sfText_setPosition(game->text.player_answ,
    (sfVector2f){123123 * game->win.ratio, 123123 * game->win.ratio});
    sfText_setPosition(game->text.pnj_name,
    (sfVector2f){1140 * game->win.ratio, 630 * game->win.ratio});
    sfText_setPosition(game->text.player_name,
    (sfVector2f){18545 * game->win.ratio, 123123 * game->win.ratio});
}

static void create_text_dialog(game_t *game)
{
    game->text.pnj_answ = sfText_create();
    game->text.player_answ = sfText_create();
    game->text.pnj_name = sfText_create();
    game->text.player_name = sfText_create();
    game->text.press_space = sfText_create();
    sfText_setFont(game->text.player_answ, game->text.game_police);
    sfText_setFont(game->text.pnj_answ, game->text.game_police);
    sfText_setFont(game->text.player_name, game->text.game_police);
    sfText_setFont(game->text.pnj_name, game->text.game_police);
    sfText_setFont(game->text.press_space, game->text.game_police);
    sfText_setString(game->text.pnj_answ, PNJ_TEXT);
    sfText_setString(game->text.player_answ, PLAYER_TEXT);
    sfText_setString(game->text.pnj_name, "Anubis");
    sfText_setString(game->text.player_name, "Harry");
    sfText_setCharacterSize(game->text.pnj_answ, 40);
    sfText_setCharacterSize(game->text.player_answ, 50);
    sfText_setCharacterSize(game->text.pnj_name, 40);
    sfText_setCharacterSize(game->text.player_name, 40);
    sfText_setCharacterSize(game->text.press_space, 30);
    create_text_dialog2(game);
}

void create_dialog_hud(game_t *game)
{
    game->sprite->dialog = sfSprite_create();
    game->texture->dialog =
    sfTexture_createFromFile("assets/img/map/dialog.png", NULL);
    sfSprite_setTexture(game->sprite->dialog, game->texture->dialog, sfTrue);
    sfSprite_setScale(game->sprite->dialog,
    (sfVector2f){2 * game->win.ratio, 2 * game->win.ratio});
    sfSprite_setPosition(game->sprite->dialog,
    (sfVector2f){780 * game->win.ratio, 475 * game->win.ratio});
    create_text_dialog(game);
}

void launch_dialog(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->dialog, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.pnj_answ, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_answ, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.pnj_name, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_name, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.press_space, NULL);
}
