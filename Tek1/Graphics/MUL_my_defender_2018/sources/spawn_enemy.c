/*
** EPITECH PROJECT, 2019
** spawn enemy
** File description:
** spawn enemy
*/

#include <math.h>
#include <stdlib.h>
#include "defender.h"

void is_destroy_enemy(variable_t *sf)
{
    free(sf->enemy);
    sf->enemy = NULL;
}

void find_coef(variable_t *sf, enemy_t **element)
{
    sfVector2f posi = (*element)->posi;
    sfVector2f hdv = sf->vector.hdv;

    if ((hdv.x - posi.x) == 0)
        hdv.x += 0.001;
    (*element)->coef_x = ((posi.y - hdv.y) / (posi.x - hdv.x));
    (*element)->coef_y = (posi.y - (posi.x * (*element)->coef_x));
}

int zone_spawn_enemy_x(int cas)
{
    switch (cas) {
        case 1: return (105);
        case 2: return (269);
        case 3: return (431);
        case 4: return (625);
        case 5: return (770);
        case 6: return (945);
        case 7: return (1004);
        case 8: return (823);
        case 9: return (625);
        case 10: return (418);
        case 11: return (269);
        case 12: return (102);
    }
    return (0);
}

int zone_spawn_enemy_y(int cas)
{
    switch (cas) {
        case 1: return (323);
        case 2: return (199);
        case 3: return (79);
        case 4: return (60);
        case 5: return (168);
        case 6: return (300);
        case 7: return (448);
        case 8: return (581);
        case 9: return (733);
        case 10: return (703);
        case 11: return (594);
        case 12: return (469);
    }
    return (0);
}

sfVector2f management_spawn_enemy(int i)
{
    static int cas = 0;
    sfVector2f vector;

    if (i == 0) {
        cas = rand() % (13 - 1) + 1;
        cas -= 1;
    }
    vector.x = zone_spawn_enemy_x(cas);
    vector.y = zone_spawn_enemy_y(cas);
    vector.x += rand() % (70 - 1) + 1;
    vector.y += rand() % (70 - 1) + 1;
    return (vector);
}
