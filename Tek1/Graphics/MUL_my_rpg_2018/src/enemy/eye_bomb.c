/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void add_enemy_eye_bomb(game_t *game, sfVector2f pos)
{
    enemy_eye_bomb_t *enemy = malloc(sizeof(enemy_eye_bomb_t));
    enemy_eye_bomb_t *tmp = game->enemy_eye_bomb;

    enemy->pos = pos;
    enemy->anim = sfClock_create();
    enemy->rect = (sfIntRect){0, 0, 32, 32};
    enemy->next = NULL;
    if (game->enemy_eye_bomb == NULL)
        game->enemy_eye_bomb = enemy;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = enemy;
    }
}

void manage_explosion_eye_bomb(game_t *game, enemy_eye_bomb_t *enemy)
{
    if (enemy->rect.top == 32) {
        for (unsigned short i = rand() % 5 + 2; i; i--) {
            add_enemy_eye(game,
            (sfVector2f){rand() % 60 - 30 + enemy->pos.x,
            rand() % 60 - 30 + enemy->pos.y});
        }
    }
}

void manage_enemy_eye_bomb(game_t *game)
{
    enemy_eye_bomb_t *enemy = game->enemy_eye_bomb;

    for (; enemy; enemy = enemy->next) {
        if (sfClock_getElapsedTime(enemy->anim).microseconds > 400000 &&
        enemy->rect.top == 0 &&
        in_radius(sfSprite_getPosition(game->sprite->player),
        enemy->pos, 300)) {
            enemy->rect.left += 32;
            enemy->rect.top = (enemy->rect.left >= 128) ? 32 : 0;
            enemy->rect.left = (enemy->rect.left >= 128) ? 0 : enemy->rect.left;
            sfClock_restart(enemy->anim);
            manage_explosion_eye_bomb(game, enemy);
        }
    }
}

void display_enemy_eye_bomb(game_t *game)
{
    enemy_eye_bomb_t *enemy = game->enemy_eye_bomb;

    for (; enemy; enemy = enemy->next) {
        sfSprite_setPosition(game->sprite->eye_bomb, enemy->pos);
        sfSprite_setTextureRect(game->sprite->eye_bomb, enemy->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->eye_bomb, NULL);
    }
}
