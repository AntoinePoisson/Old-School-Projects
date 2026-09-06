/*
** EPITECH PROJECT, 2019
** my_header.h
** File description:
** header of rpg
*/

#ifndef MY_HEADER_H
#define MY_HEADER_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <SFML/System.h>
# include <SFML/Audio.h>

# include "my_struct.h"

/* Intro */
int malloc_struct(game_t *game);
int create_hitbox_map(game_t *game);
int manage_fade(game_t *game, unsigned short value);
void intro_menu(game_t *game);
void create_intro(game_t *game);
void destroy_intro(game_t *game);
void event_intro(game_t *game, bool *close);
void create_window(game_t *game, bool fullscreen, int size);
int error_gestion(char **env);
int display_help(void);
void init_struct(game_t *game);
char **str_to_word_array(char *str, char c);
int my_strncmp(char const *s1, char const *s2, int const n);
char *create_file1(int *fd, char *file);
char *create_file2(int *fd, char *file);
char **tab_realloc(char **tab);
char **fill_tab(int fd);
void write_in_file(int fd, game_t *game);
void save_file(game_t *game);
void assign_value(int j, char *value, game_t *game);
void init_game_var(game_t *game);

/* Hud */
void attack_player(game_t *game);
void create_hud(game_t *game);
void destroy_hud(game_t *game);
void display_hud(game_t *game);
void display_potion(game_t *game);
void management_hud(game_t *game);

/* Dungeon */
void management_regeneration(game_t *game);
void manage_dungeon_boss(game_t *game);
void add_boss_particle(game_t *game, sfVector2f pos);
void add_boss_projectile(game_t *game, float angle);
void add_projectile_boss(game_t *game, float angle,
projectile_boss_t *projectile);
void check_player_collision(game_t *game, projectile_boss_t *projectile);
bool manage_boss_particle(game_t *game);
void destroy_boss_particle(game_t *game, particle_boss_t *particle);
void display_boss_particle(game_t *game);
void manage_boss_projectile(game_t *game);
void event_attack_boss(game_t *game);
void check_eye_health(game_t *game, enemy_eye_t *enemy);
void check_spider_health(game_t *game, enemy_spider_t *enemy);
void destroy_boss_projectile(game_t *game, projectile_boss_t *projectile);
void display_dungeon_boss(game_t *game);
void check_evil_tick_health(game_t *game, enemy_evil_tick_t *enemy);
void event_hand_to_hand(game_t *game);
void create_items(game_t *game);
void create_dungeon_boss(game_t *game);
void create_donjon_two(game_t *game);
void management_item(game_t *game);
int management_hitbox_donjon(game_t *game, sfVector2f posi);
bool in_radius(sfVector2f pos1, sfVector2f pos2, unsigned int radius);
int ratio_mob_player(game_t *game, sfVector2f mob);
bool check_enemy_collision(game_t *game, projectile_spell_t *tmp);
void destroy_spell_projectile(game_t *game, projectile_spell_t *projectile);
void add_spell_particle(game_t *game, sfVector2f pos);
void add_enemy_spider(game_t *game, sfVector2f pos);
void add_enemy_evil_tick(game_t *game, sfVector2f pos);
void display_enemy_spider(game_t *game);
void display_enemy_evil_tick(game_t *game);
void display_enemy_eye_bomb(game_t *game);
void manage_enemy_eye_bomb(game_t *game);
void manage_enemy_evil_tick(game_t *game);
void manage_enemy_spider(game_t *game);
void add_enemy_eye_bomb(game_t *game, sfVector2f pos);
void manage_footsteps_sound(game_t *game);
void destroy_enemy_eye(game_t *game, enemy_eye_t *enemy);
void destroy_enemy_spider(game_t *game, enemy_spider_t *enemy);
void destroy_enemy_evil_tick(game_t *game, enemy_evil_tick_t *enemy);
void display_enemy_eye(game_t *game);
void manage_enemy_eye(game_t *game);
void add_enemy_eye(game_t *game, sfVector2f pos);
void reset_dungeon_view(game_t *game);
void create_donjon(game_t *game);
void destroy_donjon(game_t *game);
void display_donjon(game_t *game);
void management_donjon(game_t *game);
void set_string_stats(game_t *game);
void check_eye_health(game_t *game, enemy_eye_t *enemy);
void check_spider_health(game_t *game, enemy_spider_t *enemy);
void check_evil_tick_health(game_t *game, enemy_evil_tick_t *enemy);
void create_donjon_other_things(game_t *game);
void create_dungeon_sound(game_t *game);
void event_key_right_dungeon(game_t *game);
void event_key_left_dungeon(game_t *game);
void event_key_down_dungeon(game_t *game);
void event_key_up_dungeon(game_t *game);
void skip_text_dialog(game_t *game);
void skip_dialog(game_t *game, bool pos_text);
void create_dungeon_enemy(game_t *game);
void play_sword_sound(game_t *game, bool which);
void manage_boss_fireball(game_t *game, bool *change_pos,
float *angle, short *times);
void manage_boss_spawn_enemies(game_t *game);
void manage_head(game_t *game, bool *change_pos,
float *angle, short *times);
void manage_head_two(game_t *game, bool *change_pos,
float *angle, short *times);
void manage_head_first(game_t *game, bool *change_pos,
float *angle, short *times);

