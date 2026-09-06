/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "is_menu.h"
#include "defender.h"

void display_bg_menu(variable_t *sf)
{
    if (select_on_play(sf) == 1)
        sf->vector.select.y = -130;
    if (select_on_highscore(sf) == 1)
        sf->vector.select.y = 0;
    if (select_on_quit(sf) == 1)
        sf->vector.select.y = 130;
    sfRenderWindow_clear(sf->win.dow, sfBlack);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_menu, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.menu, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.play, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.highscore, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.quit, NULL);
    sfSprite_setPosition(sf->sprite.select, sf->vector.select);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.select, NULL);
    sfRenderWindow_display(sf->win.dow);
}

void refresh_menu(variable_t *sf, float seconds)
{
    if (seconds >= 0.014) {
        display_bg_menu(sf);
        sf->vector.select.y = -900;
        sfClock_restart(sf->clock.menu);
    }
}

void is_extension_is_second_menu(variable_t *sf)
{
    sfVector2i vector = sfMouse_getPositionRenderWindow(sf->win.dow);

    if (sf->event.event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape) ||
        (sfMouse_isButtonPressed(sfMouseLeft) &&
        select_on_highscore(sf) == 1))
        highscore(sf);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        select_on_play(sf) == 1)
        clic_button_play(sf);
    if (1404 <= vector.x && vector.y >= 741 &&
        800 >= vector.y && vector.x <= 1600)
        how_to_play(sf);
}

void is_second_menu(variable_t *sf)
{
    float seconds = 0;

    while (sfRenderWindow_isOpen(sf->win.dow) && sf->var_norm.quit_menu == 0) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (is_extension_second_menu(sf) == 1)
            break;
        refresh_menu(sf, seconds);
    }
}

int menu(int flag)
{
    variable_t *sf = malloc(sizeof(*sf));

    if (sf == NULL) {
        my_puterror("Cannot alloc memory.\n");
        return (EXIT_ERROR);
    }
    if (flag == 1)
        sf->var_norm.mode_debug = 1;
    else
        sf->var_norm.mode_debug = 0;
    open_window(sf);
    create_is_second_menu(sf);
    is_second_menu(sf);
    destroy_menu(sf);
    free(sf);
    return (0);
}
