/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

int ratio_mob_player(game_t *game, sfVector2f mob)
{
    sfVector2f player = sfSprite_getPosition(game->sprite->player);
    float angle = difference_angle(mob, player);

    if ((angle >= 0 && angle < 30) || (angle <= 360 && angle > 330))
        return (0);
    if (angle >= 30 && angle < 60)
        return (1);
    if (angle >= 60 && angle < 120)
        return (2);
    if (angle >= 120 && angle < 150)
        return (3);
    if (angle >= 150 && angle < 210)
        return (4);
    if (angle >= 210 && angle < 240)
        return (5);
    if (angle >= 240 && angle < 300)
        return (6);
    return (7);
}

void add_enemy_eye(game_t *game, sfVector2f pos)
{
    enemy_eye_t *enemy = malloc(sizeof(enemy_eye_t));
    enemy_eye_t *tmp = game->enemy_eye;
    int y = rand() % 3 * 20;
    int x = (y == 20) ? rand() % 2 * 40 : rand() % 3 * 20;

    enemy->pos = pos;
    enemy->anim = sfClock_create();
    enemy->attack = sfClock_create();
    enemy->rect = (sfIntRect){x, y, 20, 20};
    enemy->rect.left += rand() % 3 * 60;
    enemy->health = 30;
    enemy->next = NULL;
    if (game->enemy_eye == NULL)
        game->enemy_eye = enemy;
    else {
        for (; tmp->next; tmp = tmp->next);
        tmp->next = enemy;
    }
}

void destroy_enemy_eye(game_t *game, enemy_eye_t *enemy)
{
    enemy_eye_t *tmp = game->enemy_eye;

    sfClock_destroy(enemy->anim);
    sfClock_destroy(enemy->attack);
    if (enemy == game->enemy_eye)
        game->enemy_eye = game->enemy_eye->next;
    else {
        for (; tmp->next != enemy; tmp = tmp->next);
        tmp->next = tmp->next->next;
    }
    free(enemy);
}
