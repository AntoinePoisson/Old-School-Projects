/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** is_menu
*/

#include "is_menu.h"

int menu_second(variable_t *sf)
{
    float seconds = 0;

    sf->var_norm.game = 1;
    sf->var_norm.end_game = 0;
    create_texture_and_sprite(sf);
    sfRenderWindow_setMouseCursorVisible(sf->win.dow, 0);
    sf->clock.global = sfClock_create();
    sf->clock.duck = sfClock_create();
    while (sfRenderWindow_isOpen(sf->win.dow) && sf->var_norm.end_game == 0) {
        sf->time.global = sfClock_getElapsedTime(sf->clock.duck);
        seconds = sf->time.global.microseconds / 1000000.0;
        if (seconds > 0.01 && sf->var_norm.end_game == 0) {
            main_boucle(sf);
            sfClock_restart(sf->clock.duck);
        }
    }
    is_close_prog(sf);
    return (0);
}

void is_extension_menu_three(variable_t *sf)
{
    if (sf->var_norm.end_game == 1) {
        sfRenderWindow_setMouseCursorVisible(sf->win.dow, 1);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_menu, NULL);
        sfRenderWindow_display(sf->win.dow);
    }
}

void is_extension_menu_close(variable_t *sf)
{
    sfSprite_destroy(sf->sprite.bg_menu);
    sfTexture_destroy(sf->texture.bg_menu);
    sfSprite_destroy(sf->sprite.play);
    sfTexture_destroy(sf->texture.play);
    sfSprite_destroy(sf->sprite.end);
    sfTexture_destroy(sf->texture.end);
}

int is_extension_menu_two(variable_t *sf, int seconds)
{
    if (seconds >= 0.09) {
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_menu, NULL);
        sfRenderWindow_display(sf->win.dow);
        if (sf->event.event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfSprite_destroy(sf->sprite.bg_menu);
            sfTexture_destroy(sf->texture.bg_menu);
            return (1);
        }
        sfClock_restart(sf->clock.menu);
    }
    return (0);
}

void is_extension_menu_ext(variable_t *sf)
{
    if (sfSprite_getPosition(sf->sprite.play).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.play).y))
        if (sfSprite_getPosition(sf->sprite.play).y + 68 >= sf->vector.twoi.y
            && sf->vector.twoi.x <= (sfSprite_getPosition(sf->sprite.play).x
                + 230))
            menu_second(sf);
}
