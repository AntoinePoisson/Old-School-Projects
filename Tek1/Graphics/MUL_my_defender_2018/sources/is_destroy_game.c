/*
** EPITECH PROJECT, 2018
** is_destroy_game.c
** File description:
** destroy all texture of game
*/

#include <stdlib.h>
#include "defender.h"

int destroy_game(variable_t *sf)
{
    sfSprite_destroy(sf->sprite.bg_game);
    sfTexture_destroy(sf->texture.bg_game);
    sfMusic_destroy(sf->music.canon);
    sfMusic_destroy(sf->music.attak);
    sfMusic_destroy(sf->music.trampo);
    sfMusic_destroy(sf->music.bombe);
    sfMusic_destroy(sf->music.loss);
    is_destroy_enemy(sf);
    free(sf->obj);
    free(sf->build);
    return (0);
}
