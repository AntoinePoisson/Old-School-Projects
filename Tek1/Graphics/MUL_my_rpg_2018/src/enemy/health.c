/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void check_eye_health(game_t *game, enemy_eye_t *enemy)
{
    if (enemy->health <= 0)
        destroy_enemy_eye(game, enemy);
}

void check_spider_health(game_t *game, enemy_spider_t *enemy)
{
    if (enemy->health <= 0)
        destroy_enemy_spider(game, enemy);
}

void check_evil_tick_health(game_t *game, enemy_evil_tick_t *enemy)
{
    if (enemy->health <= 0)
        destroy_enemy_evil_tick(game, enemy);
}
