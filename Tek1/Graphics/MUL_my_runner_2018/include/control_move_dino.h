/*
** EPITECH PROJECT, 2018
** control_move_dino
** File description:
** control_move_dino
*/

#ifndef CONTROL_MOVE_DINO_H
#define CONTROL_MOVE_DINO_H

#include "csfml.h"
#include "struct.h"

void gestion_dino(variable_t *sf);
void display(variable_t *sf);
void dino_move_up(variable_t *sf);
void dino_move_right(variable_t *sf);
void dino_move_left(variable_t *sf);
void is_extension_dino_move_down(variable_t *sf);
void dino_move_down_display(variable_t *sf);

#endif