/*
** EPITECH PROJECT, 2018
** management_trap.c
** File description:
** management bombe and trap
*/

#include <math.h>
#include "defender.h"

void life_restauration_tranpoline(build_t *save)
{
    int result = (TRANPOLINE_HP - save->data->hp);
    int add = 0;

    add = (result / (TRANPOLINE_SPEED_DMG - (save->data->status - 1)));
    save->data->status += 1;
    save->data->hp += add;
    if (TRANPOLINE_SPEED_DMG - (save->data->status - 1) <= 0) {
        save->data->hp = TRANPOLINE_HP;
        save->data->status = 1;
        save->data->rect.left = 0;
    }
}

void cooldown_tranpoline(build_t *save, int cas)
{
    float hp = ((save->data->hp * 1.0) / (TRANPOLINE_HP * 1.0)) * 100.0;

    if (cas == 0) {
        save->data->level = 0;
        return;
    }
    if (hp > save->data->level + 20 &&
        save->data->rect.left - save->data->rect.width >= 0) {
        save->data->level = save->data->hp;
        save->data->rect.left += save->data->rect.width;
    }
}

void management_animation_attack_tranpo(build_t *save)
{
    if (save->data->status < 0) {
        if (save->data->status >= TRANP_SPEED_ANIMATION_ATTACK * -1) {
            save->data->rect.left += save->data->rect.width;
            save->data->status = -1;
        }
        else
            save->data->status -= 1;
    }
    if (save->data->rect.left >= save->data->rect.width * 5) {
        save->data->hp = 1;
        save->data->status = 1;
    }
}

void management_tranpoline(variable_t *sf, build_t *save)
{
    sfVector2f pos_tranp = save->data->position;
    sfVector2f pos_enemy;

    if (save->data->status < 0 || save->data->hp != TRANPOLINE_HP)
        return (gestion_tranpoline(save));
    for (enemy_t *temp2 = sf->enemy; temp2; temp2 = temp2->next) {
        pos_enemy = temp2->posi;
        if (sqrt(pow(pos_enemy.x - pos_tranp.x, 2)
            + pow(pos_enemy.y - pos_tranp.y, 2)) < TRANP_RANG &&
            temp2->hp > 0) {
            temp2->hp -= TRANPOLINE_DMG;
            save->data->status = -1;
            is_extension_management_bombe(sf, 2);
            return (cooldown_tranpoline(save, 0));
        }
    }
}

void management_trap(variable_t *sf)
{
    build_t *save = sf->build;

    for (int i = 0; save && i < sf->var_norm.nbr_node_list_build;
        i++, save = save->next) {
        if (save->id == 14)
            management_bombe(sf, save);
        if (save->id == 15)
            management_tranpoline(sf, save);
    }
}
