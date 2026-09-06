/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

char *my_itoa(int nbr, int neg);
int damage_dino_check(variable_t *sf);

void is_extension_display_health_point(variable_t *sf)
{
    sfSprite_setTextureRect(sf->sprite.health_point, sf->rect.health_point);
    sfSprite_setPosition(sf->sprite.health_point, sf->vector.health_point);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.health_point, NULL);
}

void display_health_point(variable_t *sf)
{
    if (damage_dino_check(sf) == 1) {
        sf->rect.health_point.top += 160;
        sfSprite_setTextureRect(sf->sprite.health_point,
            sf->rect.health_point);
        sf->rect.heal.left = 1;
    }
    if (sf->rect.heal.left != 0 && sf->var_norm.health_point != 0) {
        sf->vector.heal.x = sf->vector.dino.x - 30;
        sf->vector.heal.y = sf->vector.dino.y - 40;
        sfSprite_setTextureRect(sf->sprite.heal, sf->rect.heal);
        sfSprite_setPosition(sf->sprite.heal, sf->vector.heal);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.heal, NULL);
        sf->rect.heal.left += 192;
        if (sf->rect.heal.left >= 2112)
            sf->rect.heal.left = 0;
    }
    sf->rect.health_point.left += ((sf->var_norm.speed_background * 30) / 100);
    if (sf->rect.health_point.left >= 1600)
        sf->rect.health_point.left = 0;
    is_extension_display_health_point(sf);
}

void display_score(variable_t *sf)
{
    char *score = "Score:";

    sfText_setPosition(sf->text.score, sf->vector.message_score);
    sfText_setString(sf->text.score, score);
    sfRenderWindow_drawText(sf->win.dow, sf->text.score, NULL);
    sfText_setPosition(sf->text.score, sf->vector.score);
    sfText_setString(sf->text.score, my_itoa(sf->var_norm.score, 0));
    sfRenderWindow_drawText(sf->win.dow, sf->text.score, NULL);
    sf->var_norm.score = sf->var_norm.score + 10;
}