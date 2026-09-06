/*
** EPITECH PROJECT, 2019
** check_pos_dialog
** File description:
** Check position of the player to lunch dialog box
*/

#include "my_rpg.h"

void check_pos_player_to_dialog(game_t *game)
{
    sfVector2f player = sfSprite_getPosition(game->sprite->player);
    sfVector2f pnj = sfSprite_getPosition(game->sprite->pnj_beach);

    if (player.x >= pnj.x - 50 &&
        player.x <= pnj.x + 100 * game->win.ratio &&
        player.y >= pnj.y &&
        player.y <= pnj.y + 110 * game->win.ratio) {
        sfRenderWindow_drawText(game->win.dow, game->text.launch_dial, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) && !game->var.disp_dial)
            game->var.disp_dial = true;
        if (game->var.disp_dial)
            launch_dialog(game);
    }
    sfRenderWindow_display(game->win.dow);
    sfRenderWindow_clear(game->win.dow, sfBlack);
}
