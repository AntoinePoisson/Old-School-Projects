/*
** EPITECH PROJECT, 2018
** control_move_dino
** File description:
** control_move_dino
*/

#ifndef IS_MENU_HIGHSCORE_H
#define IS_MENU_HIGHSCORE_H

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_lib.h"
#include "csfml.h"
#include "my_struct.h"

int analyse_file(char *file, int nbr);
void create_bg_highscore(variable_t *sf);
void create_text_highscore(variable_t *sf);
int open_file_highscore(void);
void first_transition_menu_to_highscore(variable_t *sf);
void transition_menu_to_highscore(variable_t *sf);

#endif
