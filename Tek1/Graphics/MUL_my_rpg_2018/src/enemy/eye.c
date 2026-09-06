/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void manage_single_enemy_eye(game_t *game, enemy_eye_t *tmp)
{
    float angle = 0;

    if (in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player),
    game->var.enemy_eye_agro_range) &&
    !in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player),
    50)) {
        angle = (difference_angle(tmp->pos,
        sfSprite_getPosition(game->sprite->player))) / 180 * PI;
        tmp->pos.x += cos(angle) * game->var.enemy_eye_speed;
        tmp->pos.y += -sin(angle) * game->var.enemy_eye_speed;
    } else if (in_radius(tmp->pos,
    sfSprite_getPosition(game->sprite->player), 50) &&
    sfClock_getElapsedTime(tmp->attack).microseconds > 1000000) {
        game->player.hp -= rand() % 5 + game->var.enemy_eye_dmg;
        sfClock_restart(tmp->attack);
    }
}

void manage_enemy_eye(game_t *game)
{
    enemy_eye_t *tmp = game->enemy_eye;

    for (; tmp; tmp = tmp->next) {
        if (sfClock_getElapsedTime(tmp->anim).microseconds > 100000) {
            tmp->rect = game->player.rect[0][ratio_mob_player(game, tmp->pos)];
            sfClock_restart(tmp->anim);
        }
        manage_single_enemy_eye(game, tmp);
    }
}

void display_enemy_eye(game_t *game)
{
    enemy_eye_t *tmp = game->enemy_eye;

    for (; tmp; tmp = tmp->next) {
        sfSprite_setPosition(game->sprite->eye, tmp->pos);
        sfSprite_setTextureRect(game->sprite->eye, tmp->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->eye, NULL);
    }
}
