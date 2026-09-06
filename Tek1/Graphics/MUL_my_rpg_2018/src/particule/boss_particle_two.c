/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void check_player_collision(game_t *game, projectile_boss_t *projectile)
{
    sfVector2f ply = sfSprite_getPosition(game->sprite->player);

    if (projectile->pos.x > ply.x - 10 && projectile->pos.x < ply.x + 10 &&
    projectile->pos.y > ply.y - 20 && projectile->pos.y < ply.y + 20) {
        destroy_boss_projectile(game, projectile);
        game->player.hp -= 17;
    }
}

void add_projectile_boss(game_t *game, float angle,
projectile_boss_t *projectile)
{
    projectile->pos = (sfVector2f){8300 * game->win.ratio,
    2590 * game->win.ratio};
    projectile->speed = (sfVector2f){cos(angle) * 5,
    sin(angle) * 5};
    projectile->number_move = 0;
    projectile->clock_move = sfClock_create();
    projectile->clock_particle = sfClock_create();
    projectile->next = NULL;
}

void add_boss_projectile(game_t *game, float angle)
{
    projectile_boss_t *projectile = malloc(sizeof(projectile_boss_t));
    projectile_boss_t *tmp = game->projectile_boss;

    angle *= PI / 180;
    add_projectile_boss(game, angle, projectile);
    if (game->projectile_boss == NULL)
        game->projectile_boss = projectile;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = projectile;
    }
}

void add_boss_particle(game_t *game, sfVector2f pos)
{
    particle_boss_t *particle = malloc(sizeof(particle_boss_t));
    particle_boss_t *tmp = game->particle_boss;

    particle->pos = pos;
    particle->fade = 255;
    particle->next = NULL;
    if (game->particle_boss == NULL)
        game->particle_boss = particle;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = particle;
    }
}
