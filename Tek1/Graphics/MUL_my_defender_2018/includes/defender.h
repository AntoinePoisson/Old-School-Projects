/*
** EPITECH PROJECT, 2019
** my_defender.c
** File description:
** all headers of my defender
*/

#ifndef MY_DEFENDER_H
#define MY_DEFENDER_H

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif

#ifndef EXIT_ERROR
# define EXIT_ERROR 84
#endif

# include "my_struct.h"
# include "csfml.h"
# include "my_lib.h"

# define PI 3.14159265

# define REPERATION_BUILD_COST 250

# define HDV_HP 620

# define WALL_HP 240
# define WALL_COST 2

# define BOMBE_SPEED_ANIMATION_ATTACK 50
# define BOMBE_HP 100
# define BOMBE_DMG 40
# define BOMBE_COST 6
# define BOMBE_SPEED_DMG 150

# define TRANP_SPEED_ANIMATION_ATTACK 45
# define TRANP_RANG 50
# define TRANPOLINE_HP 100
# define TRANPOLINE_DMG 999999
# define TRANPOLINE_COST 4
# define TRANPOLINE_SPEED_DMG 110

# define ENEMY_SLOW_ANIMATION 10
# define ENEMY_SLOW_ANIMATION_ATTACK 3
# define ENEMY_SPEED 1
# define ENEMY_SPEED_DMG 30
# define ENEMY_DMG 20
# define ENEMY_HP 145
# define ENEMY_GOLD 5
# define ENEMY_NBR 5

# define CANNON_DMG 4
# define CANNON_SPEED_DMG 10
# define CANON_COST 20
# define CANNON_HP 80
# define CANNON_RANG 180

# define GOLD 100

# define WAIT_WAVE 2000

int is_ext_management_enemy_move(enemy_t *element);
void create_end_level(variable_t *sf);
int compare_score(int score, int level, int bird);
int write_file(char *score, char *level, char *bird);
void is_extension_is_second_menu(variable_t *sf);
int select_on_quit(variable_t *sf);
int control_display(obj_t *save, int count, int i, variable_t *sf);
void life_restauration_tranpoline(build_t *save);
void cooldown_tranpoline(build_t *save, int cas);
void management_animation_attack_tranpo(build_t *save);
void is_extension_management_bombe(variable_t *sf, int cas);
int is_extension_second_menu(variable_t *sf);
int is_ext_analy_file(int *nbr, int *count_separator);
void is_extension_transition_end_game(variable_t *sf, int *i);
void is_extension_display_build(variable_t *sf, obj_t *save, int count);
void gestion_tranpoline(build_t *save);
void create_board_time(variable_t *sf);
void management_wave(variable_t *sf);
void management_enemy_attack(enemy_t *element);
sfVector2f move_enemy(variable_t *sf, enemy_t *save);
int dead_build(build_t *save);
int dmg_po(int posi, int x);
int take_limit_enemy_attack(enemy_t *element);
void management_enemy_move(enemy_t *element);
enemy_t *is_direction_enemy(variable_t *sf, enemy_t *element);
int take_position_enemy_sprite_two(int *start, int posi);
int take_position_enemy_sprite_one(int posi);
void find_coef(variable_t *sf, enemy_t **element);
sfVector2f management_spawn_enemy(int i);
sfIntRect find_tool_effet_posi_two(int id, sfVector2f *posi, int cas,
    sfIntRect rect);
sfIntRect find_tool_effet_posi_(int id, sfVector2f *posi, int cas,
    sfIntRect rect);
sfIntRect find_tool_effet_posi(int id, sfVector2f *posi, int cas,
    sfIntRect rect);
void display_effet(variable_t *sf);
int is_extension_control_money(variable_t *sf, int cas);
sfIntRect is_extension_find_rect(variable_t *sf, int cas, sfIntRect save);
int is_extension_control_hitbox_place(build_t *save, sfIntRect rect,
    sfVector2i posi, int i);
void add_hdv(variable_t *sf, sfVector2f posi);
void add_wall(variable_t *sf, sfVector2f posi);
void add_bombe(variable_t *sf, sfVector2f posi);
void add_cannon(variable_t *sf, sfVector2f posi);
void add_tranpoline(variable_t *sf, sfVector2f posi);
void management_bombe(variable_t *sf, build_t *save);
sfIntRect check_rect(variable_t *sf, sfIntRect rect, sfVector2i mouse);
int control_money(variable_t *sf);
int click_in_map(sfVector2i posi);
void display_range(variable_t *sf, sfVector2i posi);
void management_select_game_tool(variable_t *sf, sfVector2f posi);
void change_cursor(variable_t *sf, int status);
int reparation_build(variable_t *sf);
void display_help_in_game(variable_t *sf);
void create_board_time(variable_t *sf);
int accelerer_time(variable_t *sf);
int check_hp(int id, int hp);
int count_nbr_enemy(variable_t *sf);
int find_selec_game_tool(sfVector2f posi, variable_t *sf, int cas);
void end_game(variable_t *sf);
void management_enemy(variable_t *sf);
float calcul_angle(int hdv_x, int hdv_y, int x, int y);
void fix_attack_cancel(enemy_t *element);
void display_hp(variable_t *sf);
void management_trap(variable_t *sf);
char *my_itoa(int nbr, int neg);
void find_shoot(variable_t *sf);
void management_wave(variable_t *sf);
void is_destroy_enemy(variable_t *sf);
void is_create_enemy(variable_t *sf);
sfVector2f move_enemy(variable_t *sf, enemy_t *save);
void display_enemy(variable_t *sf, int cas);
sfIntRect find_rect(variable_t *sf);
int check_multiple_hdv(variable_t *sf);
void display_game(variable_t *sf);
void refresh_game(variable_t *sf, float seconds);
int destroy_game(variable_t *sf);
void pause_game(variable_t *sf);
void management_click(variable_t *sf, int click);
void management_mouse(variable_t *var);
int check_right_event(variable_t *var);
void management_event(variable_t *var);
void create_hdv(variable_t *var);
void create_bg_game(variable_t *sf);
void is_initialization(variable_t *sf);
int is_create_game(variable_t *sf);
int is_defender(variable_t *sf);
int control_hitbox_mouse(variable_t *sf, sfVector2i posi);
int control_hitbox_place_build(variable_t *sf, sfVector2i posi);
void add_element_list(variable_t *sf, data_t *element, int id);
void add_element_list_build(variable_t *sf, data_t *element, int id);
void add_hdv(variable_t *sf, sfVector2f posi);
void add_build(variable_t *sf, sfVector2f posi, int click);

#endif
