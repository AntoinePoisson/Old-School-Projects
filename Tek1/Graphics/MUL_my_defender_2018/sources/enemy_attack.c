/*
** EPITECH PROJECT, 2019
** enemy attack
** File description:
** enemy attack
*/

#include "defender.h"

void management_enemy_move(enemy_t *element)
{
    int start = 0;

    if (is_ext_management_enemy_move(element) == 1)
        return;
    if (element->rect.left <= 750) {
        if (take_position_enemy_sprite_one(element->rect.top) <=
            element->rect.left + 71)
            element->rect.left = 0;
        else
            element->rect.left += 71;
        return;
    }
    if (take_position_enemy_sprite_two(&start, element->rect.top)
        <= element->rect.left + 71)
        element->rect.left = start;
    else
        element->rect.left += 71;
}

int is_extension_take_limit_enemy_attack(enemy_t *element)
{
    if (element->rect.top == 1772 && element->rect.left < 700)
        return (4);
    if (element->rect.top == 1843 && element->rect.left < 700)
        return (6);
    if (element->rect.top == 1914 && element->rect.left < 700)
        return (4);
    if (element->rect.top == 1985 && element->rect.left < 700)
        return (5);
    if (element->rect.top == 2056 && element->rect.left < 700)
        return (5);
    if (element->rect.top == 1843 && element->rect.left > 700)
        return (6);
    if (element->rect.top == 1914 && element->rect.left > 700)
        return (4);
    if (element->rect.top == 1985 && element->rect.left > 700)
        return (5);
    return (4);
}

int take_limit_enemy_attack(enemy_t *element)
{
    if (element->rect.top == 1417 && element->rect.left < 700)
        return (4);
    if (element->rect.top == 1488 && element->rect.left < 700)
        return (6);
    if (element->rect.top == 1559 && element->rect.left < 700)
        return (4);
    if (element->rect.top == 1630 && element->rect.left < 700)
        return (5);
    if (element->rect.top == 1701 && element->rect.left < 700)
        return (5);
    if (element->rect.top == 1488 && element->rect.left > 700)
        return (6);
    if (element->rect.top == 1559 && element->rect.left > 700)
        return (4);
    if (element->rect.top == 1630 && element->rect.left > 700)
        return (5);
    return (is_extension_take_limit_enemy_attack(element));
}

int dmg_po(int posi, int x)
{
    if (x < 750)
        return (0);
    if (posi == 1488)
        return (1062);
    if (posi == 1559)
        return (1204);
    if (posi == 1630)
        return (1133);
    return (1204);
}

void fix_attack_cancel(enemy_t *element)
{
    int start = 0;

    if (element->rect.top > 1746) {
        element->rect.top -= 355;
        if (element->rect.left < 750)
            element->rect.left = 0;
        else {
            take_position_enemy_sprite_two(&start, element->rect.top);
            element->rect.left = start;
        }
    }
}
