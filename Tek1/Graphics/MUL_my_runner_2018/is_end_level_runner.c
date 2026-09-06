/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void control_score(variable_t *sf);
void transition_end_leve_second(variable_t *sf);
void transition_end_leve_first(variable_t *sf);
void display_level(variable_t *sf);

void end_level_loss_case(variable_t *sf)
{
    sfTime pause = sfSeconds(1.0);

    if (sf->var_norm.nbr_obstacle_past < sf->var_norm.nbr_obstacle) {
        sfMusic_stop(sf->music.bg_game);
        sfMusic_play(sf->music.loss);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.loss, NULL);
        sfRenderWindow_display(sf->win.dow);
        sf->var_norm.level += 1;
        sfSleep(pause);
        sf->var_norm.quit_game = 0;
    }
}

void end_level_win_case(variable_t *sf)
{
    sfTime pause = sfSeconds(1.0);

    if (sf->var_norm.infinity_mode == 0 && sf->var_norm.nbr_obstacle_past >=
        sf->var_norm.nbr_obstacle) {
        sfMusic_stop(sf->music.bg_game);
        sfMusic_play(sf->music.win);
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.win, NULL);
        sfRenderWindow_display(sf->win.dow);
        sfSleep(pause);
        sf->var_norm.quit_game = 0;
    }
}

void end_level_infinity_mode_case_init(variable_t *sf)
{
    sfTime pause = sfSeconds(1.0);

    display_level(sf);
    sfSleep(pause);
    sf->var_norm.obstacle_touch = 0;
    sf->var_norm.slow_dino = 0;
    sf->var_norm.dino_jump = 0;
    sf->var_norm.dino_down_two = -2;
    sf->vector.dino.x = 30;
    sf->vector.dino.y = 638;
    sf->vector.health_point.x = 0;
    sf->rect.dino.top = 0;
    sf->rect.dino.left = 256;
    sf->rect.dino.width = 128;
    sf->rect.dino.height = 135;
    sfSprite_setTextureRect(sf->sprite.dino, sf->rect.dino);
    sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    sf->var_norm.nbr_obstacle_past = 0;
    if (sf->var_norm.quit_game != 0)
        sf->var_norm.speed_background += 5;
}

void end_level_infinity_mode_case(variable_t *sf)
{

    if (sf->var_norm.infinity_mode == 1 && sf->var_norm.nbr_obstacle_past >=
        sf->var_norm.nbr_obstacle) {
        end_level_infinity_mode_case_init(sf);
        if (sf->var_norm.bird_mode == 1) {
            for (int i = 1; i < 3; i++) {
                sf->bird->position.x = (rand() % ((1000 * i) - (500)) +
                    (500 * i)) + 1600;
                sf->var_norm.offset_bird = sf->var_norm.speed_background + 3;
                sf->bird = sf->bird->next;
            }
        }
        for (int i = 1; i <= sf->var_norm.nbr_obstacle; i++) {
            sf->obj->position.x = (sf->obj->position.x - 1454) * -1 + i * 2;
            sf->obj->rect.width = (73 + (73 * ((rand() % (3 - 1) + 1) / 2)))
                - 3;
            sf->obj = sf->obj->next;
        }
    }
}
void end_level(variable_t *sf)
{
    control_score(sf);
    end_level_loss_case(sf);
    sf->rect.end_level.left = 0;
    transition_end_leve_first(sf);
    end_level_win_case(sf);
    end_level_infinity_mode_case(sf);
    transition_end_leve_second(sf);
}