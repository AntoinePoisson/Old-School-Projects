/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void destroy_spell_projectile(game_t *game, projectile_spell_t *projectile)
{
    projectile_spell_t *tmp = game->projectile_spell;

    sfClock_destroy(projectile->clock_move);
    sfClock_destroy(projectile->clock_particle);
    if (projectile == game->projectile_spell) {
        game->projectile_spell = game->projectile_spell->next;
    } else {
        for (; tmp->next && tmp->next != projectile; tmp = tmp->next);
        if (tmp->next) {
            tmp->next = tmp->next->next;
        }
    }
    free(projectile);
}

void destroy_spell_particle(game_t *game, particle_spell_t *particle)
{
    particle_spell_t *tmp = game->particle_spell;

    if (tmp == particle) {
        game->particle_spell = game->particle_spell->next;
    } else {
        for (; tmp->next != particle; tmp = tmp->next);
        tmp->next = tmp->next->next;
    }
    free(particle);
}

bool manage_spell_particle(game_t *game)
{
    particle_spell_t *tmp = game->particle_spell;
    particle_spell_t *backup = NULL;

    if (sfClock_getElapsedTime(game->clock->spell_particle).microseconds
        < 30000)
        return (false);
    else
        sfClock_restart(game->clock->spell_particle);
    for (; tmp; tmp = backup) {
        backup = tmp->next;
        if (tmp->fade) {
            tmp->fade -= 5;
            tmp->pos.x += (rand() % 3 - 1);
            tmp->pos.y += (rand() % 3 - 1);
        } else {
            destroy_spell_particle(game, tmp);
        }
    }
    return (false);
}

void display_spell_particle(game_t *game)
{
    particle_spell_t *tmp = game->particle_spell;

    for (; tmp; tmp = tmp->next) {
        sfRectangleShape_setPosition(game->particle->spell, tmp->pos);
        sfRectangleShape_setFillColor(game->particle->spell,
        sfColor_fromRGBA(190, 60, 60, tmp->fade));
        sfRenderWindow_drawRectangleShape(game->win.dow,
        game->particle->spell, NULL);
    }
}

void manage_spell_projectile(game_t *game)
{
    projectile_spell_t *tmp = game->projectile_spell;
    projectile_spell_t *backup = NULL;

    for (; tmp; tmp = backup) {
        backup = tmp->next;
        if (sfClock_getElapsedTime(tmp->clock_move).microseconds > 10000) {
            tmp->pos = (sfVector2f){tmp->pos.x + tmp->speed.x,
            tmp->pos.y + tmp->speed.y};
            sfClock_restart(tmp->clock_move);
            tmp->number_move += 1;
        }
        if (sfClock_getElapsedTime(tmp->clock_particle).microseconds > 30000) {
            add_spell_particle(game, tmp->pos);
            add_spell_particle(game, tmp->pos);
            sfClock_restart(tmp->clock_particle);
        }
        if (tmp->number_move >= game->var.spell_range)
            destroy_spell_projectile(game, tmp);
        else
            check_enemy_collision(game, tmp);
    }
}
