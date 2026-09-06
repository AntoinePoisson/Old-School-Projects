/*
** EPITECH PROJECT, 2018
** gestion
** File description:
** gestion
*/

#include "gestion.h"

void gestion_window_two(variable_t *sf)
{
    float seconds = sf->time.global.microseconds / 1000000.0;

    sf->time.global = sfClock_getElapsedTime(sf->clock.global);
    if (!(seconds <= sf->var_norm.pause_window_two)) {
        if (sf->var_norm.choose_person_w_t == 0)
            random_choose_person_w_o_w_t(sf);
        if (kill_window_two(sf) == 1)
            sf->var_norm.pause_window_two = seconds + rand_pause_window_t(sf);
        if (seconds >= (sf->var_norm.pause_window_two + 5)) {
            sfSprite_destroy(sf->sprite.window_two);
            sfTexture_destroy(sf->texture.window_two);
            create_window_two(sf);
            sf->var_norm.heal_point--;
            change_heal_point(sf);
            sf->var_norm.pause_window_two = seconds + rand_pause_window_t(sf);
        }
    }
}

void gestion_window_one(variable_t *sf)
{
    float seconds = sf->time.global.microseconds / 1000000.0;

    sf->time.global = sfClock_getElapsedTime(sf->clock.global);
    if (!(seconds <= sf->var_norm.pause_window_one)) {
        if (sf->var_norm.choose_person == 0)
            random_choose_person_w_o(sf);
        if (kill_window_one(sf) == 1) {
            sf->var_norm.pause_window_one = seconds + rand_pause_window_o(sf);
        }
        if (seconds >= (sf->var_norm.pause_window_one + 5)) {
            sfSprite_destroy(sf->sprite.window_one);
            sfTexture_destroy(sf->texture.window_one);
            create_window_one(sf);
            sf->var_norm.heal_point--;
            change_heal_point(sf);
            sf->var_norm.pause_window_one = seconds + rand_pause_window_o(sf);
        }
    }
}

void gestion_door_one(variable_t *sf)
{
    float seconds = sf->time.global.microseconds / 1000000.0;

    sf->time.global = sfClock_getElapsedTime(sf->clock.global);
    if (!(seconds <= sf->var_norm.pause_door_one)) {
        if (sf->var_norm.choose_person_d_o == 0)
            random_choose_person_d_o(sf);
        if (kill_door_one(sf) == 1) {
            sf->var_norm.pause_door_one = seconds + rand_pause_window_d_o(sf);
        }
        if (seconds >= (sf->var_norm.pause_door_one + 5)) {
            sfSprite_destroy(sf->sprite.door_one);
            sfTexture_destroy(sf->texture.door_one);
            create_door_one(sf);
            sf->var_norm.heal_point--;
            change_heal_point(sf);
            sf->var_norm.pause_door_one = seconds + rand_pause_window_d_o(sf);
        }
    }
}

void gestion_door_two(variable_t *sf)
{
    float seconds = sf->time.global.microseconds / 1000000.0;

    sf->time.global = sfClock_getElapsedTime(sf->clock.global);
    if (!(seconds <= sf->var_norm.pause_door_two)) {
        if (sf->var_norm.choose_person_d_t == 0)
            random_choose_person_d_t(sf);
        if (kill_door_two(sf) == 1) {
            sf->var_norm.pause_door_two = seconds + rand_pause_window_d_t(sf);
        }
        else if (seconds >= (sf->var_norm.pause_door_two + 5)) {
            sfSprite_destroy(sf->sprite.door_two);
            sfTexture_destroy(sf->texture.door_two);
            create_door_two(sf);
            sf->var_norm.heal_point--;
            change_heal_point(sf);
            sf->var_norm.pause_door_two = seconds + rand_pause_window_d_t(sf);
        }
    }
}

void gestion_back(variable_t *sf)
{
    sf->time.global = sfClock_getElapsedTime(sf->clock.global);
    float seconds = sf->time.global.microseconds / 1000000.0;

    if (!(seconds <= sf->var_norm.pause_back)) {
        if (sf->var_norm.acceleration_back == 0)
            random_choose_person_b(sf);
        if (kill_back(sf) == 1) {
            sf->var_norm.pause_back = seconds + rand_pause_window_b(sf);
        }
        if (seconds >= (sf->var_norm.pause_back + 5)) {
            sfSprite_destroy(sf->sprite.back);
            sfTexture_destroy(sf->texture.back);
            create_back(sf);
            sf->var_norm.heal_point--;
            change_heal_point(sf);
            sf->var_norm.pause_back = seconds + rand_pause_window_b(sf);
        }
    }
}
