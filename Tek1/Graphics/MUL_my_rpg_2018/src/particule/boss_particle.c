/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void destroy_boss_projectile(game_t *game, projectile_boss_t *projectile)
{
    projectile_boss_t *tmp = game->projectile_boss;

    sfClock_destroy(projectile->clock_move);
    sfClock_destroy(projectile->clock_particle);
    if (projectile == game->projectile_boss) {
        game->projectile_boss = game->projectile_boss->next;
    } else {
        for (; tmp->next && tmp->next != projectile; tmp = tmp->next);
        if (tmp->next) {
            tmp->next = tmp->next->next;
        }
    }
    free(projectile);
}

void destroy_boss_particle(game_t *game, particle_boss_t *particle)
{
    particle_boss_t *tmp = game->particle_boss;

    if (tmp == particle) {
        game->particle_boss = game->particle_boss->next;
    } else {
        for (; tmp->next != particle; tmp = tmp->next);
        tmp->next = tmp->next->next;
    }
    free(particle);
}

bool manage_boss_particle(game_t *game)
{
    particle_boss_t *tmp = game->particle_boss;
    particle_boss_t *backup = NULL;

    if (sfClock_getElapsedTime(game->clock->boss_particle).microseconds
        < 30000)
        return (false);
    else
        sfClock_restart(game->clock->boss_particle);
    for (; tmp; tmp = backup) {
        backup = tmp->next;
        if (tmp->fade) {
            tmp->fade -= 5;
            tmp->pos.x += (rand() % 3 - 1);
            tmp->pos.y += (rand() % 3 - 1);
        } else {
            destroy_boss_particle(game, tmp);
        }
    }
    return (false);
}

void display_boss_particle(game_t *game)
{
    particle_boss_t *tmp = game->particle_boss;

    for (; tmp; tmp = tmp->next) {
        sfRectangleShape_setPosition(game->particle->boss, tmp->pos);
        sfRectangleShape_setFillColor(game->particle->boss,
        sfColor_fromRGBA(255, 255 - tmp->fade, 0, tmp->fade));
        sfRenderWindow_drawRectangleShape(game->win.dow,
        game->particle->boss, NULL);
    }
}

void manage_boss_projectile(game_t *game)
{
    projectile_boss_t *tmp = game->projectile_boss;
    projectile_boss_t *backup = NULL;

    for (; tmp; tmp = backup) {
        backup = tmp->next;
        if (sfClock_getElapsedTime(tmp->clock_move).microseconds > 10000) {
            tmp->pos = (sfVector2f){tmp->pos.x + tmp->speed.x,
            tmp->pos.y + tmp->speed.y};
            sfClock_restart(tmp->clock_move);
            tmp->number_move += 1;
        }
        if (sfClock_getElapsedTime(tmp->clock_particle).microseconds > 30000) {
            add_boss_particle(game, tmp->pos);
            add_boss_particle(game, tmp->pos);
            sfClock_restart(tmp->clock_particle);
        }
        if (tmp->number_move >= 125)
            destroy_boss_projectile(game, tmp);
        else
            check_player_collision(game, tmp);
    }
}
