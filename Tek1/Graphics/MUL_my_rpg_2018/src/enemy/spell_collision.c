/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

bool check_eye_collision(game_t *game, projectile_spell_t *tmp)
{
    enemy_eye_t *enemy = game->enemy_eye;
    enemy_eye_t *backup = NULL;

    for (; enemy; enemy = backup) {
        backup = enemy->next;
        if (tmp->pos.x > enemy->pos.x + 10 * game->win.ratio &&
        tmp->pos.x < enemy->pos.x + 50 * game->win.ratio &&
        tmp->pos.y > enemy->pos.y + 10 * game->win.ratio &&
        tmp->pos.y < enemy->pos.y + 50 * game->win.ratio) {
            enemy->health -= game->var.spell_dmg;
            check_eye_health(game, enemy);
            destroy_spell_projectile(game, tmp);
            game->player.gold += ENEMY_EYE_EARN;
            game->var.score += rand() % 3 + 1;
            game->player.xp += rand() % 5 + 2;
            game->var.kill += 1;
            return (true);
        }
    }
    return (false);
}

bool check_spider_collision(game_t *game, projectile_spell_t *tmp)
{
    enemy_spider_t *enemy = game->enemy_spider;
    enemy_spider_t *backup = NULL;

    for (; enemy; enemy = backup) {
        backup = enemy->next;
        if (tmp->pos.x > enemy->pos.x + 10 * game->win.ratio &&
        tmp->pos.x < enemy->pos.x + 50 * game->win.ratio &&
        tmp->pos.y > enemy->pos.y + 10 * game->win.ratio &&
        tmp->pos.y < enemy->pos.y + 50 * game->win.ratio) {
            enemy->health -= game->var.spell_dmg;
            check_spider_health(game, enemy);
            destroy_spell_projectile(game, tmp);
            game->player.gold += ENEMY_SPIDER_EARN;
            game->var.score += rand() % 5 + 1;
            game->player.xp += rand() % 6 + 3;
            game->var.kill += 1;
            return (true);
        }
    }
    return (false);
}

bool check_evil_tick_collision(game_t *game, projectile_spell_t *tmp)
{
    enemy_evil_tick_t *enemy = game->enemy_evil_tick;
    enemy_evil_tick_t *backup = NULL;

    for (; enemy; enemy = backup) {
        backup = enemy->next;
        if (tmp->pos.x > enemy->pos.x + 8 * game->win.ratio &&
        tmp->pos.x < enemy->pos.x + 32 * game->win.ratio &&
        tmp->pos.y > enemy->pos.y + 8 * game->win.ratio &&
        tmp->pos.y < enemy->pos.y + 32 * game->win.ratio) {
            enemy->health -= game->var.spell_dmg;
            check_evil_tick_health(game, enemy);
            destroy_spell_projectile(game, tmp);
            game->player.gold += ENEMY_EVIL_TICK_EARN;
            game->var.score += rand() % 8 + 3;
            game->player.xp += rand() % 11 + 3;
            game->var.kill += 1;
            return (true);
        }
    }
    return (false);
}

bool check_boss_collision(game_t *game, projectile_spell_t *tmp)
{
    if (tmp->pos.x >= 8257 && tmp->pos.x <= 8387 &&
    tmp->pos.y >= 2457 && tmp->pos.y <= 2650 &&
    game->boss.attack_status) {
        game->boss.health -= game->var.spell_dmg;
        if (game->boss.health <= 0)
            game->boss.attack_status = 42;
        destroy_spell_projectile(game, tmp);
        return (true);
    }
    return (false);
}

bool check_enemy_collision(game_t *game, projectile_spell_t *tmp)
{
    if (check_eye_collision(game, tmp))
        return (false);
    if (check_spider_collision(game, tmp))
        return (false);
    if (check_evil_tick_collision(game, tmp))
        return (false);
    if (check_boss_collision(game, tmp))
        return (false);
    return (false);
}
