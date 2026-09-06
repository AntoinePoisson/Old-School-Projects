/*
** EPITECH PROJECT, 2019
** create_background
** File description:
** Creation of the background
*/

#include "my_rpg.h"

int create_particle(game_t *game)
{
    menu_particle_t *particle = malloc(sizeof(menu_particle_t));
    menu_particle_t *tmp = game->menu_particle;
    int size = rand() % 7 + 2;

    if (particle == NULL)
        return (84);
    particle->next = NULL;
    particle->speed = (sfVector2f){(rand() % 50 + 10) / 10 * game->win.ratio,
        (rand() % 50 + 10) / 10 * game->win.ratio};
    particle->pos = (sfVector2f){rand() % (int)(1920 * game->win.ratio),
        rand() % 2 * (1180 - 50) * game->win.ratio};
    particle->size = (sfVector2f){(float)size * game->win.ratio,
        (float)size * game->win.ratio};
    if (!game->menu_particle) {
        game->menu_particle = particle;
    } else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = particle;
    }
    return (0);
}

void add_particle(game_t *game, int nb)
{
    int i = 0;

    for (; i < nb; i++)
        create_particle(game);
}

int manage_particle(game_t *game)
{
    menu_particle_t *tmp = game->menu_particle;
    menu_particle_t *backup = NULL;

    if (sfClock_getElapsedTime(game->clock->particle).microseconds > 30000)
        sfClock_restart(game->clock->particle);
    else
        return (0);
    while (tmp) {
        tmp->pos.x += tmp->speed.x + rand() % 3 - 1;
        tmp->pos.y += tmp->speed.y + rand() % 3 - 1;
        backup = tmp->next;
        if (tmp->pos.x < -70 * game->win.ratio
            || tmp->pos.x > 1990 * game->win.ratio
            || tmp->pos.y < -70 * game->win.ratio
            || tmp->pos.y > 1150 * game->win.ratio) {
            destroy_particle(game, tmp);
            add_particle(game, 1);
        }
        tmp = backup;
    }
    return (0);
}
