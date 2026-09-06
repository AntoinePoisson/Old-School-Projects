/*
** EPITECH PROJECT, 2019
** my_prototypes.h
** File description:
** prototypes of all project functions
*/

#ifndef MY_PROTOTYPES_H
#define MY_PROTOTYPES_H

char **cp_two_d(char **str);
int find_color_of_charac(options_t *opt, char charac);
int check_usr_input(options_t opt, time_t *stack);
int managemet_display_tetris(options_t *opt, time_t *stack,
    WINDOW *board, info_t info);
char **create_border(options_t *opt);
int take_obj_random(options_t *opt);
void fall_block(options_t *opt);
int move_down(options_t *opt);
int move_right(options_t *opt);
int move_left(options_t *opt);
bool check_move(options_t *opt, char **plan, int x, int y);
bool check_move_left(options_t *opt, char **plan);
bool check_move_right(options_t *opt, char **plan);
bool check_move_down(options_t *opt, char **plan);
void change_select_obj(options_t *opt);
int insert_obj(options_t *opt, char **tetrimino);
int kill_line(options_t *opt, int line);
int check_kill_line(options_t *opt);

int wait_input(void);
int set_newterm(void);
int tetris_title(void);
int init_colors(void);
int disp_key_bindings(char const *str, char *key);
int help_opt(char const *binary);
int calcul_row(int *col, char **str);
void is_extension_main_loop(info_t *info, time_t stack);
int swap_node(tetrimino_t **one, tetrimino_t **two);
int display_debug_mode_file_part(options_t *opt);
void sort_alphabetically(options_t *opt);
int free_node(options_t *opt);
int init_screen(void);
int is_extension_calcul_row(char **str, int *i, int *find_block);
int take_data(options_t *opt, char *name);
int color_of_charac(options_t *opt, char charac);
int control_right_file(char **str, int cas);
int display_file_data(tetrimino_t *tetris);
int display_name_file(tetrimino_t *tetris);
int size_list(options_t *opt);
int stat_size(char const *filepath);
int add_node(options_t *opt);
int tetris(char const **av);
int help_opt(char const *binary);
int debug_tetriminos(options_t *opt, int cas);
int analyze_flags_opt(char const **av, options_t *opt);
int check_tetriminos(void);
int is_level_opt(char const **av, options_t *opt, int *a);
int is_others_opt(char const **av, options_t *opt, int a);
int is_map_size_opt(char const **av, options_t *opt, int *a);
int is_key_opt(char const **av, options_t *opt, int *a);
int debug_mode(options_t *opt);
int read_file_info(options_t *opt, DIR *folder);
bool check_right_extension(char const *name);
char *change_name_of_file(char *name);
char **init_map(options_t *opt);
info_t init_info(options_t opt);
options_t init_opt(void);

#endif
