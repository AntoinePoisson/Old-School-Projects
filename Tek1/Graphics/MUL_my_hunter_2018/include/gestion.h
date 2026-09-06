/*
** EPITECH PROJECT, 2018
** create
** File description:
** create
*/

#ifndef GESTION_H
#define GESTION_H

#include "include_csfml.h"
#include "struct.h"

void random_choose_person_w_o_w_t(variable_t *sf);
int kill_window_two(variable_t *sf);
float rand_pause_window_t(variable_t *sf);
void create_window_two(variable_t *sf);
void change_heal_point(variable_t *sf);
void random_choose_person_w_o(variable_t *sf);
int kill_window_one(variable_t *sf);
float rand_pause_window_o(variable_t *sf);
void create_window_one(variable_t *sf);
void random_choose_person_d_o(variable_t *sf);
int kill_door_one(variable_t *sf);
float rand_pause_window_o(variable_t *sf);
void create_door_one(variable_t *sf);
void is_ext_random_choose_person_d_t(variable_t *sf, int perso_have_choise);
int kill_door_two(variable_t *sf);
float rand_pause_window_d_t(variable_t *sf);
void create_door_two(variable_t *sf);
int kill_back(variable_t *sf);
void random_choose_person_b(variable_t *sf);
float rand_pause_window_b(variable_t *sf);
void create_back(variable_t *sf);
float rand_pause_window_d_o(variable_t *sf);
void random_choose_person_d_t(variable_t *sf);

#endif