/*
** EPITECH PROJECT, 2019
** paus_funct
** File description:
** pause the game
*/

#include "defender.h"

int check_pos_pause(sfVector2i pos)
{
    if (pos.x > 490 && pos.x < 600 && pos.y > 167 && pos.y < 265)
        return (1);
    if (pos.x > 366 && pos.x < 436 && pos.y > 185 && pos.y < 249)
        return (2);
    if (pos.x > 647 && pos.x < 715 && pos.y > 170 && pos.y < 250)
        return (3);
    return (0);
}

int pause_option(variable_t *sf, sfVector2i pos)
{
    int i = 0;

    if (sfKeyboard_isKeyPressed(sfKeyQ))
        return (1);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pos = sfMouse_getPositionRenderWindow(sf->win.dow);
        i = check_pos_pause(pos);
    }
    if (i == 1)
        return (1);
    if (i == 2) {
        sf->var_norm.quit_game = 1;
        return (1);
    }
    if (i == 3) {
        sf->var_norm.quit_game = 1;
        sf->var_norm.quit_menu = 1;
        return (1);
    }
    return (0);
}

void pause_game(variable_t *sf)
{
    sfVector2i pos;

    sf->var_norm.take_build = 0;
    sf->var_norm.id_of_take_build = 0;
    change_cursor(sf, 0);
    sfRenderWindow_setMouseCursorVisible(sf->win.dow, sfTrue);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.pause_menu, NULL);
    sfRenderWindow_display(sf->win.dow);
    while (sfRenderWindow_isOpen(sf->win.dow)) {
        sfRenderWindow_pollEvent(sf->win.dow, &sf->event.event);
        if (sf->event.event.type == sfEvtClosed) {
            sf->var_norm.quit_game = 1;
            sf->var_norm.quit_menu = 1;
            return;
        }
        if (pause_option(sf, pos) == 1)
            return;
    }
}
