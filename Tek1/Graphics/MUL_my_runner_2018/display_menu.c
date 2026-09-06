/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include <unistd.h>
#include "my_lib.h"
#include "csfml.h"
#include "struct.h"

char *data_highscore_file(int);

void display_text_highscore_bird(variable_t *sf)
{
    char *text = "Level:";
    static char *level = "first";

    if (level[0] == 'f')
        level = data_highscore_file(1);
    sf->vector.message_highscore.y = 550;
    sf->vector.message_highscore.x = 710;
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, text);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
    sf->vector.message_highscore.x = 805;
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, level);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
}

void display_text_highscore_level(variable_t *sf)
{
    char *text = "Bird:";
    static char *bird = "first";

    sf->vector.message_highscore.y = 500;
    sf->vector.message_highscore.x = 710;
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, text);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
    sf->vector.message_highscore.x = 805;
    if (bird[0] == 'f') {
        if (my_getnbr(data_highscore_file(1)) != 0)
            bird = "On";
        else
            bird = "Off";
    }
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, bird);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
    display_text_highscore_bird(sf);
}

void display_text_highscore(variable_t *sf)
{
    char *text = "Score:";
    static char *score = "first";

    if (score[0] == 'f') {
        score = data_highscore_file(0);
    }
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, text);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
    sf->vector.message_highscore.x = 805;
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, score);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
    display_text_highscore_level(sf);
    sf->vector.message_highscore.x = 710;
    sf->vector.message_highscore.y = 445;
}

void display_highscore(variable_t *sf)
{
    for (int i = 1; i <= 9; sf->bg = sf->bg->next, i++) {
        sf->bg->rect.left += sf->bg->offset;
        sfSprite_setTextureRect(sf->bg->sprite, sf->bg->rect);
        sfRenderWindow_drawSprite(sf->win.dow, sf->bg->sprite, NULL);
        if (sf->bg->rect.left > 4800)
            sf->bg->rect.left = 0;
    }
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_highscore, NULL);
    display_text_highscore(sf);
    sfRenderWindow_display(sf->win.dow);
}

void display_highscore_transition(variable_t *sf)
{
    for (int i = 1; i <= 9; sf->bg = sf->bg->next, i++) {
        sf->bg->rect.left += sf->bg->offset;
        sfSprite_setTextureRect(sf->bg->sprite, sf->bg->rect);
        sfRenderWindow_drawSprite(sf->win.dow, sf->bg->sprite, NULL);
        if (sf->bg->rect.left > 4800)
            sf->bg->rect.left = 0;
    }
    sfSprite_setPosition(sf->sprite.select, sf->vector.select);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.select, NULL);
    sfSprite_setPosition(sf->sprite.bg_highscore, sf->vector.bg_highscore);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_highscore, NULL);
    sfSprite_setPosition(sf->sprite.menu, sf->vector.select);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.menu, NULL);
    sfRenderWindow_display(sf->win.dow);
}
