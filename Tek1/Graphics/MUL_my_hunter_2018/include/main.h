/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#ifndef MAIN_H
#define MAIN_H

#include "include_csfml.h"
#include "struct.h"
#define ERROR 84

void create_mccree_b(variable_t *sf);
void create_robot_b(variable_t *sf);
void create_mf_b(variable_t *sf);
void create_lucky_luke_b(variable_t *sf);
void create_boss_b(variable_t *sf);
void create_dalton_b(variable_t *sf);
void create_riven_b(variable_t *sf);
void create_mccree_two_b(variable_t *sf);
void create_cowboy_b(variable_t *sf);
void create_jinx_b(variable_t *sf);
void create_mccree_d_o(variable_t *sf);
void create_robot_d_o(variable_t *sf);
void create_mf_d_o(variable_t *sf);
void create_lucky_luke_d_o(variable_t *sf);
void create_boss_d_o(variable_t *sf);
void create_dalton_d_o(variable_t *sf);
void create_riven_d_o(variable_t *sf);
void create_mccree_two_d_o(variable_t *sf);
void create_cowboy_d_o(variable_t *sf);
void create_jinx_d_o(variable_t *sf);
void create_mccree_d_t(variable_t *sf);
void create_robot_d_t(variable_t *sf);
void create_mf_d_t(variable_t *sf);
void create_lucky_luke_d_t(variable_t *sf);
void create_boss_d_t(variable_t *sf);
void create_dalton_d_t(variable_t *sf);
void create_riven_d_t(variable_t *sf);
void create_mccree_two_d_t(variable_t *sf);
void create_cowboy_d_t(variable_t *sf);
void create_jinx_d_t(variable_t *sf);
void create_menu_bg(variable_t *sf);
void create_menu_sprite_and_texture(variable_t *sf);
void create_ghost(variable_t *sf);
void create_background_one(variable_t *sf);
void create_background_two(variable_t *sf);
void create_door_one(variable_t *sf);
void create_door_two(variable_t *sf);
void create_heal_point_mid(variable_t *sf);
void create_heal_point_less_than_mid(variable_t *sf);
void create_heal_point_low(variable_t *sf);
void create_game_over(variable_t *sf);
void create_window_one(variable_t *sf);
void create_text_score(variable_t *sf);
void is_extension_create_texture_and_sprite(variable_t *sf);
void create_texture_and_sprite(variable_t *sf);
void create_heal_point_high(variable_t *sf);
void create_heal_point_more_than_mid(variable_t *sf);
void create_shoot(variable_t *sf);
void create_music(variable_t *sf);
void change_time_text(variable_t *sf);
void create_text_time(variable_t *sf);
void change_time_score(variable_t *sf);
void create_window_two(variable_t *sf);
void create_back(variable_t *sf);
void create_duck(variable_t *sf);
void create_girl_normal(variable_t *sf);
void create_girl_rev(variable_t *sf);
void create_mccree_w_o(variable_t *sf);
void create_robot_w_o(variable_t *sf);
void create_mf_w_o(variable_t *sf);
void create_lucky_luke_w_o(variable_t *sf);
void create_boss_w_o(variable_t *sf);
void create_dalton_w_o(variable_t *sf);
void create_riven_w_o(variable_t *sf);
void create_mccree_two_w_o(variable_t *sf);
void create_cowboy_w_o(variable_t *sf);
void create_jinx_w_o(variable_t *sf);
void create_mccree_w_t(variable_t *sf);
void create_robot_w_t(variable_t *sf);
void create_mf_w_t(variable_t *sf);
void create_lucky_luke_w_t(variable_t *sf);
void create_boss_w_t(variable_t *sf);
void create_dalton_w_t(variable_t *sf);
void create_riven_w_t(variable_t *sf);
void create_mccree_two_w_t(variable_t *sf);
void create_cowboy_w_t(variable_t *sf);
void create_jinx_w_t(variable_t *sf);
void gestion_window_two(variable_t *sf);
void gestion_window_one(variable_t *sf);
void gestion_door_one(variable_t *sf);
void gestion_door_two(variable_t *sf);
void gestion_back(variable_t *sf);
void is_extension_change_heal_point_two(variable_t *sf);
void change_heal_point(variable_t *sf);
void open_window(variable_t *sf);
float rand_pause_window_d_t(variable_t *sf);
float rand_pause_window_b(variable_t *sf);
float rand_person(void);
int rand_duck_x(variable_t *sf);
int rand_duck_y(void);
int rand_ghost_x(void);
float rand_pause_window_o(variable_t *sf);
float rand_pause_window_t(variable_t *sf);
float rand_pause_window_d_o(variable_t *sf);
int is_extension_menu(variable_t *sf);
int menu(variable_t *sf);
int main_second(void);
void option_h(void);
int menu_second(variable_t *sf);
void is_extension_menu_three(variable_t *sf);
void is_extension_menu_close(variable_t *sf);
int is_extension_menu_two(variable_t *sf, int seconds);
void is_extension_menu_ext(variable_t *sf);
void is_extension_main_boucle_four(variable_t *sf);
void is_extension_main_boucle_three(variable_t *sf);
void is_extension_main_boucle_two(variable_t *sf);
void is_extension_main_boucle(variable_t *sf);
void main_boucle(variable_t *sf);
void is_extension_close(variable_t *sf);
void is_close_prog(variable_t *sf);
int is_extension_kill_window_one(variable_t *sf);
int kill_window_one(variable_t *sf);
int is_extension_kill_window_two(variable_t *sf);
int kill_window_two(variable_t *sf);
int is_extension_kill_door_one(variable_t *sf);
int kill_door_one(variable_t *sf);
int kill_door_two(variable_t *sf);
int is_extension_kill_back(variable_t *sf);
int kill_back(variable_t *sf);
void change_cursor_mouse(variable_t *sf);
void put_out_map_ghost(variable_t *sf);
void is_extension_move_ghost(int max_value, variable_t *sf);
void is_extension_move_ghost_three(variable_t *sf);
void is_extension_move_ghost_two(variable_t *sf);
void move_duck(int offset, int max_value, variable_t *sf);
void move_ghost(int offset, int max_value, variable_t *sf);
void is_ext_put_out_map_duck(variable_t *sf);
void put_out_map_duck(variable_t *sf);
void is_extension_move_duck(int max_value, variable_t *sf);
void is_extension_move_duck_two(variable_t *sf);
int is_case_zero(int nbr);
char *my_itoa(int nbr, int neg);
void is_ext_random_choose_person_w_o_w_t(variable_t *sf, int perso_have_choise);
void random_choose_person_w_o_w_t(variable_t *sf);
void is_ext_random_choose_person_w_o(variable_t *sf, int perso_have_choise);
void random_choose_person_w_o(variable_t *sf);
void is_ext_random_choose_person_d_o(variable_t *sf, int perso_have_choise);
void random_choose_person_d_o(variable_t *sf);
void is_ext_random_choose_person_d_t(variable_t *sf, int perso_have_choise);
void random_choose_person_d_t(variable_t *sf);
void random_choose_person_b(variable_t *sf);
void is_ext_random_choose_person_b(variable_t *sf, int perso_have_choise);




#endif