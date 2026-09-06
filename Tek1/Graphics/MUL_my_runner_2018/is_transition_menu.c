/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "my_lib.h"
#include "csfml.h"
#include "struct.h"

void display_highscore(variable_t *sf);
void display_highscore_transition(variable_t *sf);

void is_extension_transition_menu_to_highscore_two(variable_t *sf)
{
    if (sf->vector.bg_highscore.y != 0) {
        sf->vector.bg_highscore.y = 0;
        sfSprite_setPosition(sf->sprite.select, sf->vector.select);
    }
}

int is_extension_transition_menu_to_highscore_three(variable_t *sf,
    int seconds)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
        sfMouse_isButtonPressed(sfMouseLeft))
        return (1);
    if (seconds >= 0.014) {
        display_highscore(sf);
        sfClock_restart(sf->clock.menu);
    }
    return (0);
}

void first_transition_menu_to_highscore(variable_t *sf)
{
    float seconds = 0;

    while (sf->vector.bg_highscore.y < 0) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (seconds >= 0.014) {
            sf->vector.bg_highscore.y += 50;
            sf->vector.select.y += 50;
            display_highscore_transition(sf);
            sfClock_restart(sf->clock.menu);
        }
    }
}

void end_transition_highscore_to_menu(variable_t *sf)
{
    float seconds = 0;

    while (sf->vector.select.y > 0) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (seconds >= 0.014) {
            sf->vector.bg_highscore.y -= 50;
            sf->vector.select.y -= 50;
            display_highscore_transition(sf);
            sfClock_restart(sf->clock.menu);
        }
    }
}

void transition_menu_to_highscore(variable_t *sf)
{
    float seconds = 0;

    first_transition_menu_to_highscore(sf);
    is_extension_transition_menu_to_highscore_two(sf);
    while (1) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (is_extension_transition_menu_to_highscore_three(sf, seconds) == 1)
            break;
    }
    end_transition_highscore_to_menu(sf);
}
