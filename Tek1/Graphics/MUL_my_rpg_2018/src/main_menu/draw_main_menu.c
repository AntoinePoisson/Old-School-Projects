/*
** EPITECH PROJECT, 2019
** draw_main_menu
** File description:
** Draw main menu
*/

#include "my_rpg.h"

void draw_main_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->menu, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud_menu, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->logo, NULL);
}