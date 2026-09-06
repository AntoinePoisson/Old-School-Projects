/*
** EPITECH PROJECT, 2018
** is_extension_display.c
** File description:
** is_extension_display
*/

#include "defender.h"

void is_extension_display_build(variable_t *sf, obj_t *save, int count)
{
    for (int i = 0; i < sf->var_norm.nbr_node_list_obj && save != NULL;
        i++, save = save->next)
        if (control_display(save, count, i, sf) == 1) {
            sfSprite_setPosition(sf->sprite.resources, save->data->position);
            sfSprite_setTextureRect(sf->sprite.resources, save->data->rect);
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
        }
}

void is_extension_transition_end_game(variable_t *sf, int *i)
{
    sfSprite_setTextureRect(sf->sprite.end_level, sf->rect.end_level);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.end_level, NULL);
    sfRenderWindow_display(sf->win.dow);
    sf->rect.end_level.left += 1600;
    if (sf->rect.end_level.left >= 8000) {
        sf->rect.end_level.left = 0;
        sf->rect.end_level.top += 900;
    }
    *i -= 1;
    sfClock_restart(sf->clock.game);
}

int is_ext_analy_file(int *nbr, int *count_separator)
{
    if (*nbr == 0)
        return (84);
    *count_separator += 1;
    *nbr = 0;
    return (0);
}

int is_extension_second_menu(variable_t *sf)
{
    if (sfRenderWindow_pollEvent(sf->win.dow, &sf->event.event)) {
        if (sf->event.event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape) ||
            (sfMouse_isButtonPressed(sfMouseLeft) &&
            select_on_quit(sf) == 1))
            return (1);
        is_extension_is_second_menu(sf);
    }
    return (0);
}

void is_extension_management_bombe(variable_t *sf, int cas)
{
    if (cas == 1 && sfMusic_getStatus(sf->music.bombe) != sfPlaying)
        sfMusic_play(sf->music.bombe);
    if (cas == 2 && sfMusic_getStatus(sf->music.trampo) != sfPlaying)
        sfMusic_play(sf->music.trampo);
}