/* Settings menu */
void is_extension_create_set_loop(game_t *game);
void set_vsync_button(game_t *game, sfVector2f *vsync_pos);
void set_full_button(game_t *game, sfVector2f *full_pos);
void set_size4_button(game_t *game, sfVector2f *size4_pos);
void set_size3_button(game_t *game, sfVector2f *size3_pos);
void set_size2_button(game_t *game, sfVector2f *size2_pos);
void set_size1_button(game_t *game, sfVector2f *size1_pos);
void menu_exit_button(game_t *game, sfVector2f *exit_pos);
void menu_score_button(game_t *game, sfVector2f *score_pos);
void menu_htp_button(game_t *game, sfVector2f *htp_pos);
void menu_set_button(game_t *game, sfVector2f *set_pos);
void menu_play_button(game_t *game, sfVector2f *play1_pos);
void draw_set_loop(game_t *game);
void create_set_loop(game_t *game);
void set_loop(game_t *game);
void change_sprite_set_menu(game_t *game);
void third_states_buttons_set_menu(game_t *game);
void click_buttons_set_menu(game_t *game);
void set_pos_scale_set_menu(game_t *game);
void follow_cursor(game_t *game);
void change_fullscreen(game_t *game, sfVector2f full_pos);
void scale_resize(game_t *game);
void reset_ratio(game_t *game, int which_one);
void create_music_but(game_t *game);
void event_clik_music_but(game_t *game);
void click_music_but(game_t *game);

/* Pause game */
void pause_game_loop(game_t *game);
void pause_game_donjon(game_t *game);
void draw_buttons_pause(game_t *game);
void draw_pause_game_loop(game_t *game);
void draw_pause_donjon(game_t *game);
void create_pause(game_t *game);
void set_pos_pause(game_t *game);
void click_buttons_pause(game_t *game);
void state_buttons_pause(game_t *game);

/* Main menu */
void draw_play(game_t *game);
void draw_set(game_t *game);
void draw_htp(game_t *game);
void draw_exit(game_t *game);
void draw_high_score(game_t *game);
int create_orientation_player(game_t *game);
void display_particle(game_t *game);
int manage_particle(game_t *game);
void add_particle(game_t *game, int nb);
void initialize_menu_vars(game_t *game);
void event_menu(game_t *game);
void event_move_mouse(game_t *game);
int main_menu(game_t *game);
int create_main_menu(game_t *game);
void destroy_main_menu(game_t *game);
void draw_buttons_main_menu(game_t *game);
void click_buttons_main_menu(game_t *game);
void game_loop(game_t *game);
void draw_main_menu(game_t *game);
void third_states_buttons_main_menu(game_t *game);
void set_pos_scale_main_menu(game_t *game);
void create_texture_main_menu(game_t *game);
void create_sprite_main_menu(game_t *game);
void size_1920(game_t *game);
void size_1664(game_t *game);
void size_1280(game_t *game);
void key_bindings(game_t *game);

/* Choose chara menu */
void choose_chara_menu(game_t *game);
void draw_chara_menu(game_t *game);
void create_chara_menu(game_t *game);
void change_text_chara_menu(game_t *game);
void color_rect_choose_chara_menu(game_t *game);
void click_choose_chara_menu(game_t *game);
void create_rectangle_shape_chara_menu(game_t *game);
void create_text_chara_menu(game_t *game);

