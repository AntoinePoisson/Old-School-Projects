/*
** EPITECH PROJECT, 2019
** draw_sprite_menu
** File description:
** rpg
*/

#include "my_rpg.h"

void size_1920(game_t *game)
{
    sfVector2f pos_1920 = sfSprite_getPosition(game->sprite->size_1920_1);

    if (game->vector.mouse.x >= pos_1920.x &&
        game->vector.mouse.x <= pos_1920.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= pos_1920.y &&
        game->vector.mouse.y <= pos_1920.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->size_1920_2, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->size_1920_1, NULL);
}

void size_1664(game_t *game)
{
    sfVector2f pos_1664 = sfSprite_getPosition(game->sprite->size_1664_1);

    if (game->vector.mouse.x >= pos_1664.x &&
        game->vector.mouse.x <= pos_1664.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= pos_1664.y &&
        game->vector.mouse.y <= pos_1664.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->size_1664_2, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->size_1664_1, NULL);
}

void size_1280(game_t *game)
{
    sfVector2f pos_1280 = sfSprite_getPosition(game->sprite->size_1280_1);

    if (game->vector.mouse.x >= pos_1280.x &&
        game->vector.mouse.x <= pos_1280.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= pos_1280.y &&
        game->vector.mouse.y <= pos_1280.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->size_1280_2, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->size_1280_1, NULL);
}

void key_bindings(game_t *game)
{
    sfVector2f pos_key = sfSprite_getPosition(game->sprite->key_bindings_1);

    if (game->vector.mouse.x >= pos_key.x &&
        game->vector.mouse.x <= pos_key.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= pos_key.y &&
        game->vector.mouse.y <= pos_key.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->key_bindings_2, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->key_bindings_1, NULL);
}
