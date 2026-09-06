/*
** EPITECH PROJECT, 2019
** destroy_donjon.c
** File description:
** destroy_donjon
*/

#include "my_rpg.h"

void destroy_dungeon_music(game_t *game)
{
    game->skill = NULL;
    sfMusic_destroy(game->music->dungeon_theme);
    sfMusic_destroy(game->music->boss_theme);
    sfSoundBuffer_destroy(game->music->sand1_buffer);
    sfSoundBuffer_destroy(game->music->sand2_buffer);
    sfSoundBuffer_destroy(game->music->sand3_buffer);
    sfSoundBuffer_destroy(game->music->spell_buffer);
    sfSoundBuffer_destroy(game->music->flesh_slice_buffer);
    sfSoundBuffer_destroy(game->music->sword_slash_buffer);
    sfSound_destroy(game->music->sand1);
    sfSound_destroy(game->music->sand2);
    sfSound_destroy(game->music->sand3);
    sfSound_destroy(game->music->spell);
    sfSound_destroy(game->music->flesh_slice);
    sfSound_destroy(game->music->sword_slash);
}

void destroy_donjon(game_t *game)
{
    game->var.quit_donjon = 1;
    sfSprite_destroy(game->sprite->donjon);
    sfTexture_destroy(game->texture->donjon);
    sfSprite_destroy(game->sprite->donjon_shader);
    sfTexture_destroy(game->texture->donjon_shader);
    sfSprite_destroy(game->sprite->donjon_torch);
    sfTexture_destroy(game->texture->donjon_torch);
    sfSprite_destroy(game->sprite->item);
    sfTexture_destroy(game->texture->item);
    sfSprite_destroy(game->sprite->donjon_wall);
    sfTexture_destroy(game->texture->donjon_wall);
    sfSprite_destroy(game->sprite->skill);
    sfTexture_destroy(game->texture->skill);
    sfClock_destroy(game->player.clock_time_score);
    sfClock_destroy(game->clock->donjon_torch);
    destroy_dungeon_music(game);
    destroy_hud(game);
}
