/*
** EPITECH PROJECT, 2018
** create
** File description:
** create
*/

#ifndef IS_MAIN_BOUCLE_H
#define IS_MAIN_BOUCLE_H

#include "include_csfml.h"
#include "struct.h"

void move_duck(int offset, int max_value, variable_t *sf);
void move_ghost(int offset, int max_value, variable_t *sf);
void gestion_door_one(variable_t *sf);
void gestion_door_two(variable_t *sf);
void change_time_text(variable_t *sf);
void change_cursor_mouse(variable_t *sf);
void create_girl_rev(variable_t *sf);
void create_girl_normal(variable_t *sf);
void put_out_map_ghost(variable_t *sf);
void put_out_map_duck(variable_t *sf);
int kill_back(variable_t *sf);
int kill_door_two(variable_t *sf);
int kill_door_one(variable_t *sf);
int kill_window_one(variable_t *sf);
int kill_window_two(variable_t *sf);
void gestion_window_two(variable_t *sf);
void gestion_window_one(variable_t *sf);
void gestion_back(variable_t *sf);

#endif