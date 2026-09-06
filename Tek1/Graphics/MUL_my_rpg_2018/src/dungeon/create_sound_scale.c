/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create sound and scale
*/

#include "my_rpg.h"

void create_donjon_things(game_t *game)
{
    sfSprite_setScale(game->sprite->eye,
    (sfVector2f){3 * game->win.ratio, 3 * game->win.ratio});
    sfSprite_setScale(game->sprite->eye_bomb,
    (sfVector2f){3 * game->win.ratio, 3 * game->win.ratio});
    sfSprite_setScale(game->sprite->spider,
    (sfVector2f){2.5 * game->win.ratio, 2.5 * game->win.ratio});
    sfSprite_setScale(game->sprite->evil_tick,
    (sfVector2f){2 * game->win.ratio, 2 * game->win.ratio});
}

void create_donjon_other_things(game_t *game)
{
    sfColor alpha;

    alpha.a = 80;
    sfSprite_setScale(game->sprite->donjon,
    (sfVector2f){4.2 * game->win.ratio, 4.2 * game->win.ratio});
    sfSprite_setScale(game->sprite->donjon_shader,
    (sfVector2f){4.2 * game->win.ratio, 4.2 * game->win.ratio});
    sfSprite_setScale(game->sprite->donjon_torch,
    (sfVector2f){4.2 * game->win.ratio, 4.2 * game->win.ratio});
    sfSprite_setScale(game->sprite->donjon_wall,
    (sfVector2f){4.2 * game->win.ratio, 4.2 * game->win.ratio});
    sfSprite_setScale(game->sprite->item,
    (sfVector2f){3.2 * game->win.ratio, 3.2 * game->win.ratio});
    sfSprite_setScale(game->sprite->player,
    (sfVector2f){3.75 * game->win.ratio, 3.75 * game->win.ratio});
    sfSprite_setColor(game->sprite->donjon_shader, alpha);
    create_donjon_things(game);
}

void create_dungeon_sound(game_t *game)
{
    game->music->dungeon_theme =
    sfMusic_createFromFile("assets/sound/dungeon_theme.ogg");
    game->music->boss_theme =
    sfMusic_createFromFile("assets/sound/boss_theme.ogg");
    game->music->flesh_slice_buffer =
    sfSoundBuffer_createFromFile("assets/sound/sword_flesh.ogg");
    game->music->flesh_slice = sfSound_create();
    sfSound_setBuffer(game->music->flesh_slice,
    game->music->flesh_slice_buffer);
    game->music->sword_slash_buffer =
    sfSoundBuffer_createFromFile("assets/sound/sword_slash.ogg");
    game->music->sword_slash = sfSound_create();
    sfSound_setBuffer(game->music->sword_slash,
    game->music->sword_slash_buffer);
}
