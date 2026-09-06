/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "is_menu.h"

void display_bg_menu(variable_t *sf)
{
    for (int i = 1; i <= 9; sf->bg = sf->bg->next, i++) {
        sf->bg->rect.left += sf->bg->offset;
        sfSprite_setTextureRect(sf->bg->sprite, sf->bg->rect);
        sfRenderWindow_drawSprite(sf->win.dow, sf->bg->sprite, NULL);
        if (sf->bg->rect.left > 4800)
            sf->bg->rect.left = 0;
    }
    if (select_on_play(sf) == 1)
        sf->vector.select.y = -130;
    if (select_on_highscore(sf) == 1)
        sf->vector.select.y = 0;
    if (select_on_quit(sf) == 1)
        sf->vector.select.y = 130;
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

void is_extension_is_second_menu(variable_t *sf, char *av[], int ac)
{
    if (sf->event.event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape) ||
        (sfMouse_isButtonPressed(sfMouseLeft) &&
        select_on_highscore(sf) == 1))
        highscore(sf);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        select_on_play(sf) == 1)
        clic_button_play(sf, av, ac);
}

void is_second_menu(variable_t *sf, char *av[], int ac)
{
    float seconds = 0;

    while (sfRenderWindow_isOpen(sf->win.dow) && sf->var_norm.menu == 1) {
        sf->time.menu = sfClock_getElapsedTime(sf->clock.menu);
        seconds = sf->time.menu.microseconds / 1000000.0;
        if (sfRenderWindow_pollEvent(sf->win.dow, &sf->event.event)) {
            if (sf->event.event.type == sfEvtClosed ||
                sfKeyboard_isKeyPressed(sfKeyEscape) ||
                (sfMouse_isButtonPressed(sfMouseLeft) &&
                select_on_quit(sf) == 1))
                break;
            is_extension_is_second_menu(sf, av, ac);
        }
        refresh_menu(sf, seconds);
    }
}

int menu(char *av[], int ac)
{
    variable_t *sf = malloc(sizeof(*sf));

    if (sf == NULL) {
        my_putstr("can not alloc memory\n");
        return (EXIT_ERROR);
    }
    check_argument(av, ac, sf);
    open_window(sf);
    create_is_second_menu(sf);
    is_second_menu(sf, av, ac);
    destroy_menu(sf);
    free(sf);
    return (0);
}
