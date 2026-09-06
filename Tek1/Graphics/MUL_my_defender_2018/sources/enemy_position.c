/*
** EPITECH PROJECT, 2019
** enemy position
** File description:
** enemy position
*/

#include <math.h>
#include "defender.h"

float calcul_angle(int hdv_x, int hdv_y, int x, int y)
{
    float result = atan2((y - hdv_y), (x - hdv_x)) * 180.0 / PI;

    if (result < 0)
        result = 360 - (result * -1);
    result -= 360;
    result *= -1;
    return (result);
}

int find_right_angle(float result)
{
    if ((result <= 15 && result >= 0) || (result <= 360 && result >= 345))
        return (1559);
    if (result < 75 && result > 15)
        return (1630);
    if (result <= 105 && result >= 75)
        return (1701);
    if (result < 175 && result > 105)
        return (1630);
    if (result <= 205 && result >= 175)
        return (1559);
    if (result < 255 && result > 205)
        return (1488);
    if (result <= 285 && result >= 255)
        return (1417);
    if (result < 345 && result > 285)
        return (1488);
    return (1417);
}

int take_position_enemy_sprite_two(int *start, int posi)
{
    if (posi == 1488) {
        *start = 1133;
        return (1487);
    }
    if (posi == 1559) {
        *start = 1274;
        return (1487);
    }
    if (posi == 1630) {
        *start = 1062;
        return (1487);
    }
    return (1487);
}

enemy_t *is_direction_enemy(variable_t *sf, enemy_t *element)
{
    int start = 0;
    float angle = calcul_angle(element->posi.x, element->posi.y,
        sf->vector.hdv.x, sf->vector.hdv.y);

    element->rect.top = find_right_angle(angle);
    element->rect.left = 0;
    if ((angle > 285 && angle <= 360) || (angle < 75 && angle >= 0)) {
        take_position_enemy_sprite_two(&start, element->rect.top);
        element->rect.left = start;
    }
    element->rect.width = 71;
    element->rect.height = 71;
    return (element);
}

int take_position_enemy_sprite_one(int posi)
{
    if (posi == 1417)
        return (424);
    if (posi == 1488)
        return (353);
    if (posi == 1559)
        return (212);
    if (posi == 1630)
        return (424);
    if (posi == 1701)
        return (424);
    return (212);
}
