/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw all button
*/

#include "my_rpg.h"

void draw_buttons_main_menu(game_t *game)
{
    game->vector.mouse.x = sfMouse_getPositionRenderWindow(game->win.dow).x;
    game->vector.mouse.y = sfMouse_getPositionRenderWindow(game->win.dow).y;
    draw_play(game);
    draw_set(game);
    draw_htp(game);
    draw_high_score(game);
    draw_exit(game);
}
