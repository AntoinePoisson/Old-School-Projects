/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void add_enemy_evil_tick(game_t *game, sfVector2f pos)
{
    enemy_evil_tick_t *enemy = malloc(sizeof(enemy_evil_tick_t));
    enemy_evil_tick_t *tmp = game->enemy_evil_tick;

    enemy->pos = pos;
    enemy->anim = sfClock_create();
    enemy->attack = sfClock_create();
    enemy->rect = (sfIntRect){0, 0, 20, 20};
    enemy->health = 50;
    enemy->next = NULL;
    if (game->enemy_evil_tick == NULL)
        game->enemy_evil_tick = enemy;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = enemy;
    }
}

void destroy_enemy_evil_tick(game_t *game, enemy_evil_tick_t *enemy)
{
    enemy_evil_tick_t *tmp = game->enemy_evil_tick;

    sfClock_destroy(enemy->anim);
    sfClock_destroy(enemy->attack);
    if (enemy == game->enemy_evil_tick)
        game->enemy_evil_tick = game->enemy_evil_tick->next;
    else {
        for (; tmp->next != enemy; tmp = tmp->next);
        tmp->next = tmp->next->next;
    }
    free(enemy);
}

void manage_single_enemy_evil_tick(game_t *game, enemy_evil_tick_t *tmp)
{
    float angle = 0;

    if (in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player),
    ENEMY_EVIL_TICK_AGRO_RANGE) &&
    !in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player),
    50)) {
        angle = (difference_angle(tmp->pos,
        sfSprite_getPosition(game->sprite->player))) / 180 * PI;
        tmp->pos.x += cos(angle) * ENEMY_EVIL_TICK_SPEED;
        tmp->pos.y += -sin(angle) * ENEMY_EVIL_TICK_SPEED;
    } else if (in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player), 50) &&
    sfClock_getElapsedTime(tmp->attack).microseconds > 1000000) {
        game->player.hp -= rand() % 5 + ENEMY_EVIL_TICK_DAMAGE;
        sfClock_restart(tmp->attack);
    }
}

void manage_enemy_evil_tick(game_t *game)
{
    enemy_evil_tick_t *tmp = game->enemy_evil_tick;
    static int move = 0;
    static int save = 0;

    for (; tmp; tmp = tmp->next) {
        if (sfClock_getElapsedTime(tmp->anim).microseconds > 100000) {
            tmp->rect = game->player.rect[0][ratio_mob_player(game, tmp->pos)];
            tmp->rect = game->player.rect[move][ratio_mob_player(game,
            tmp->pos)];
            save = 2;
            sfClock_restart(tmp->anim);
        }
        manage_single_enemy_evil_tick(game, tmp);
    }
    if (save == 2) {
        if (move == 1)
            move = 0;
        else
            move = 1;
        save = 0;
    }
}

void display_enemy_evil_tick(game_t *game)
{
    enemy_evil_tick_t *tmp = game->enemy_evil_tick;

    for (; tmp; tmp = tmp->next) {
        sfSprite_setPosition(game->sprite->evil_tick, tmp->pos);
        sfSprite_setTextureRect(game->sprite->evil_tick, tmp->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->evil_tick, NULL);
    }
}
