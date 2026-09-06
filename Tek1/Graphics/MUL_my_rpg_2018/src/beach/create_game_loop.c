/*
** EPITECH PROJECT, 2019
** create_game_loop.c
** File description:
** Creations of the game loop
*/

#include "my_rpg.h"

void create_game_loop_bis(game_t *game)
{
    game->var.level = 0;
    game->view.view = sfView_createFromRect
    ((sfFloatRect){0, 0, 1920 * game->win.ratio, 1080 * game->win.ratio});
    game->view.offset =
    (sfVector2f){200 * game->win.ratio, 700 * game->win.ratio};
    sfView_move(game->view.view, game->view.offset);
    game->sprite->beach_intro = sfSprite_create();
    game->sprite->beach_intro2 = sfSprite_create();
    game->texture->beach_intro =
    sfTexture_createFromFile("assets/img/map/beach_intro.png", NULL);
    game->texture->beach_intro2 =
    sfTexture_createFromFile("assets/img/map/beach_intro2.png", NULL);
    sfSprite_setTexture(game->sprite->beach_intro2,
    game->texture->beach_intro2, sfTrue);
}

void create_game_loop_third(game_t *game)
{
    sfSprite_setTexture(game->sprite->beach_intro,
    game->texture->beach_intro, sfTrue);
    game->projectile_spell = NULL;
    game->particle_spell = NULL;
    game->var.disp_dial = false;
    sfSprite_setScale(game->sprite->beach_intro2,
    (sfVector2f){1.4 * game->win.ratio, 1.4 * game->win.ratio});
    sfSprite_setScale(game->sprite->beach_intro,
    (sfVector2f){1.4 * game->win.ratio, 1.4 * game->win.ratio});
    game->sprite->rain = sfSprite_create();
    game->texture->rain =
    sfTexture_createFromFile("assets/img/particule/rain.png", NULL);
    game->clock->spell_particle = sfClock_create();
    game->clock->footsteps_sound = sfClock_create();
    game->clock->spell_sound = sfClock_create();
    game->clock->regeneration = sfClock_create();
    game->clock->trap = sfClock_create();
}

void create_beach_sound(game_t *game)
{
    game->music->sand1_buffer =
    sfSoundBuffer_createFromFile("assets/sound/sand1.wav");
    game->music->sand1 = sfSound_create();
    sfSound_setBuffer(game->music->sand1, game->music->sand1_buffer);
    game->music->sand2_buffer =
    sfSoundBuffer_createFromFile("assets/sound/sand2.wav");
    game->music->sand2 = sfSound_create();
    sfSound_setBuffer(game->music->sand2, game->music->sand2_buffer);
    game->music->sand3_buffer =
    sfSoundBuffer_createFromFile("assets/sound/sand3.wav");
    game->music->sand3 = sfSound_create();
    sfSound_setBuffer(game->music->sand3, game->music->sand3_buffer);
    game->music->spell_buffer =
    sfSoundBuffer_createFromFile("assets/sound/spell.wav");
    game->music->spell = sfSound_create();
    sfSound_setBuffer(game->music->spell, game->music->spell_buffer);
}

void create_game_loop(game_t *game)
{
    create_player(game);
    create_dialog_hud(game);
    game->music->rain = sfMusic_createFromFile("assets/sound/rain_sfx.ogg");
    if (!game->var.disp_music) {
        sfMusic_play(game->music->rain);
        sfMusic_setLoop(game->music->rain, sfTrue);
    }
    create_game_loop_bis(game);
    create_game_loop_third(game);
    create_inventory(game);
    create_pause(game);
    create_stats(game);
    sfSprite_setTexture(game->sprite->rain, game->texture->rain, sfTrue);
    sfSprite_setScale(game->sprite->rain,
    (sfVector2f){RAIN_SIZE * game->win.ratio, RAIN_SIZE * game->win.ratio});
    sfClock_restart(game->clock->particle);
    game->rain_particle = NULL;
    add_rain_particle(game, RAIN_PARTICLE_NUMBER, true);
    create_beach_sound(game);
}
