/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void display_bird(variable_t *sf);
int gestion_acceleration_bg(int modulo);
char *my_itoa(int nbr, int neg);
void display_health_point(variable_t *sf);
void display_score(variable_t *sf);

void display_level(variable_t *sf)
{
    sfText *text = sfText_create();
    sfVector2f position;
    char *level = "Level:";
    sfFont *font_level = sfFont_createFromFile("./font/Fipps-Regular.ttf");

    sfText_setFont(text, font_level);
    position.x = 670;
    position.y = 450;
    sfText_setPosition(text, position);
    sfText_setString(text, level);
    sfRenderWindow_drawText(sf->win.dow, text, NULL);
    position.x += 165;
    sfText_setPosition(text, position);
    sfText_setString(text, my_itoa(sf->var_norm.level, 0));
    sfRenderWindow_drawText(sf->win.dow, text, NULL);
    sfRenderWindow_display(sf->win.dow);
    sfText_destroy(text);
    sfFont_destroy(font_level);
    sf->var_norm.level += 1;
}

void display_obstacle(variable_t *sf)
{
    for (int i = 1; i <= sf->var_norm.nbr_obstacle; i++) {
        if (sf->obj->position.x > -146) {
            sf->obj->position.x -= sf->var_norm.speed_background;
            sfSprite_setPosition(sf->sprite.cactus, sf->obj->position);
            sfSprite_setTextureRect(sf->sprite.cactus, sf->obj->rect);
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.cactus, NULL);
            if (sf->obj->position.x <= -146)
                sf->var_norm.nbr_obstacle_past += 1;
        }
        else
            sf->obj->position.x -= sf->var_norm.speed_background;
        sf->obj = sf->obj->next;
    }
}

void is_extension_display(variable_t *sf)
{
    display_obstacle(sf);
    display_score(sf);
    if (sf->var_norm.god_mode == 0)
        display_health_point(sf);
    if (sf->var_norm.bird_mode == 1)
        display_bird(sf);
    sfRenderWindow_display(sf->win.dow);
}

void display(variable_t *sf)
{
    int acceleration = 9;

    for (int i = 1; i <= 9; sf->bg = sf->bg->next, i++, acceleration--) {
        sf->bg->offset = ((sf->var_norm.speed_background *
            gestion_acceleration_bg(acceleration)) / 100);
        sf->bg->rect.left += sf->bg->offset;
        sfSprite_setTextureRect(sf->bg->sprite, sf->bg->rect);
        sfRenderWindow_drawSprite(sf->win.dow, sf->bg->sprite, NULL);
        if (sf->bg->rect.left > 4800)
            sf->bg->rect.left = 0;
    }
    if (sf->var_norm.dino_down == 1 && sf->vector.dino.y == 638) {
        sf->vector.dino.y += 51;
        sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.dino, NULL);
    }
    else
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.dino, NULL);
    is_extension_display(sf);
}

void display_score_transition(variable_t *sf)
{
    char *score = "Score:";

    sf->vector.message_score.y = sf->vector.score.y;
    sfText_setPosition(sf->text.score, sf->vector.message_score);
    sfText_setString(sf->text.score, score);
    sfRenderWindow_drawText(sf->win.dow, sf->text.score, NULL);
    sfText_setPosition(sf->text.score, sf->vector.score);
    sfText_setString(sf->text.score, my_itoa(sf->var_norm.score, 0));
    sfRenderWindow_drawText(sf->win.dow, sf->text.score, NULL);
}