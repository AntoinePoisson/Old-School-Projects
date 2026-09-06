/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void event_spell(game_t *game)
{
    if (game->win.event.type == sfEvtMouseButtonPressed &&
        game->win.event.mouseButton.button == sfMouseRight &&
        game->press.rightclick == false &&
        game->player.mana >= SPELL_MANA_COST) {
        add_spell_projectile(game);
        game->player.mana -= SPELL_MANA_COST;
        if (sfClock_getElapsedTime(game->clock->spell_sound).microseconds
            > 1000000 && !game->var.disp_music) {
            sfSound_play(game->music->spell);
            sfClock_restart(game->clock->spell_sound);
        }
        game->press.rightclick = true;
    }
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseRight &&
        game->press.rightclick == true) {
        game->press.rightclick = false;
    }
}

void add_projectile(game_t *game, float angle, projectile_spell_t *projectile)
{
    projectile->pos = (sfVector2f){sfSprite_getPosition
    (game->sprite->player).x * game->win.ratio,
    sfSprite_getPosition(game->sprite->player).y + 20 * game->win.ratio};
    projectile->speed = (sfVector2f){cos(angle) * game->var.spell_speed,
    sin(angle) * game->var.spell_speed};
    projectile->number_move = 0;
    projectile->clock_move = sfClock_create();
    projectile->clock_particle = sfClock_create();
    projectile->next = NULL;
}

void add_spell_projectile(game_t *game)
{
    projectile_spell_t *projectile = malloc(sizeof(projectile_spell_t));
    projectile_spell_t *tmp = game->projectile_spell;
    sfVector2f player = {(sfSprite_getPosition(game->sprite->player).x -
    game->view.offset.x) * game->win.ratio, (sfSprite_getPosition
    (game->sprite->player).y - game->view.offset.y) * game->win.ratio};
    sfVector2f mouse = {sfSprite_getPosition(game->sprite->cursor).x
    * game->win.ratio,
    sfSprite_getPosition(game->sprite->cursor).y * game->win.ratio};
    float angle = (360 - difference_angle(player, mouse)) / 180 * PI;

    add_projectile(game, angle, projectile);
    if (game->projectile_spell == NULL)
        game->projectile_spell = projectile;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = projectile;
    }
}

void add_spell_particle(game_t *game, sfVector2f pos)
{
    particle_spell_t *particle = malloc(sizeof(particle_spell_t));
    particle_spell_t *tmp = game->particle_spell;

    particle->pos = pos;
    particle->fade = 255;
    particle->next = NULL;
    if (game->particle_spell == NULL)
        game->particle_spell = particle;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = particle;
    }
}
