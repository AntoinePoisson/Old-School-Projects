/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include <unistd.h>
#include "my_lib.h"
#include "csfml.h"
#include "my_struct.h"

char *data_highscore_file(int);

void display_text_highscore_level(variable_t *sf)
{
    char *text = "Survival Time:";
    static char *level = "first";

    if (level[0] == 'f')
        level = data_highscore_file(1);
    sf->vector.message_highscore.y = 550;
    sf->vector.message_highscore.x = 550;
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, text);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
    sf->vector.message_highscore.x = 805;
    sfText_setPosition(sf->text.text_highscore, sf->vector.message_highscore);
    sfText_setString(sf->text.text_highscore, level);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_highscore, NULL);
}

void display_text_highscore(variable_t *sf)
{
    char *text = "Kill :";
    static char *score = "first";

    if (score[0] == 'f')
        score = data_highscore_file(0);
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
    sfRenderWindow_clear(sf->win.dow, sfBlack);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_menu, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_highscore, NULL);
    display_text_highscore(sf);
    sfRenderWindow_display(sf->win.dow);
}

void display_highscore_transition(variable_t *sf)
{
    sfRenderWindow_clear(sf->win.dow, sfBlack);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_menu, NULL);
    sfSprite_setPosition(sf->sprite.select, sf->vector.select);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.select, NULL);
    sfSprite_setPosition(sf->sprite.bg_highscore, sf->vector.bg_highscore);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_highscore, NULL);
    sfSprite_setPosition(sf->sprite.menu, sf->vector.select);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.menu, NULL);
    sfRenderWindow_display(sf->win.dow);
}
