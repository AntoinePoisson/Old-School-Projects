/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_boss.c
*/

#include "my_rpg.h"

void manage_head_first(game_t *game, bool *change_pos,
float *angle, short *times)
{
    if (game->boss.rect.top == 130) {
        *change_pos = true;
        *times += 1;
    } else {
        game->boss.rect.top = 130;
        *angle = 90;
    }
}

void manage_head_two(game_t *game, bool *change_pos,
float *angle, short *times)
{
    if (game->boss.rect.top == 0) {
        *change_pos = false;
        *times += 1;
    } else {
        game->boss.rect.top = 0;
        *angle = 90;
    }
}

void manage_head(game_t *game, bool *change_pos,
float *angle, short *times)
{
    if (*change_pos == false) {
        *angle += 22.5;
        game->boss.rect.left += 125;
        if (game->boss.rect.left >= 500) {
            game->boss.rect.left = 0;
            manage_head_first(game, change_pos, angle, times);
        }
    } else {
        *angle -= 22.5;
        game->boss.rect.left -= 125;
        if (game->boss.rect.left < 0) {
            game->boss.rect.left = 375;
            manage_head_two(game, change_pos, angle, times);
        }
    }
}

void manage_boss_spawn_enemies(game_t *game)
{
    if (game->boss.attack_status == 4) {
        for (short tick = rand() % 3 + 3; tick; tick--)
            add_enemy_evil_tick(game,
            (sfVector2f){8000 + rand() % 400, 2675 + rand() % 300});
        game->boss.attack_status = 3;
    }
    if (game->boss.attack_status == 5) {
        for (short spider = rand() % 2 + 3; spider; spider--)
            add_enemy_spider(game,
            (sfVector2f){8000 + rand() % 400, 2675 + rand() % 300});
        game->boss.attack_status = 3;
    }
    if (game->boss.attack_status == 6) {
        for (short eye = rand() % 2 + 4; eye; eye--)
            add_enemy_eye(game, (sfVector2f)
            {8000 + rand() % 400, 2675 + rand() % 300});
        game->boss.attack_status = 3;
    }
    if (game->boss.attack_status == 42)
        game->boss.rect = (sfIntRect){0, 775, 125, 130};
}

void manage_boss_fireball(game_t *game, bool *change_pos,
float *angle, short *times)
{
    if (game->boss.attack_status == 1 &&
    sfClock_getElapsedTime(game->boss.attack).microseconds >= 5000000) {
        game->boss.attack_status = 2;
        sfClock_restart(game->boss.attack);
    }
    if (game->boss.attack_status == 2 &&
    sfClock_getElapsedTime(game->boss.attack).microseconds >= 300000) {
        add_boss_projectile(game, *angle);
        manage_head(game, change_pos, angle, times);
        if (*times > 10) {
            *times = 0;
            game->boss.attack_status = rand() % 3 + 4;
        }
        sfClock_restart(game->boss.attack);
    }
}
