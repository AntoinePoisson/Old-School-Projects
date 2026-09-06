/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** event_inventory.c
*/

#include "my_rpg.h"

void event_open_inventory(game_t *game)
{
    if (game->win.event.type == sfEvtKeyPressed &&
        game->win.event.key.code == sfKeyI && game->press.inventory == false) {
        game->press.inventory = true;
        game->var.disp_inventory = !game->var.disp_inventory;
    }
    if (game->win.event.type == sfEvtKeyReleased &&
        game->win.event.key.code == sfKeyI && game->press.inventory) {
        game->press.inventory = false;
    }
}
