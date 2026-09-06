/*
** EPITECH PROJECT, 2018
** management_how_to_play
** File description:
** management_how_to_play.c
*/

#include "is_menu.h"

static sfVector2f display_transition_menu_to_htp(variable_t *sf,
    sfVector2f vector, int cas)
{
    if (cas == 1)
        vector.x -= 10;
    else
        vector.y += 20;
    sfRenderWindow_clear(sf->win.dow, sfBlack);
    sfSprite_setPosition(sf->sprite.resources, vector);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_menu, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.menu, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.play, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.highscore, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.quit, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
    sfRenderWindow_display(sf->win.dow);
    return (vector);
}

static void menu_to_htp(variable_t *sf)
{
    sfIntRect rect;
    sfVector2f vector = {1800, 200};
    float seconds = 0;

    rect.left = 537;
    rect.top = 2136;
    rect.width = 303;
    rect.height = 563;
    sfSprite_setPosition(sf->sprite.resources, vector);
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    while (vector.x > 1060) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (seconds >= 0.014) {
            vector = display_transition_menu_to_htp(sf, vector, 1);
            sfClock_restart(sf->clock.menu);
        }
    }
}

static void htp_to_menu(variable_t *sf)
{
    sfIntRect rect;
    sfVector2f vector = {1060, 200};
    float seconds = 0;

    rect.left = 537;
    rect.top = 2136;
    rect.width = 303;
    rect.height = 563;
    sfSprite_setPosition(sf->sprite.resources, vector);
    sfSprite_setTextureRect(sf->sprite.resources, rect);
    while (vector.y < 2380) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (seconds >= 0.014) {
            vector = display_transition_menu_to_htp(sf, vector, 0);
            sfClock_restart(sf->clock.menu);
        }
    }
}

void how_to_play(variable_t *sf)
{
    int i = 1;

    menu_to_htp(sf);
    while (i) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
            sfMouse_isButtonPressed(sfMouseLeft))
            i = 0;
    }
    htp_to_menu(sf);
}
