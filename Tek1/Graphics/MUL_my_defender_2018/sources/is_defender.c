/*
** EPITECH PROJECT, 2019
** is_defender.c
** File description:
** file of defender
*/

#include <math.h>
#include "defender.h"

int check_win(variable_t *sf)
{
    static int count = 0;
    int i = 0;
    build_t *build = sf->build;

    if (count < 5) {
        count++;
        return (0);
    }
    count = 0;
    for (; build && i < sf->var_norm.nbr_node_list_build; i++) {
        if (build->id == 11 && build->data->hp <= 0) {
            sfMusic_play(sf->music.loss);
            return (1);
        }
        build = build->next;
    }
    return (0);
}

void refresh_game(variable_t *sf, float seconds)
{
    if (seconds >= 0.013) {
        sf->var_norm.timer += 1;
        management_trap(sf);
        management_wave(sf);
        find_shoot(sf);
        management_enemy(sf);
        display_game(sf);
        sfClock_restart(sf->clock.game);
        if (check_win(sf) == 1)
            sf->var_norm.quit_game = 1;
    }
}

int check_right_event(variable_t *sf)
{
    if (sf->event.event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape) ||
        sfMouse_isButtonPressed(sfMouseLeft) ||
        sfMouse_isButtonPressed(sfMouseRight))
        return (1);
    return (0);
}

int is_defender(variable_t *sf)
{
    float seconds = 0;

    if (is_create_game(sf) != 0)
        return (84);
    while (sfRenderWindow_isOpen(sf->win.dow) && sf->var_norm.quit_game != 1) {
        sf->time.game = sfClock_getElapsedTime(sf->clock.game);
        seconds = sf->time.game.microseconds / 1000000.0;
        if (sfRenderWindow_pollEvent(sf->win.dow, &sf->event.event) &&
            check_right_event(sf) == 1)
            management_event(sf);
        else
            refresh_game(sf, seconds);
    }
    change_cursor(sf, 1);
    for (build_t *build = sf->build; build; build = build->next)
        if (build->id == 11 && build->data->hp <= 0)
            end_game(sf);
    change_cursor(sf, 0);
    sfRenderWindow_setMouseCursorVisible(sf->win.dow, sfTrue);
    return (destroy_game(sf));
}
