/*
** EPITECH PROJECT, 2019
** enemy_create
** File description:
** enemy creta
*/

#include <math.h>
#include <stdlib.h>
#include "defender.h"

void management_enemy_attack_2(enemy_t *element, int start)
{
    if ((dmg_po(element->rect.left, element->rect.left) +
        take_limit_enemy_attack(element) * 71 <= element->rect.left)
        || (element->status + 1 == ENEMY_SPEED_DMG)) {
        element->rect.top -= 355;
        if (element->rect.left < 750)
            element->rect.left = 0;
        else {
            take_position_enemy_sprite_two(&start, element->rect.top);
            element->rect.left = start;
        }
    }
}

void management_enemy_attack(enemy_t *element)
{
    int start = 0;

    if (element->slow_animation <= ENEMY_SLOW_ANIMATION_ATTACK) {
        element->slow_animation += 1;
        return;
    }
    element->slow_animation = 0;
    if (element->rect.top < 1746) {
        element->rect.top += 355;
        if (element->rect.left < 750)
            element->rect.left = 0;
        else
            element->rect.left = dmg_po(element->rect.top, element->rect.left);
    }
    else
        element->rect.left += 71;
    management_enemy_attack_2(element, start);
}

void is_create_enemy(variable_t *sf)
{
    enemy_t *element = NULL;
    int count = 0;

    srand((((sf->time.game.microseconds / 100000.0) * 100) / 1));
    sf->var_norm.nbr_enemy = ENEMY_NBR + (ENEMY_NBR * sf->var_norm.level) / 2;
    for (int i = 0; count < sf->var_norm.nbr_enemy; i++, count++) {
        if (i == 5)
            i = 0;
        element = malloc(sizeof(enemy_t));
        element->status = 1;
        element->hp = ENEMY_HP;
        element->damage = ENEMY_DMG;
        element->move_speed = ENEMY_SPEED;
        element->slow_animation = 0;
        element->posi = management_spawn_enemy(i);
        is_direction_enemy(sf, element);
        find_coef(sf, &(element));
        element->next = sf->enemy;
        sf->enemy = element;
    }
}

sfVector2f move_enemy(variable_t *sf, enemy_t *save)
{
    sfVector2f element = save->posi;

    if (sf->vector.hdv.x > element.x)
        element.x += save->move_speed;
    else
        element.x -= save->move_speed;
    element.y = ((save->coef_x * element.x) + save->coef_y);
    return (element);
}

int dead_build(build_t *save)
{
    if (save->id == 11) {
        save->data->rect.top = 9;
        save->data->rect.left = 151;
        save->data->rect.width = 142;
        save->data->rect.height = 117;
    }
    if (save->id == 12) {
        save->data->rect.top = 198;
        save->data->rect.left = 82;
        save->data->rect.width = 30;
        save->data->rect.height = 33;
    }
    if (save->id == 13) {
        save->data->rect.top = 244;
        save->data->rect.left = 0;
        save->data->rect.width = 72;
        save->data->rect.height = 56;
    }
    return (1);
}
