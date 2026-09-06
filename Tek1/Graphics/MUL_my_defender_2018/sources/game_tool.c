/*
** EPITECH PROJECT, 2019
** game_tool
** File description:
** game tool
*/

#include "defender.h"

int is_ext_find_selec_game_tool(sfVector2f posi, variable_t *sf, int cas)
{
    if (cas == 0)
        return (0);
    if (1309 <= posi.x && posi.y >= 139 &&
        202 >= posi.y && posi.x <= 1372) {
        if (reparation_build(sf) == 0) {
            sf->var_norm.reparation = 10;
        }
    }
    if (1436 <= posi.x && posi.y >= 140 &&
        204 >= posi.y && posi.x <= 1500) {
        if (accelerer_time(sf) == 0)
            sf->var_norm.acceleration = 10;
    }
    return (0);
}

int find_selec_game_tool(sfVector2f posi, variable_t *sf, int cas)
{
    if (1110 <= posi.x && posi.y >= 24)
        if (134 >= posi.y && posi.x <= 1225)
            return (1);
    if (1110 <= posi.x && posi.y >= 150)
        if (260 >= posi.y && posi.x <= 1225)
            return (2);
    if (1110 <= posi.x && posi.y >= 280)
        if (393 >= posi.y && posi.x <= 1225)
            return (3);
    if (1110 <= posi.x && posi.y >= 409)
        if (520 >= posi.y && posi.x <= 1225)
            return (4);
    if (1110 <= posi.x && posi.y >= 536)
        if (647 >= posi.y && posi.x <= 1225)
            return (5);
    if (1110 <= posi.x && posi.y >= 664)
        if (774 >= posi.y && posi.x <= 1225)
            return (6);
    return (is_ext_find_selec_game_tool(posi, sf, cas));
}

void is_extension_management_select_game_tool_(variable_t *sf, int cas)
{
    if (cas == 6) {
        sf->var_norm.take_build = 1;
        sf->var_norm.id_of_take_build = 30;
    }
    if (cas == 7)
        if (reparation_build(sf) == 0)
            sf->var_norm.reparation = 10;
    if (cas == 8)
        if (accelerer_time(sf) == 0)
            sf->var_norm.acceleration = 10;
}

void is_extension_management_select_game_tool(variable_t *sf, int cas)
{
    switch (cas) {
        case 1: sf->var_norm.take_build = 1;
            sf->var_norm.id_of_take_build = 11;
            return;
        case 2: sf->var_norm.take_build = 1;
            sf->var_norm.id_of_take_build = 12;
            return;
        case 3: sf->var_norm.take_build = 1;
            sf->var_norm.id_of_take_build = 13;
            return;
        case 4: sf->var_norm.take_build = 1;
            sf->var_norm.id_of_take_build = 14;
            return;
        case 5: sf->var_norm.take_build = 1;
            sf->var_norm.id_of_take_build = 15;
            return;
        default: is_extension_management_select_game_tool_(sf, cas);
            return;
    }
}

void management_select_game_tool(variable_t *sf, sfVector2f posi)
{
    int cas = 0;

    if ((cas = find_selec_game_tool(posi, sf, 1)) == 0)
        return;
    sf->var_norm.effet = 10;
    is_extension_management_select_game_tool(sf, cas);
}
