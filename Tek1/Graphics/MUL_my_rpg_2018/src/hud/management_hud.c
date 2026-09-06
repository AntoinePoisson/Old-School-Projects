/*
** EPITECH PROJECT, 2019
** management_hud.c
** File description:
** management hud
*/

#include "my_rpg.h"

void create_hud(game_t *game)
{
    game->sprite->hud = sfSprite_create();
    game->texture->hud =
    sfTexture_createFromFile("assets/img/hud/hud.png", NULL);
    sfSprite_setTexture(game->sprite->hud,
    game->texture->hud, sfTrue);
}

void destroy_hud(game_t *game)
{
    sfSprite_destroy(game->sprite->hud);
    sfTexture_destroy(game->texture->hud);
}

void management_hud(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    display_potion(game);
    view.x = view.x - 960 * game->win.ratio;
    view.y = view.y + 4 * game->win.ratio;
    sfSprite_setPosition(game->sprite->hud, view);
    sfSprite_setTextureRect(game->sprite->hud,
        (sfIntRect){805, 709, 224, 536});
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
    sfSprite_setTextureRect(game->sprite->hud,
        (sfIntRect){2039, 709, 224, 536});
    view = sfView_getCenter(game->view.view);
    view.x = view.x + 760 * game->win.ratio;
    view.y = view.y + 4 * game->win.ratio;
    sfSprite_setPosition(game->sprite->hud, view);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
    display_hud(game);
    display_skill(game);
}