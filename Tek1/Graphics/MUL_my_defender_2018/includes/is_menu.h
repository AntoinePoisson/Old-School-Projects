/*
** EPITECH PROJECT, 2018
** control_move_dino
** File description:
** control_move_dino
*/

#ifndef IS_MENU_H
#define IS_MENU_H

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"
#include "csfml.h"
#include "my_struct.h"

void how_to_play(variable_t *sf);
int is_defender(variable_t *sf);
void open_window(variable_t *sf);
int is_runner(variable_t *sf, char *av[], int ac);
void check_argument(char *av[], int ac, variable_t *sf);
void create_bg(variable_t *sf);
void create_end_level(variable_t *sf);
int open_file_highscore(void);
int analyse_file(char *file, int nbr);
void create_music(variable_t *sf);
void create_bg_highscore(variable_t *sf);
void create_text_highscore(variable_t *sf);
void create_obj_menu(variable_t *sf);
void create_menu(variable_t *sf);
void is_extension_destroy_menu(variable_t *sf);
void destroy_menu(variable_t *sf);
void create_is_second_menu(variable_t *sf);
int select_on_play(variable_t *sf);
int select_on_highscore(variable_t *sf);
int select_on_quit(variable_t *sf);
void is_extension_transition_menu_to_highscore_two(variable_t *sf);
int is_extension_transition_menu_to_highscore_three(variable_t *sf,
    int seconds);
void first_transition_menu_to_highscore(variable_t *sf);
void end_transition_highscore_to_menu(variable_t *sf);
void transition_menu_to_highscore(variable_t *sf);
void display_text_highscore_bird(variable_t *sf);
void display_text_highscore_level(variable_t *sf);
void display_text_highscore(variable_t *sf);
void display_highscore(variable_t *sf);
void display_highscore_transition(variable_t *sf);
void position_obj_menu(variable_t *sf);
void clic_button_play(variable_t *sf);
char *data_highscore_file(int);
int check_file_highscore(void);
void highscore(variable_t *sf);

#endif
