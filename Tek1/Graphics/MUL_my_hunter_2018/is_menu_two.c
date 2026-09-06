/*
** EPITECH PROJECT, 2018
** is_menu_two
** File description:
** is_menu_two
*/

#include "is_menu_two.h"

int is_extension_menu(variable_t *sf)
{
    sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
    is_extension_menu_ext(sf);
    if (sfSprite_getPosition(sf->sprite.end).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.end).y)) {
        if (sfSprite_getPosition(sf->sprite.end).y + 66 >= sf->vector.twoi.y &&
            sf->vector.twoi.x <= (sfSprite_getPosition(sf->sprite.end).x
                + 123)) {
            sfSprite_destroy(sf->sprite.bg_menu);
            sfTexture_destroy(sf->texture.bg_menu);
            sfSprite_destroy(sf->sprite.play);
            sfTexture_destroy(sf->texture.play);
            sfSprite_destroy(sf->sprite.end);
            sfTexture_destroy(sf->texture.end);
            return (0);
        }
    }
    return (1);
}

int menu(variable_t *sf)
{
    float seconds = 0;

    create_menu_sprite_and_texture(sf);
    create_menu_bg(sf);
    create_menu_bg(sf);
    while (sfRenderWindow_isOpen(sf->win.dow)) {
        is_extension_menu_three(sf);
        sfRenderWindow_pollEvent(sf->win.dow, &sf->event.event);
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            if (is_extension_menu(sf) == 0)
                return (0);
        if (is_extension_menu_two(sf, seconds) == 1)
            return (0);
    }
    is_extension_menu_close(sf);
    return (0);
}

int main_second(void)
{
    variable_t *sf = malloc(sizeof(*sf));

    sf->var_norm.game = 0;
    if (sf == NULL) {
        my_putstr("can not alloc memory\n");
        return (ERROR);
    }
    open_window(sf);
    menu(sf);
    if (sf->var_norm.game == 0) {
        sfRenderWindow_destroy(sf->win.dow);
        sfRenderWindow_close(sf->win.dow);
    }
    return (0);
}

void option_h(void)
{
    my_putstr("USAGE\n      ./my_hunter\nDESCRIPTION\n");
    my_putstr("       This is a small video game based on the");
    my_putstr(" rules of Duck Hunt.\n");
}
