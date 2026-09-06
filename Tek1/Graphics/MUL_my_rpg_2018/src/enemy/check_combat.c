/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check combat
*/

#include "my_rpg.h"

bool check_combat_eye(game_t *game, sfVector2f player_pos)
{
    enemy_eye_t *eye = game->enemy_eye;

    for (; eye; eye = eye->next) {
        if (in_radius(eye->pos, player_pos, 130)) {
            eye->health -= CLOSE_COMBAT_DAMAGE;
            check_eye_health(game, eye);
            play_sword_sound(game, true);
            return (true);
        }
    }
    return (false);
}

bool check_combat_spider(game_t *game, sfVector2f player_pos)
{
    enemy_spider_t *spider = game->enemy_spider;

    for (; spider; spider = spider->next) {
        if (in_radius(spider->pos, player_pos, 130)) {
            spider->health -= CLOSE_COMBAT_DAMAGE;
            check_spider_health(game, spider);
            play_sword_sound(game, true);
            return (true);
        }
    }
    return (false);
}

bool check_combat_evil_tick(game_t *game, sfVector2f player_pos)
{
    enemy_evil_tick_t *evil_tick = game->enemy_evil_tick;

    for (; evil_tick; evil_tick = evil_tick->next) {
        if (in_radius(evil_tick->pos, player_pos, 130)) {
            evil_tick->health -= CLOSE_COMBAT_DAMAGE;
            check_evil_tick_health(game, evil_tick);
            play_sword_sound(game, true);
            return (true);
        }
    }
    return (false);
}

bool check_combat_boss(game_t *game, sfVector2f player_pos)
{
    if (player_pos.x >= 8120 && player_pos.x <= 8510 &&
        player_pos.y >= 2457 && player_pos.y <= 2780 &&
        game->boss.attack_status) {
        game->boss.health -= CLOSE_COMBAT_DAMAGE;
        if (game->boss.health <= 0)
            game->boss.attack_status = 42;
        play_sword_sound(game, true);
        return (true);
    }
    return (false);
}
