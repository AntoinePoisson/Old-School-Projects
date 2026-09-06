/*
** EPITECH PROJECT, 2018
** create
** File description:
** create
*/

#ifndef MOVE_PERSO_H
#define MOVE_PERSO_H

#include "include_csfml.h"
#include "struct.h"

int rand_ghost_x(void);
void change_time_score(variable_t *sf);
void change_heal_point(variable_t *sf);
void gestion_window_two(variable_t *sf);
void gestion_window_one(variable_t *sf);
void gestion_door_one(variable_t *sf);
void gestion_door_two(variable_t *sf);
void gestion_back(variable_t *sf);
void change_time_text(variable_t *sf);

#endif