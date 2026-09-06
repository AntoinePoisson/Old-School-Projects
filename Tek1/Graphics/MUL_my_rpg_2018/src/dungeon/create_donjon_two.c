/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void create_donjon_two(game_t *game)
{
    if (!game->var.disp_music) {
        sfMusic_play(game->music->dungeon_theme);
        sfMusic_setPlayingOffset(game->music->dungeon_theme, sfSeconds(1.5));
        sfMusic_setLoop(game->music->dungeon_theme, sfTrue);
        sfMusic_setLoop(game->music->boss_theme, sfTrue);
    }
    game->particle->boss = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->particle->boss,
    sfColor_fromRGBA(255, 0, 0, 255));
    sfRectangleShape_setSize(game->particle->boss,
    (sfVector2f){8 * game->win.ratio, 8 * game->win.ratio});
    game->clock->boss_particle = sfClock_create();
    game->projectile_boss = NULL;
    game->particle_boss = NULL;
}
