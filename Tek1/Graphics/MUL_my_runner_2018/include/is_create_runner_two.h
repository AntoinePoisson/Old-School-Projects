/*
** EPITECH PROJECT, 2018
** control_move_dino
** File description:
** control_move_dino
*/

#ifndef IS_CREATE_RUNNER_TWO_H
#define IS_CREATE_RUNNER_TWO_H

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void create_dino(variable_t *sf);
void create_bird(variable_t *sf);
void create_text_score(variable_t *sf);
void create_health_point(variable_t *sf);
void create_heal(variable_t *sf);
void create_portal(variable_t *sf);
void create_cactus(variable_t *sf);
void create_win_or_loss(variable_t *sf);
void create_end_level(variable_t *sf);
void create_element(variable_t *sf, int i);

#endif