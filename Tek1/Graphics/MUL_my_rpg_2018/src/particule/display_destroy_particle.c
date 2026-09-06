/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display and destroy particle
*/

#include "my_rpg.h"

void destroy_particle(game_t *game, menu_particle_t *particle)
{
    menu_particle_t *tmp = game->menu_particle;

    if (particle == game->menu_particle) {
        game->menu_particle = game->menu_particle->next;
        free(particle);
    } else {
        while (tmp->next != particle)
            tmp = tmp->next;
        tmp->next = tmp->next->next;
        free(particle);
    }
}

void display_particle(game_t *game)
{
    menu_particle_t *tmp = game->menu_particle;

    while (tmp) {
        sfRectangleShape_setSize(game->particle->rectangle, tmp->size);
        sfRectangleShape_setPosition(game->particle->rectangle, tmp->pos);
        sfRenderWindow_drawRectangleShape(game->win.dow,
        game->particle->rectangle, NULL);
        tmp = tmp->next;
    }
}

void destroy_rain_particle(game_t *game, rain_particle_t *particle)
{
    rain_particle_t *tmp = game->rain_particle;

    if (particle == game->rain_particle) {
        game->rain_particle = game->rain_particle->next;
        free(particle);
    } else {
        while (tmp->next != particle)
            tmp = tmp->next;
        tmp->next = tmp->next->next;
        free(particle);
    }
}

void display_rain_particle(game_t *game)
{
    rain_particle_t *tmp = game->rain_particle;

    while (tmp) {
        sfSprite_setPosition(game->sprite->rain, tmp->pos);
        sfSprite_setTextureRect(game->sprite->rain, tmp->rect);
        sfSprite_setColor(game->sprite->rain,
        sfColor_fromRGBA(255, 255, 255, 150));
        sfRenderWindow_drawSprite(game->win.dow,
        game->sprite->rain, NULL);
        tmp = tmp->next;
    }
}
