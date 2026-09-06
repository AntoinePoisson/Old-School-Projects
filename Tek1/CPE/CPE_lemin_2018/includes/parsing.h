/*
** EPITECH PROJECT, 2018
** parsing.h
** File description:
** all headers of my parsing
*/

#ifndef MY_PARSING_H
# define MY_PARSING_H

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif

#ifndef EXIT_ERROR
# define EXIT_ERROR 84
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "get_next_line.h"
#include "my_struct.h"

int check_end_start_link(variable_t *var);
int failure_parsing(variable_t *var);
int is_extension_management_parsing(variable_t *var, int value_return, int cas,
    int i);
char *select_begin(char *str);
int select_fd(char const *str);
list_t *take_data(void);
char **create_data(variable_t *var);
int pre_analyze(variable_t *var, int *posi_define_nbr_ant);
int management_parsing(variable_t *var, int posi_define_nbr_ant,
    node_t **tab_node);
int final_check(variable_t *var);
int analyze_data_arg(variable_t *var);
int display_parse(variable_t *var, int cas);
int check_same_data(variable_t *var, node_t *element);
int check_error(variable_t *var);
int find_begin(char const *str);
int count_word(char const *str);
int is_room(char const *str);
int create_link(variable_t *var, char const *str);
int is_right_link_room(variable_t *var, char *str);
int is_link_room(char const *str);
int nbr_ants(char const *str);
int management_special_room(variable_t *var, char const *str, int *posi,
    int *cas);
int is_command(variable_t *var, char const *str, int *i);
int select_element_parsing(variable_t *var, char *str, int *i);
node_t **create_tab_node_element(variable_t *var);
int add_node(variable_t *var, char const *str);

#endif
