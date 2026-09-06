/*
** EPITECH PROJECT, 2019
** my_header.h
** File description:
** header of shell
*/

#ifndef MY_HEADER_H
# define MY_HEADER_H

# include <stdio.h>
# include <dirent.h>
# include <time.h>
# include <stdbool.h>

# include <curses.h>
# include <unctrl.h>
# include <termios.h>
# include <ncurses.h>

# include "my_struct.h"

    /* Built-in */
int exec_my_alias(variable_t *var);
int check_flag_cd(char const *arg);
int check_error_my_unsetenv(variable_t const *var);
int research_env(variable_t *var, char const *str, int *i);
int push(variable_t *var, char const *str);
int is_extension_change_value_env(variable_t *var, char *result);
int change_value_env(variable_t *var, char const *element, char const *data);
char *find_env(variable_t *var, char const *str);
void change_env(variable_t *var);
int is_extension_check_error_cd(variable_t *var, int *i);
DIR *is_extension_check_error_cd_two(variable_t *var, int i);
int check_permission(char const *dir);
int cd_flag_back(variable_t *var);
int display_env(variable_t const *var);
int my_exit(variable_t *var, char *arg_nbr, int print_message);
int my_cd(variable_t *var);
int my_echo(variable_t *var);
int my_unsetenv(variable_t *var);
int my_setenv(variable_t *var);
char my_stat(char const *dir, int cas);
int pop(variable_t *var);

    /* Check Error */
char *check_parentheses(char *arg);
int check_error(variable_t *var, char *env[]);
int check_around_operator(char **arg, int i, int nbr_operator);
int check_operator(char const *str);
int check_operator_in_tree(char const *str, int ope);
int compare_charac_and_operator(char const *str, int i, int ope);

    /* Display */
void display(void);
int display_adapt_message_of_wrong_operator(int nbr_operator);

    /* Alias */
char *control_alias(variable_t *var, char *arg);
int is_initialization_alias(variable_t *var);
void is_extension_rework_line_(char *line, int *i, int *size);
char *is_extension_rework_line(char *line);
char *rework_line(char *line);
char *cpy_alias(char *alias, char *arg);
int check_alias(char *alias, char *arg);

    /* Execution */
int exec_arg(variable_t *var, char *arg);
int test_command_in_path(variable_t const *var);
int search_command_in_path(variable_t *var);
int search_my_command(variable_t *var);
int exec_command_in_path(variable_t *var);
int my_command(variable_t *var);
int is_minishell(variable_t *var);
int exec_simple(variable_t *var);

    /* Globbing /inhibitor*/
char *find_backslash(char *str);
char *change_backslash(char *str);
char **find_globbing(char **tab);
char **edit_tab(glob_t **list, char **tab, int i);
void find_char(glob_t **list, char *str, int j);
void globbing_hook(glob_t **list, char *str, int i);
void globbing_star(glob_t **list, char *str, int i);
void globbing_qmark(glob_t **list, char *str, int i);
glob_t *open_all_dir(char *str);
char *find_path(char *str);
char *last_word(char *str, char c);

    /* Operator */
int control_parentheses(variable_t *var, tree_t *tree);
int control_double_ampersand(variable_t *var, tree_t *tree);
int control_double_pipe(variable_t *var, tree_t *tree);
int check_right_operator(char **arg);
int control_right_chevron(variable_t *var, tree_t *tree);
int control_double_right_chevron(variable_t *var, tree_t *tree);
int control_semicolon(variable_t *var, tree_t *tree);
int control_left_chevron(variable_t *var, tree_t *tree);
int control_double_left_chevron(variable_t *var, tree_t *tree);
int control_pipe(variable_t *var, tree_t *tree);
int chose_good_operator(variable_t *var, tree_t *tree);
int is_operator(variable_t *var);
int check_element_is_operator(tree_t *tree);

    /* Binary Tree | Parser LL */
tree_t *is_create_tree(tree_t *tree);
int is_create_root_tree(variable_t *var);
tree_t *is_initialisation_tree(tree_t *tree);
char *purge_name_file(char const * file);

    /* Management Failure Execution */
int check_echec_exec(variable_t *var, int signal, int wstatus);
int research_signal(int signal, int w);
int research_signal_two(int signal, int w);
int research_signal_three(int signal, int w);
int research_signal_ext_one(int signal, int w);
int research_signal_ext_two(int signal, int w);
int check_type_bin(variable_t const *var);
int print_signal(char const *str, int wstatus);
int display_error_fork(int cas, char const *file);

    /* Free */
void destroy_arg_two_d(variable_t *var);
int destroy_env(variable_t *var);

    /* Tool */
char *control_alias(variable_t *var, char *arg);

    /* History */
history_t *add_to_history(history_t *history, char const *cmd, bool reset);
int display_history(history_t *history, char flag, int nb);
int my_history(history_t *history, char **args, bool *reset);
int clean_history(history_t **history);

char *auto_completion(char *str);
char *get_cmd(char **env, history_t *history);
char *get_term(char **env);
int new_term(struct termios *save, struct termios *newt, char **env);
int clear_scr(char **cmd);
int null_touch(char **cmd);
int del_char(char **cmd);
int del_line(char **cmd);
int auto_comp(char **cmd);
int call_termcap(char const *str);

void loop_print_single(variable_t *var, int a, int *b);
void loop_print_double(variable_t *var, int a, int *b);
int check_single_cote(variable_t *var);

/* Backticks */
char *clean_str(char *str);
char *file_to_str(char const *filepath);
void free_array(char **array);
char **my_realloc_array(char **array, char *str);
char *my_strcat_with_char(char *dest, char *src, char c);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int exec_backticks(variable_t *var, char *arg, int fd);
bool my_str_has_backtick(char *str);
char *backticks(char *str, variable_t *var);
int create_file(char const *file, int *fd);
bool nb_backticks_is_even(char *str);
char *get_str_between_backticks(char *str);
bool my_str_has_backtick(char *str);
bool my_str_starts_with_backtick(char *str);
bool my_str_finish_with_backtick(char *str);
char *test(int *i, char **array);
char **new_array(char **array);
char *replace_backslash_n_with_spaces(char *str);
char *get_str_file(variable_t *var, int fd, char *array_i);
char *backticks(char *str, variable_t *var);

#endif
