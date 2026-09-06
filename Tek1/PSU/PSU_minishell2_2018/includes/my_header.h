/*
** EPITECH PROJECT, 2019
** my_header.h
** File description:
** header of shell
*/

#ifndef MY_HEADER_H
# define MY_HEADER_H

# include <dirent.h>
# include "my_struct.h"

    /* Built-in */
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
int my_exit(variable_t *var, char *arg_nbr);
int my_cd(variable_t *var);
int my_unsetenv(variable_t *var);
int my_setenv(variable_t *var);
char my_stat(char const *dir, int cas);
int pop(variable_t *var);

    /* Check Error */
int check_error(variable_t *var, char *env[]);
int check_around_operator(char **arg, int i, int nbr_operator);
int check_operator(char const *str);
int check_operator_in_tree(char const *str, int ope);
int compare_charac_and_operator(char const *str, int i, int ope);

    /* Display */
void display(void);
int display_adapt_message_of_wrong_operator(int nbr_operator);

    /* Execution */
int exec_arg(variable_t *var, char *arg);
int test_command_in_path(variable_t const *var);
int search_command_in_path(variable_t *var);
int search_my_command(variable_t *var);
int exec_command_in_path(variable_t *var);
int my_command(variable_t *var);
int is_minishell(variable_t *var);
int exec_simple(variable_t *var);

    /* Operator */
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

#endif