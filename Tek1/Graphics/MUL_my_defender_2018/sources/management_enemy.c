/*
** EPITECH PROJECT, 2018
** management_enemy
** File description:
** management_enemy
*/

#include <math.h>
#include <stdlib.h>
#include "defender.h"

int attack_element(variable_t *sf, int posi, enemy_t *enemy)
{
    build_t *save = sf->build;
    int i = 0;

    for (; save && i < posi; i++, save = save->next);
    if (save->id == 14 || save->id == 15)
        return (1);
    if (save && save->data->hp <= 0)
        return (dead_build(save));
    if (save != NULL && (enemy->status + take_limit_enemy_attack(enemy)
        * ENEMY_SLOW_ANIMATION) >= ENEMY_SPEED_DMG)
        management_enemy_attack(enemy);
    if (save != NULL && enemy->status == ENEMY_SPEED_DMG) {
        save->data->hp -= ENEMY_DMG;
        if (sfMusic_getStatus(sf->music.attak) != sfPlaying)
            sfMusic_play(sf->music.attak);
        enemy->status = 1;
        fix_attack_cancel(enemy);
    } else
        enemy->status += 1;
    return (0);
}

int don_t_move_special_case(variable_t *sf, sfVector2i convertion)
{
    build_t *save = sf->build;
    int posi = 0;

    if (control_hitbox_place_build(sf, convertion) == 0)
        return (1);
    if ((posi = control_hitbox_place_build(sf, convertion)) != 0) {
        posi--;
        for (int i = 0; save && i < posi; i++, save = save->next);
        if (save->data->hp <= 0 || save->id == 14 || save->id == 15)
            return (1);
    }
    return (0);
}

void management_enemy_2(variable_t *sf, enemy_t *save,
    sfVector2i convertion, int posi)
{
    if ((save->hp <= 0) ||
        ((posi = control_hitbox_place_build(sf, convertion)) != 0
        && attack_element(sf, posi - 1, save) == 0)) {
    }
    else if (don_t_move_special_case(sf, convertion)) {
        save->posi = move_enemy(sf, save);
        management_enemy_move(save);
    }
}

void management_enemy(variable_t *sf)
{
    enemy_t *save = sf->enemy;
    sfVector2i convertion;

    for (int posi = 0; save; save = save->next) {
        convertion.x = save->posi.x + 38;
        convertion.y = save->posi.y + 39;
        if (save->hp <= 0 && save->status != 0) {
            save->rect.top = 309;
            save->rect.left = 0;
            save->rect.width = 33;
            save->rect.height = 47;
            save->status = 0;
            sf->var_norm.kill += 1;
            sf->var_norm.money += ENEMY_GOLD;
        }
        management_enemy_2(sf, save, convertion, posi);
    }
}

void display_enemy(variable_t *sf, int cas)
{
    enemy_t *save = sf->enemy;

    for (; save; save = save->next) {
        if (cas == 0 && save->hp <= 0) {
            sfSprite_setPosition(sf->sprite.resources, save->posi);
            sfSprite_setTextureRect(sf->sprite.resources, save->rect);
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
        }
        if (cas == 1 && save->hp > 0) {
            sfSprite_setPosition(sf->sprite.resources, save->posi);
            sfSprite_setTextureRect(sf->sprite.resources, save->rect);
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
        }
    }
}
