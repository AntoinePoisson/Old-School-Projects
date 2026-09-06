/*
** EPITECH PROJECT, 2019
** management_bombe
** File description:
** management bombe
*/

#include <math.h>
#include "defender.h"

void life_restauration_bombe(build_t *save)
{
    int result = (BOMBE_HP - save->data->hp);
    int add = 0;

    add = (result / (BOMBE_SPEED_DMG - (save->data->status - 1)));
    save->data->status += 1;
    save->data->hp += add;
    if (BOMBE_SPEED_DMG - (save->data->status - 1) <= 0) {
        save->data->hp = BOMBE_HP;
        save->data->status = 1;
    }
}

void management_animation_attack_bombe(build_t *save)
{
    if (save->data->status < 0) {
        if (save->data->status >= BOMBE_SPEED_ANIMATION_ATTACK * -1) {
            save->data->rect.left += save->data->rect.width;
            save->data->status = -1;
        }
        else
            save->data->status -= 1;
    }
    if (save->data->rect.left >= save->data->rect.width * 7) {
        save->data->hp = 1;
        save->data->status = 1;
        save->data->rect.left = 0;
    }
}

void gestion_bombe(build_t *save)
{
    if (save->data->status < 0)
        return (management_animation_attack_bombe(save));
    if (save->data->hp != BOMBE_HP) {
        life_restauration_bombe(save);
        return;
    }
}

void management_bombe(variable_t *sf, build_t *save)
{
    sfVector2f pos_tranp = save->data->position;
    sfVector2f pos_enemy;

    if (save->data->status < 0 || save->data->hp != BOMBE_HP)
        return (gestion_bombe(save));
    for (enemy_t *temp2 = sf->enemy; temp2; temp2 = temp2->next) {
        pos_enemy = temp2->posi;
        if ((sqrt(pow(pos_enemy.x - pos_tranp.x, 2)
            + pow(pos_enemy.y - pos_tranp.y, 2)) < TRANP_RANG) &&
            temp2->hp > 0) {
            is_extension_management_bombe(sf, 1);
            temp2->hp -= BOMBE_DMG;
            save->data->hp = 1;
            save->data->status = -1;
        }
    }
}
