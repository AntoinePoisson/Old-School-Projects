/*
** EPITECH PROJECT, 2019
** display_hp
** File description:
** display the hp
*/

#include "defender.h"

int find_hp_texture(int hp, int hp_max)
{
    double pourcent = (((hp * 1.0) / (hp_max * 1.0)) * 100.0);

    if (pourcent < 10)
        return (989);
    if (pourcent < 20)
        return (984);
    if (pourcent < 30)
        return (979);
    if (pourcent < 40)
        return (974);
    if (pourcent < 50)
        return (969);
    if (pourcent < 60)
        return (964);
    if (pourcent < 70)
        return (959);
    if (pourcent < 80)
        return (954);
    return (949);
}

int check_hp(int id, int hp)
{
    if (id == 11)
        if (hp < HDV_HP && hp > 0)
            return (HDV_HP);
    if (id == 12)
        if (hp < WALL_HP && hp > 0)
            return (WALL_HP);
    if (id == 13)
        if (hp < CANNON_HP && hp > 0)
            return (CANNON_HP);
    if (id == 14)
        if (hp < BOMBE_HP && hp > 0)
            return (BOMBE_HP);
    if (id == 15)
        if (hp < TRANPOLINE_HP && hp > 0)
            return (TRANPOLINE_HP);
    if (id == 20)
        if (hp < ENEMY_HP && hp > 0)
            return (ENEMY_HP);
    return (-5);
}

void show_hp_build(int id, int hp, data_t *data, variable_t *sf)
{
    sfIntRect rect;
    sfVector2f posi = {0, 0};

    rect.left = 0;
    rect.top = find_hp_texture(hp, check_hp(id, hp));
    rect.width = 46;
    rect.height = 4;
    posi.x = ((data->position.x + (data->rect.width / 2)) - 23);
    posi.y = data->position.y - 10 - data->rect.height / 5;
    sfSprite_setPosition(sf->sprite.resources, posi);
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
}

void show_hp_enemy(int id, int hp, enemy_t *enemy, variable_t *sf)
{
    sfIntRect rect;
    sfVector2f posi = {0, 0};

    rect.left = 0;
    rect.top = find_hp_texture(hp, check_hp(id, hp));
    rect.width = 46;
    rect.height = 5;
    posi.x = ((enemy->posi.x + (enemy->rect.width / 2)) - 23);
    posi.y = enemy->posi.y - 10 - enemy->rect.height / 5;
    sfSprite_setPosition(sf->sprite.resources, posi);
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
}

void display_hp(variable_t *sf)
{
    obj_t *obj = sf->obj;
    enemy_t *enemy = sf->enemy;
    int hp = 0;

    for (int i = 0; obj && i < sf->var_norm.nbr_node_list_obj;
        i++, obj = obj->next) {
        hp = obj->data->hp;
        if (check_hp(obj->id, hp) != -5)
            show_hp_build(obj->id, hp, obj->data, sf);
    }
    for (; enemy; enemy = enemy->next) {
        if (check_hp(20, enemy->hp) != -5)
            show_hp_enemy(20, enemy->hp, enemy, sf);
    }
}
