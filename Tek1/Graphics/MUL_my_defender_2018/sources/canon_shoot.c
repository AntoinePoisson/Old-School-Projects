/*
** EPITECH PROJECT, 2019
** canon_shoot
** File description:
** where the canon is moving
*/

#include <math.h>
#include "defender.h"

void cannon_enemy_target(build_t *build, sfVector2f pos_canon,
    sfVector2f pos_enemy)
{
    int count = 0;
    int negative = 0;
    float angle =
        calcul_angle(pos_canon.x, pos_canon.y, pos_enemy.x, pos_enemy.y);

    if (angle > 180) {
        angle = angle - 180;
        negative = 1;
    }
    else
        angle = 180 - angle;
    calcul_angle(pos_canon.x, pos_canon.y, pos_enemy.x, pos_enemy.y);
    for (; (10.56 * (count + 1)) < angle; count++) {
    }
    build->data->rect.top = 1187 - 79 * negative;
    build->data->rect.left = count * 80;
}

int check_touch(variable_t *sf, enemy_t *temp2, build_t *temp,
    sfVector2f pos_canon)
{
    sfVector2f pos_enemy = temp2->posi;

    if (temp2->hp > 0 && temp->data->hp > 0 &&
        temp->data->status == CANNON_SPEED_DMG) {
        temp2->hp -= CANNON_DMG;
        temp->data->status = 1;
        cannon_enemy_target(temp, pos_canon, pos_enemy);
        if (sfMusic_getStatus(sf->music.canon) != sfPlaying)
            sfMusic_play(sf->music.canon);
        return (1);
    }
    else if (temp2->hp > 0 && temp->data->hp > 0)
        temp->data->status += 1;
    return (0);
}

void check_touch_enemy(variable_t *sf, build_t *temp, sfVector2f pos_canon,
    sfVector2f pos_enemy)
{
    for (enemy_t *temp2 = sf->enemy; temp2; temp2 = temp2->next) {
        pos_enemy = temp2->posi;
        if (sqrt(pow(pos_enemy.x - pos_canon.x, 2)
            + pow(pos_enemy.y - pos_canon.y, 2)) < CANNON_RANG &&
            check_touch(sf, temp2, temp, pos_canon) == 1)
            return;
    }
}

void find_shoot(variable_t *sf)
{
    sfVector2f pos_canon;
    sfVector2f pos_enemy;

    for (build_t *temp = sf->build; temp; temp = temp->next) {
        if (temp->id == 13) {
            pos_canon = temp->data->position;
            check_touch_enemy(sf, temp, pos_canon, pos_enemy);
        }
    }
}
