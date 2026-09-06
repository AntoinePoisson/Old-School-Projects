/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void add_enemy_spider(game_t *game, sfVector2f pos)
{
    enemy_spider_t *enemy = malloc(sizeof(enemy_spider_t));
    enemy_spider_t *tmp = game->enemy_spider;

    enemy->pos = pos;
    enemy->anim = sfClock_create();
    enemy->attack = sfClock_create();
    enemy->rect = (sfIntRect){0, 100, 33, 33};
    enemy->health = 50;
    enemy->next = NULL;
    if (game->enemy_spider == NULL)
        game->enemy_spider = enemy;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = enemy;
    }
}

void destroy_enemy_spider(game_t *game, enemy_spider_t *enemy)
{
    enemy_spider_t *tmp = game->enemy_spider;

    sfClock_destroy(enemy->anim);
    sfClock_destroy(enemy->attack);
    if (enemy == game->enemy_spider)
        game->enemy_spider = game->enemy_spider->next;
    else {
        for (; tmp->next != enemy; tmp = tmp->next);
        tmp->next = tmp->next->next;
    }
    free(enemy);
}

void manage_single_enemy_spider(game_t *game, enemy_spider_t *tmp)
{
    float angle = 0;

    if (in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player),
    ENEMY_SPIDER_AGRO_RANGE) &&
    !in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player),
    50)) {
        angle = (difference_angle(tmp->pos,
        sfSprite_getPosition(game->sprite->player))) / 180 * PI;
        tmp->pos.x += cos(angle) * ENEMY_SPIDER_SPEED;
        tmp->pos.y += -sin(angle) * ENEMY_SPIDER_SPEED;
    } else if (in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player), 50) &&
    sfClock_getElapsedTime(tmp->attack).microseconds > 1000000) {
        game->player.hp -= rand() % 5 + ENEMY_SPIDER_DAMAGE;
        sfClock_restart(tmp->attack);
    }
}

void manage_enemy_spider(game_t *game)
{
    enemy_spider_t *tmp = game->enemy_spider;
    static int move = 0;
    static int save = 0;

    for (; tmp; tmp = tmp->next) {
        if (sfClock_getElapsedTime(tmp->anim).microseconds > 100000) {
            tmp->rect = game->player.rect[move][ratio_mob_player(game,
            tmp->pos)];
            sfClock_restart(tmp->anim);
            save = 2;
        }
        manage_single_enemy_spider(game, tmp);
    }
    if (save == 2) {
        if (move == 1)
            move = 0;
        else
            move = 1;
        save = 0;
    }
}

void display_enemy_spider(game_t *game)
{
    enemy_spider_t *tmp = game->enemy_spider;

    for (; tmp; tmp = tmp->next) {
        sfSprite_setPosition(game->sprite->spider, tmp->pos);
        sfSprite_setTextureRect(game->sprite->spider, tmp->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->spider, NULL);
    }
}
