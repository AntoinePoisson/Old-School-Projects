/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

bool in_radius(sfVector2f pos1, sfVector2f pos2, unsigned int radius)
{
    int dx = pos2.x - pos1.x;
    int dy = pos2.y - pos1.y;
    int radii = radius + 1;

    if ((dx * dx) + (dy * dy) < radii * radii)
        return (true);
    else
        return (false);
}
