/*
** EPITECH PROJECT, 2018
** create
** File description:
** create
*/

#ifndef MOVE_PERSO_TWO_H
#define MOVE_PERSO_TWO_H

#include "include_csfml.h"
#include "struct.h"

void is_extension_move_ghost(int max_value, variable_t *sf);
void is_extension_move_ghost_three(variable_t *sf);
void is_extension_move_ghost_two(variable_t *sf);
int rand_duck_x(variable_t *sf);
int rand_duck_y(void);
void change_time_score(variable_t *sf);
void change_heal_point(variable_t *sf);
void change_time_text(variable_t *sf);
void change_cursor_mouse(variable_t *sf);


#endif