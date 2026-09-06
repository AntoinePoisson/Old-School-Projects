/*
** EPITECH PROJECT, 2019
** create_inventory
** File description:
** Creation of inventory
*/

#include "my_rpg.h"

void set_pos_inventory(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    view.x = view.x - 600 * game->win.ratio;
    view.y = view.y - 310 * game->win.ratio;
    sfSprite_setPosition(game->sprite->inventory, view);
}

void create_inventory(game_t *game)
{
    game->sprite->inventory = sfSprite_create();
    game->texture->inventory =
        sfTexture_createFromFile("assets/img/inventory/inventory.png", NULL);
    sfSprite_setTexture(game->sprite->inventory,
        game->texture->inventory, sfTrue);
    sfSprite_setScale(game->sprite->inventory,
        (sfVector2f){1 * game->win.ratio, 1 * game->win.ratio});
}
