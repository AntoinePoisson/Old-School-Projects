/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "defender.h"

void transition_menu_to_game(variable_t *sf)
{
    sfIntRect rect;
    float seconds = 0;
    sfColor alpha;

    rect.top = 2400;
    rect.left = 2532;
    rect.width = 1600;
    rect.height = 800;
    sfSprite_setTextureRect(sf->sprite.end_level, rect);
    for (alpha.a = 0; alpha.a <= 80;) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (seconds >= 0.013) {
            sfSprite_setColor(sf->sprite.end_level, alpha);
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.end_level, NULL);
            sfRenderWindow_display(sf->win.dow);
            alpha.a += 2;
            sfClock_restart(sf->clock.menu);
        }
    }
}
