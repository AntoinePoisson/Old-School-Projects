/*
** EPITECH PROJECT, 2019
** display_effet
** File description:
** display effet
*/

#include "defender.h"

sfIntRect find_tool_effet_posi(int id, sfVector2f *posi, int cas,
    sfIntRect rect)
{
    if (id == 11 && cas == 0) {
        (*posi).y = 25;
        rect.top = 2076;
    }
    if (id == 12 && cas == 0) {
        (*posi).y = 154;
        rect.top = 2205;
    }
    if (id == 13 && cas == 0) {
        (*posi).y = 284;
        rect.top = 2336;
    }
    if (id == 14 && cas == 0) {
        (*posi).y = 414;
        rect.top = 2466;
    }
    return (rect);
}

sfIntRect find_tool_effet_posi_(int id, sfVector2f *posi, int cas,
    sfIntRect rect)
{
    if (id == 1 && cas == 1) {
        rect.top = 2078;
        (*posi).y = 25;
    }
    if (id == 2 && cas == 1) {
        rect.top = 2207;
        (*posi).y = 154;
    }
    if (id == 3 && cas == 1) {
        rect.top = 2336;
        (*posi).y = 284;
    }
    if (id == 4 && cas == 1) {
        rect.top = 2466;
        (*posi).y = 414;
    }
    rect = find_tool_effet_posi(id, posi, cas, rect);
    rect = find_tool_effet_posi_two(id, posi, cas, rect);
    return (rect);
}

sfIntRect special_case(variable_t *sf, sfIntRect save, sfVector2f *posi)
{
    sfIntRect rect;

    if (sf->var_norm.acceleration == 0 && sf->var_norm.reparation == 0)
        return (save);
    rect.width = 63;
    rect.height = 63;
    if (sf->var_norm.acceleration != 0) {
        sf->var_norm.acceleration -= 1;
        rect.top = 2239;
        rect.left = 1061;
        (*posi).x = 1437;
        (*posi).y = 141;
    } else {
        sf->var_norm.reparation -= 1;
        rect.top = 2241;
        rect.left = 978;
        (*posi).y = 139;
        (*posi).x = 1309;
    }
    return (rect);
}

sfIntRect find_tool_effet(variable_t *sf, int id, sfVector2f *posi, int cas)
{
    sfIntRect rect;

    rect.width = 114;
    rect.height = 114;
    rect.top = -200;
    rect.left = 1171;
    (*posi).x = 1115;
    rect = find_tool_effet_posi_(id, posi, cas, rect);
    if (cas == 0)
        rect.left = 1287;
    if ((id == 6 && cas == 1 && sf->var_norm.take_build == 0) ||
        (id == 30 && cas == 0 && sf->var_norm.take_build == 0)) {
        (*posi).y = -500;
        rect.top = -500;
    }
    if ((id == 11 && cas == 0 && sf->vector.hdv.x != 0) ||
        (id == 1 && cas == 1 && sf->vector.hdv.x != 0))
        rect.top = -200;
    rect = special_case(sf, rect, posi);
    return (rect);
}

void display_effet(variable_t *sf)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(sf->win.dow);
    sfIntRect rect;
    sfVector2f result = {(posi.x * 1.0), (posi.y * 1.0)};
    int cas = 0;

    if (sf->var_norm.effet > 0 && sf->var_norm.take_build != 0) {
        sf->var_norm.effet -= 1;
        rect = find_tool_effet(sf, sf->var_norm.id_of_take_build, &result, 0);
    }
    else if ((cas = find_selec_game_tool(result, sf, 0)) != 0 ||
        sf->var_norm.acceleration != 0 || sf->var_norm.reparation != 0)
        rect = find_tool_effet(sf, cas, &result, 1);
    if (sf->var_norm.effet <= 0 && sf->var_norm.take_build == 0 &&
        find_selec_game_tool(result, sf, 0) == 0)
        return;
    sfSprite_setPosition(sf->sprite.resources, result);
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
}
