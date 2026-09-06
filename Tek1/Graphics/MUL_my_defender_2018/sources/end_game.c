/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** screen of end game
*/

#include "my_lib.h"
#include "defender.h"

void freeze_screen(variable_t *sf)
{
    sfTime pause = sfSeconds(2.0);
    sfVector2f posi = {0, 0};

    sf->rect.end_level.top = 0;
    sf->rect.end_level.left = 0;
    sfSprite_setPosition(sf->sprite.end_level, posi);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.end_level, NULL);
    sfRenderWindow_display(sf->win.dow);
    sf->rect.end_level.top = 0;
    sf->rect.end_level.left = 1600;
    sfSleep(pause);
}

void transition_end_game(variable_t *sf)
{
    float seconds = 0;
    int i = 18;

    while (i) {
        sf->time.game = sfClock_getElapsedTime(sf->clock.game);
        seconds = sf->time.game.microseconds / 1000000.0;
        if (seconds >= 0.020) {
            is_extension_transition_end_game(sf, &i);
        }
    }
}

void display_scoreboard(variable_t *sf)
{
    int nbr_enemy = sf->var_norm.kill;
    int time = (sf->var_norm.timer) / 60;
    char *text_time = my_strcat(my_itoa(time, 0), "  Seconds");
    char *text_kill = my_strcat(my_itoa(nbr_enemy, 0), "  Kill");
    sfVector2f posi = {760, 570};

    sfText_setColor(sf->text.text_money, sfWhite);
    sfText_setString(sf->text.text_money, text_kill);
    sfText_setPosition(sf->text.text_money, posi);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_money, NULL);
    sfText_setString(sf->text.text_money, text_time);
    posi.x = 760;
    posi.y = 670;
    sfText_setPosition(sf->text.text_money, posi);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_money, NULL);
    sfRenderWindow_display(sf->win.dow);
}

void end_game(variable_t *sf)
{
    sfTime pause = sfSeconds(3.5);
    char *score = my_itoa(sf->var_norm.time_wave * sf->var_norm.level / 60, 0);
    char *level = my_itoa(ENEMY_NBR + ENEMY_NBR * sf->var_norm.level / 2, 0);

    sfMusic_play(sf->music.loss);
    freeze_screen(sf);
    transition_end_game(sf);
    sf->rect.end_level.left = 6400;
    sf->rect.end_level.top = 2800;
    sf->rect.end_level.width = 1600;
    sf->rect.end_level.height = 800;
    sfSprite_setTextureRect(sf->sprite.end_level, sf->rect.end_level);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.end_level, NULL);
    display_scoreboard(sf);
    if ((compare_score(sf->var_norm.time_wave * sf->var_norm.level / 60,
        ENEMY_NBR + (ENEMY_NBR * sf->var_norm.level) / 2, 0)) != 0)
        write_file(score, level, "0");
    sfSleep(pause);
}
