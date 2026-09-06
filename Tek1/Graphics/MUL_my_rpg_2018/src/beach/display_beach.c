/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Main loop of the game
*/

#include "my_rpg.h"

void display_beach(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->beach_intro, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->pnj_beach, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->player, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->beach_intro2, NULL);
    sfSprite_move(game->sprite->cursor, game->view.offset);
}
