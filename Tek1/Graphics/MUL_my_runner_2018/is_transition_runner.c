/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

int gestion_acceleration_bg(int modulo);
void display_bg_menu_transition(variable_t *sf, int i);
void create_element(variable_t *sf, int i);

void transition_end_leve_first(variable_t *sf)
{
    float seconds = 0;
    int i = 21;

    while (i) {
        sf->time.game = sfClock_getElapsedTime(sf->clock.game);
        seconds = sf->time.game.microseconds / 1000000.0;
        if (seconds >= 0.013) {
            sfSprite_setTextureRect(sf->sprite.end_level, sf->rect.end_level);
            sfSprite_setPosition(sf->sprite.end_level, sf->vector.end_level);
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.end_level, NULL);
            sfRenderWindow_display(sf->win.dow);
            sf->rect.end_level.left += 1600;
            if (sf->rect.end_level.left >= 8000) {
                sf->rect.end_level.left = 0;
                sf->rect.end_level.top += 900;
            }
            i--;
            sfClock_restart(sf->clock.game);
        }
    }
}
void is_extension_transition_end_leve_second(variable_t *sf, int *i)
{
    sfSprite_setTextureRect(sf->sprite.end_level, sf->rect.end_level);
    sfSprite_setPosition(sf->sprite.end_level, sf->vector.end_level);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.end_level, NULL);
    sfRenderWindow_display(sf->win.dow);
    sf->rect.end_level.left -= 1600;
    if (sf->rect.end_level.left < 0) {
        sf->rect.end_level.left = 6400;
        sf->rect.end_level.top -= 900;
    }
    *i -= 1;
    sfClock_restart(sf->clock.game);
}

void is_extension_transition_end_leve_second_two(variable_t *sf)
{
    sf->bg->rect.left += sf->bg->offset;
    sfSprite_setTextureRect(sf->bg->sprite, sf->bg->rect);
    sfRenderWindow_drawSprite(sf->win.dow, sf->bg->sprite, NULL);
}

void transition_end_leve_second(variable_t *sf)
{
    float seconds = 0;
    int acceleration = 9;
    int i = 21;

    while (i > 0) {
        sf->time.game = sfClock_getElapsedTime(sf->clock.game);
        seconds = sf->time.game.microseconds / 1000000.0;
        if (seconds >= 0.013) {
            acceleration = 9;
            for (int a = 1; a <= 9; sf->bg = sf->bg->next, a++,
                    acceleration--) {
                sf->bg->offset = ((sf->var_norm.speed_background *
                    gestion_acceleration_bg(acceleration)) / 100);
                is_extension_transition_end_leve_second_two(sf);
                if (sf->bg->rect.left > 4800)
                    sf->bg->rect.left = 0;
            }
            is_extension_transition_end_leve_second(sf, &i);
        }
    }
}

void transition_menu_to_game(variable_t *sf)
{
    float seconds = 0;
    sf->clock.game = sfClock_create();

    for (int i = 60; i >= -35;) {
        sf->time.game = sfClock_getElapsedTime(sf->clock.game);
        seconds = sf->time.game.microseconds / 1000000.0;
        if (seconds >= 0.013) {
            create_element(sf, i);
            display_bg_menu_transition(sf, i);
            sfRenderWindow_display(sf->win.dow);
            sfClock_restart(sf->clock.game);
            i--;
        }
    }
    sf->vector.select.y = 0;
    sf->vector.select.x = 0;
    sfSprite_setPosition(sf->sprite.menu, sf->vector.select);
    sf->vector.select.y = -900;
    sfSprite_setPosition(sf->sprite.select, sf->vector.select);
}