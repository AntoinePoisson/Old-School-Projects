/*
** EPITECH PROJECT, 2018
** control_move_dino
** File description:
** control_move_dino
*/

#ifndef IS_RUNNER_H
#define IS_RUNNER_H

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void dino_move_up(variable_t *sf);
void dino_move_right(variable_t *sf);
void dino_move_left(variable_t *sf);
void dino_move_down(variable_t *sf);
void create_dino(variable_t *sf);
void gestion_dino(variable_t *sf);
int gestion_acceleration_bg(int modulo);
void dino_move_speed(variable_t *sf);
int is_create_obstacle(char *av[], int ac, variable_t *sf);
void end_level(variable_t *sf);
char *my_itoa(int nbr, int neg);
void create_bird(variable_t *sf);
void display_bird(variable_t *sf);
void control_score(variable_t *sf);
void create_text_score(variable_t *sf);
void create_health_point(variable_t *sf);
void create_heal(variable_t *sf);
void create_portal(variable_t *sf);
void create_cactus(variable_t *sf);
void create_win_or_loss(variable_t *sf);
void create_end_level(variable_t *sf);
void create_element(variable_t *sf, int i);
void is_extension_display_health_point(variable_t *sf);
void display_health_point(variable_t *sf);
void display_score(variable_t *sf);
void display_level(variable_t *sf);
void display_obstacle(variable_t *sf);
void is_extension_display(variable_t *sf);
void display(variable_t *sf);
void display_portail(variable_t *sf, int i);
void display_dino_transition(variable_t *sf, int i);
void is_extension_display_bg_menu_transition(variable_t *sf, int i);
void is_extension_display_bg_menu_transition_two(variable_t *sf, int i);
void display_bg_menu_transition(variable_t *sf, int i);
void transition_end_leve_first(variable_t *sf);
void is_extension_transition_end_leve_second(variable_t *sf, int *i);
void is_extension_transition_end_leve_second_two(variable_t *sf);
void transition_end_leve_second(variable_t *sf);
void transition_menu_to_game(variable_t *sf);
void end_level_loss_case(variable_t *sf);
void end_level_win_case(variable_t *sf);
void end_level_infinity_mode_case_init(variable_t *sf);
void end_level_infinity_mode_case(variable_t *sf);
void end_level(variable_t *sf);
int touch_dino_left_top(variable_t *sf, int *i, int *value_return);
int touch_dino_right_top(variable_t *sf, int *i, int *value_return);
int touch_dino_mid_left(variable_t *sf, int *i, int *value_return);
void is_extension_damage_dino_check(variable_t *sf, int *i, int *value_return);
int touch_bird_left_top(variable_t *sf, int *value_return);
int touch_bird_left_mid(variable_t *sf, int *value_return);
int touch_bird_bot_left(variable_t *sf, int *value_return);
void is_extension_damage_bird_check(variable_t *sf, int *value_return);
int damage_dino_check(variable_t *sf);

#endif