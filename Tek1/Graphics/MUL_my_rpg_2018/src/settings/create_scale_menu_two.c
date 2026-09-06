/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** scale set menu
*/

#include "my_rpg.h"

void is_extension_create_set_loop(game_t *game)
{
    game->rect.full_but = (sfIntRect){0, 0, 11, 11};
    sfSprite_setTexture(game->sprite->size_1664_2,
    game->texture->size_1664_2, sfTrue);
}