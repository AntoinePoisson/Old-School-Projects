/*
** EPITECH PROJECT, 2019
** management_event.c
** File description:
** management event of game
*/

#include "defender.h"

int control_money(variable_t *sf)
{
    switch (sf->var_norm.id_of_take_build) {
        case 11: return (is_extension_control_money(sf, 11));
        case 12: return (is_extension_control_money(sf, 12));
        case 13: return (is_extension_control_money(sf, 13));
        case 14: return (is_extension_control_money(sf, 14));
        case 15: return (is_extension_control_money(sf, 15));
        default: return (0);
    }
    return (0);
}

sfIntRect find_rect(variable_t *sf)
{
    sfIntRect rect = {0, 0, 0, 0};

    switch (sf->var_norm.id_of_take_build) {
        case 11: return (is_extension_find_rect(sf, 11, rect));
        case 12: return (is_extension_find_rect(sf, 12, rect));
        case 13: return (is_extension_find_rect(sf, 13, rect));
        case 14: rect.left = 0;
            rect.top = 502;
            rect.width = 26;
            rect.height = 34;
            return (rect);
        case 15: rect.left = 0;
            rect.top = 652;
            rect.width = 72;
            rect.height = 78;
            return (rect);
        case 30: return (is_extension_find_rect(sf, 30, rect));
    }
    return (rect);
}

int check_multiple_hdv(variable_t *sf)
{
    build_t *save = sf->build;

    for (int i = 0; i < sf->var_norm.nbr_node_list_obj && save;
        i++, save = save->next)
        if (save->id == 11)
            return (1);
    return (0);
}

sfIntRect check_rect(variable_t *sf, sfIntRect rect, sfVector2i mouse)
{
    if (control_hitbox_place_build(sf, mouse) == 0 && click_in_map(mouse) == 1)
        return (rect);
    switch (sf->var_norm.id_of_take_build) {
        case 11: rect.left = 1449;
            rect.top = 337;
            return (rect);
        case 12: rect.left = 1524;
            rect.top = 212;
            return (rect);
        case 13: rect.left = 1473;
            rect.top = 116;
            rect.height = 64;
            return (rect);
        case 14: rect.left = 1524;
            rect.top = 285;
            return (rect);
        case 15: rect.top = 738;
            return (rect);
    }
    return (rect);
}

void management_event(variable_t *sf)
{
    if (sf->event.event.type == sfEvtClosed) {
        sf->var_norm.quit_game = 1;
        sf->var_norm.quit_menu = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        pause_game(sf);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        management_click(sf, 1);
    if (sfMouse_isButtonPressed(sfMouseRight))
        management_click(sf, 0);
}
