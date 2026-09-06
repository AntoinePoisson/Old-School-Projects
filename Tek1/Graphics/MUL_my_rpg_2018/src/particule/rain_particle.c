/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rain particle
*/

#include "my_rpg.h"

void create_rain(game_t *game, int speed, rain_particle_t *particle,
rain_particle_t *tmp)
{
    particle->limit = rand() % 1700;
    particle->rect = (sfIntRect){0, 0, 25, 25};
    particle->clock =
    sfClock_getElapsedTime(game->clock->particle).microseconds;
    particle->speed = (sfVector2f){-2 * speed, 4.5 * speed};
    particle->animation = 0;
    if (!game->rain_particle) {
        game->rain_particle = particle;
    } else {
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = particle;
    }
}

int create_rain_particle(game_t *game, bool init)
{
    rain_particle_t *particle = malloc(sizeof(rain_particle_t));
    rain_particle_t *tmp = game->rain_particle;
    int speed = rand() % 2 + 2;

    if (particle == NULL)
        return (84);
    particle->next = NULL;
    particle->pos = (sfVector2f){rand() % (int)(2520
    * game->win.ratio) + game->view.offset.x,
    ((init) ? rand() % 1080 * game->win.ratio : -25) + game->view.offset.y};
    create_rain(game, speed, particle, tmp);
    return (0);
}

void add_rain_particle(game_t *game, int nb, bool init)
{
    int i = 0;

    for (; i < nb; i++)
        create_rain_particle(game, init);
}

void manage_rain(game_t *game, rain_particle_t *tmp)
{
    if (tmp->pos.y < tmp->limit + game->view.offset.y) {
        tmp->pos.x += tmp->speed.x;
        tmp->pos.y += tmp->speed.y;
    } else {
        if (tmp->animation % 3 == 0)
            tmp->rect.left += 25;
        tmp->animation += 1;
    }
    if (tmp->pos.y > 1920 * game->win.ratio + game->view.offset.y
        || tmp->rect.left >= 150) {
        destroy_rain_particle(game, tmp);
        add_rain_particle(game, 1, false);
    }
}

void manage_rain_particle(game_t *game)
{
    rain_particle_t *tmp = game->rain_particle;
    rain_particle_t *backup = NULL;

    while (tmp) {
        backup = tmp->next;
        if (sfClock_getElapsedTime(game->clock->particle).microseconds
            > (30000 + tmp->clock)) {
            tmp->clock =
                sfClock_getElapsedTime(game->clock->particle).microseconds;
            manage_rain(game, tmp);
        }
        tmp = backup;
    }
}
