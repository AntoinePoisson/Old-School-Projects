/*
** EPITECH PROJECT, 2018
** lem_in.h
** File description:
** all headers of my lem_in
*/

#ifndef MY_LEM_IN_H
# define MY_LEM_IN_H

#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"
#include "get_next_line.h"
#include "my_struct.h"

int research_recurrence(int **tab, path_t *posi, int new_index);
int check_move_forward(variable_t *var, path_t *posi, int *cas);
path_t *move_forward(path_t *posi, int new_posi);
path_t *move_back(variable_t *var, path_t *posi);
int get_index(variable_t *var, node_t *room);
int check_end_algo(variable_t *var, path_t *posi);
int check_complete_path(variable_t *var, path_t *posi, int *cas);
path_t *complete_path(variable_t *var, path_t *posi);
int comparation_recurrence(int **tab, path_t *save, int i, int new_index);
int count_element_path(path_t *path);
int **sort_array(int **);
int move_ants(int , int **, variable_t *);
int initialization_algo(variable_t *var);
path_t *reverse_list(path_t *path);
int **convert_list(int **tab, path_t *path);
int get_index(variable_t *var, node_t *room);
int check_end_algo(variable_t *var, path_t *posi);
int check_complete_path(variable_t *var, path_t *posi, int *cas);
path_t *complete_path(variable_t *var, path_t *posi);
int comparation_recurrence(int **tab, path_t *save, int i, int new_index);
int research_recurrence(int **tab, path_t *posi, int new_index);
int check_move_forward(variable_t *var, path_t *posi, int *cas);
path_t *move_forward(path_t *posi, int new_posi);
path_t *move_back(variable_t *var, path_t *posi);
int find_all_path(variable_t *var);
int display_parse(variable_t *var, int cas);
path_t *add_element_path(path_t *path, int index);
path_t *delete_element_path(path_t *path);
int count_element_path(path_t *path);
int check_error(variable_t *var);
int analyze_data_arg(variable_t *var);
int algo(variable_t *var);
int main_bis(int ac, char **av);
int tab_len(int **arr);
int **my_realloc_tab_int(int **arr);
int **convert_list(int **tab_path, path_t *path);
void disp(int ant, char *movement);
int nbr_ants(char const *str);
int simple_path(int ants, int *path, variable_t *var);
void is_extension_simple_path(int *print, int *path, int a, int cas);
int last_room(anthill_t anthill[], int *path, int ants);
#endif
