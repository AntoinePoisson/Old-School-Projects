/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void display_score_transition(variable_t *sf);

void display_portail(variable_t *sf, int i)
{
    if (i >= 26)
        sf->rect.portal.left += 83;
    if (i < 26 && sf->vector.dino.x < 130) {
        sf->rect.portal.left += 83;
        if (sf->rect.portal.left >= 664)
            sf->rect.portal.left = 415;
    }
    if (sf->vector.dino.x >= 130 && sf->rect.portal.left >= 0)
        sf->rect.portal.left -= 83;
    sfSprite_setTextureRect(sf->sprite.portal, sf->rect.portal);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.portal, NULL);
}

void display_dino_transition(variable_t *sf, int i)
{
    if (sf->vector.dino.x < 130 && i < 26)
        sf->vector.dino.x += 6;
    if (sf->var_norm.slow_dino >= 3) {
        if (sf->rect.dino.left == 256)
            sf->rect.dino.left = 383;
        else
            sf->rect.dino.left = 256;
        sf->var_norm.slow_dino = 0;
    }
    else
        sf->var_norm.slow_dino += 1;
    sfSprite_setTextureRect(sf->sprite.dino, sf->rect.dino);
    sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.dino, NULL);
}

void is_extension_display_bg_menu_transition(variable_t *sf, int i)
{
    if (i < 30 && i >= 0) {
        if (sf->vector.health_point.y > 740)
            sf->vector.health_point.y -= 11;
        if (sf->vector.health_point.y < 740)
            sf->vector.health_point.y = 740;
        if (sf->vector.score.y <= 30)
            sf->vector.score.y += 2;
        sfSprite_setPosition(sf->sprite.health_point, sf->vector.health_point);
        if (sf->var_norm.god_mode == 0)
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.health_point,
                NULL);
        display_score_transition(sf);
    }
}

void is_extension_display_bg_menu_transition_two(variable_t *sf, int i)
{
    if (i < 20) {
        display_dino_transition(sf, i);
        display_portail(sf, i);
        if (sf->var_norm.god_mode == 0)
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.health_point,
                NULL);
        display_score_transition(sf);
    }
}

void display_bg_menu_transition(variable_t *sf, int i)
{
    for (int i = 1; i <= 9; sf->bg = sf->bg->next, i++) {
        sf->bg->rect.left += sf->bg->offset;
        sfSprite_setTextureRect(sf->bg->sprite, sf->bg->rect);
        sfRenderWindow_drawSprite(sf->win.dow, sf->bg->sprite, NULL);
        if (sf->bg->rect.left > 4800)
            sf->bg->rect.left = 0;
    }
    if (i >= 30) {
        sf->vector.select.x -= 40;
        sf->vector.select.y = 0;
        sfSprite_setPosition(sf->sprite.menu, sf->vector.select);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.menu, NULL);
        sf->vector.select.y = -130;
        sfSprite_setPosition(sf->sprite.select, sf->vector.select);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.select, NULL);
    }
    is_extension_display_bg_menu_transition(sf, i);
    is_extension_display_bg_menu_transition_two(sf, i);
}