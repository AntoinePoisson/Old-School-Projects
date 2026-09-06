/*
** EPITECH PROJECT, 2019
** draw_set_loop
** File description:
** Draw set loop
*/

#include "my_rpg.h"

void draw_set_loop(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->menu, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud_set, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->logo, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->fullscreen, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->vsync, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->music_but, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.fullscreen, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.vsync, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.music, NULL);
}