/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include "defender.h"

int check_error(int ac, char *av[])
{
    if (ac || av) {
    }
    return (0);
}

void gestion_tranpoline(build_t *save)
{
    if (save->data->status < 0)
        return (management_animation_attack_tranpo(save));
    if (save->data->hp != TRANPOLINE_HP) {
        cooldown_tranpoline(save, 1);
        return (life_restauration_tranpoline(save));
    }
}

int is_ext_management_enemy_move(enemy_t *element)
{
    fix_attack_cancel(element);
    if (element->slow_animation <= ENEMY_SLOW_ANIMATION) {
        element->slow_animation += 1;
        return (1);
    }
    element->slow_animation = 0;
    return (0);
}