/* Game loop */
int check_leave_donjon(game_t *game);
void leave_donjon(game_t *game);
void check_actual_posi_player(game_t *game);
void management_trap(game_t *game);
int control_move_player(game_t *game, int cas);
float difference_angle(sfVector2f obj, sfVector2f obj_two);
bool manage_spell_particle(game_t *game);
void manage_rain_particle(game_t *game);
void display_rain_particle(game_t *game);
void add_rain_particle(game_t *game, int nb, bool init);
void add_spell_projectile(game_t *game);
void game_loop(game_t *game);
void create_game_loop(game_t *game);
void create_sprite_set_loop(game_t *game);
void create_texture_set_loop(game_t *game);
void create_text_set_loop(game_t *game);
void create_player(game_t *game);
void event_game_loop(game_t *game);
void event_key_shift_right(game_t *game);
void event_key_shift_left(game_t *game);
void event_key_shift_up(game_t *game);
void event_key_shift_down(game_t *game);
void event_view_shift_right(game_t *game);
void event_view_shift_left(game_t *game);
void event_view_shift_up(game_t *game);
void event_view_shift_down(game_t *game);
void check_pos_player_to_dialog(game_t *game);
void manage_spell_projectile(game_t *game);
void display_spell_particle(game_t *game);
void event_spell(game_t *game);
void create_dialog_hud(game_t *game);
void launch_dialog(game_t *game);
void skip_text_dialog(game_t *game);
void create_inventory(game_t *game);
void set_pos_inventory(game_t *game);
void create_stats(game_t *game);
void set_pos_text_stats(game_t *game);
bool check_combat_boss(game_t *game, sfVector2f player_pos);
bool check_combat_evil_tick(game_t *game, sfVector2f player_pos);
bool check_combat_spider(game_t *game, sfVector2f player_pos);
bool check_combat_eye(game_t *game, sfVector2f player_pos);

/* Display */
void display_beach(game_t *game);
void destroy_rain_particle(game_t *game, rain_particle_t *particle);
void destroy_particle(game_t *game, menu_particle_t *particle);
void print_inventory(game_t *game);
void event_open_inventory(game_t *game);
void evt_released_key(game_t *game);
void display_text_end_game(game_t *game);

/* HTP loop */
void create_htp(game_t *game);
void htp_loop(game_t *game);

/* Personnage */
void save_file(game_t *game);
void use_potion(game_t *game);
void fill_tab_orientation_player_two(game_t *game);
void fill_tab_orientation_player(game_t *game);
void management_orientation_player(game_t *game);
int check_move_perso(game_t *game, sfVector2f perso, int cas);
void event_move(game_t *game);

/* High Score */
void display_highscore(game_t *game);
int create_file_of_highsocre(game_t *game);
int is_ext_analy_file(int *nbr, int *count_separator);
char *data_highscore_file(int cas);
int check_file_highscore(void);
char *decrypt_highscore(char *dec);
char *dec_to_char(char *dec);
char *char_to_dec(char *nbr);
int open_file_highscore(void);
int analyse_file(char *file, int nbr);
int compare_data(char *data, int score, int count, int final_result);
char *is_extension_compare_score(char *data, char *file, int *i_two);
int compare_score(int score, int level, int bird);
int management_highscore(game_t *game, int cas);
void create_high_score(game_t *game);
void high_score_loop(game_t *game);

/* Skill */
int random_skill(game_t *game);
skill_t *random_skill_(game_t *game);
void display_skill_tree_text(game_t *game, skill_t *one, skill_t *two);
void display_skill_tree(game_t *game, skill_t *one, skill_t *two);
void player_input(game_t *game, int *choose);
void fill_struct_skill(game_t *game, skill_t *result);
void make_choose(game_t *game);
void transition_game_to_skill(game_t *game, sfSprite *sprite);
void choose_skill(game_t *game);
void check_choose_skill(game_t *game);
void resusite_player(game_t *game, int element);
void more_hp(game_t *game, int element);
void more_mana(game_t *game, int element);
void more_armor(game_t *game, int element);
void incremente_mana(game_t *game, int element);
void incremente_hp(game_t *game, int element);
void deal_more_dmg(game_t *game, int element);
void gain_more_xp(game_t *game, int element);
void restaure_potion(game_t *game, int element);
void go_to_the_end(game_t *game, int element);
int research_skill(game_t *game, int element);
void create_sprite_of_skill(game_t *game);
void check_choose_skill(game_t *game);
void management_skill(game_t *game, int nbr);
void display_skill(game_t *game);
void create_skill(game_t *game);

/* library */
char *my_strcat(char *dest, char *src);
char *my_itoa(int nbr, int cas);
int my_getnbr(char *);
char *my_strcat_charac(char *dest, char const *src);
char *get_next_line(int fd);
void *my_malloc(size_t size, int fill);
void my_putchar(char c);
int my_atoi(char const *str);
int my_putstr(char const *str);
int my_puterror(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strdup(char const *str);

#endif
