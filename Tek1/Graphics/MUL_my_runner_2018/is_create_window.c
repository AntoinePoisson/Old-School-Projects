/*
** EPITECH PROJECT, 2018
** is_window_create
** File description:
** is_window_create
*/

#include "is_create_window.h"

void open_window(variable_t *sf)
{
    sfVideoMode Mode = {1600, 900, 32};

    sf->win.mode = Mode;
    sf->win.dow = sfRenderWindow_create(sf->win.mode, "My Runner",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(sf->win.dow, 40);
    sfRenderWindow_setKeyRepeatEnabled(sf->win.dow, 1);
}
