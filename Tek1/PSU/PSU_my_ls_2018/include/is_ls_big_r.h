/*
** EPITECH PROJECT, 2018
** is_ls_big_r.h
** File description:
** is_ls_big_r
*/

#ifndef IS_LS_BIG_R_H
#define IS_LS_BIG_R_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my_struct.h"
#include "my_lib.h"

char *month(char *time, int i_two);
void rotation_first(flag_t *flag);
void add_element(flag_t *flag, char *data_element);
void push(flag_t *flag, char *data_element);
void pop(flag_t *flag);
char my_stat(char *av, int, flag_t *flag);
char *is_extension_month_big_r(char *time, int i_two);
char *month(char *time, int i_two);
int analyze(flag_t *flag, int *i, int first);
void display_flag_d(flag_t *flag, int *i);
char *link_directory(char *directory, int nbr, flag_t *flag);
char *find_name(char *file);
void display_flag_l_big_r(flag_t *flag);
void display_flag_d_big_r(flag_t *flag);
int display_file_big_r(flag_t *flag);
int display_error_message_big_r(flag_t *flag);
int create_result_big_r(flag_t *flag, int first);
DIR *is_open_directory_big_two(flag_t *flag, int *nbr);
DIR *is_open_directory_big(flag_t *flag, int *i);
int close_directory_big_r(DIR *dirp);
void save_result_big_r(struct dirent *result, flag_t *flag, int count);
int directory_and_file_big_r(flag_t *flag, int *i);
int first_analyze_big_r(flag_t *flag, int *nbr, int *i);
void display_result_big_r(flag_t *flag);
void display_flag_big_r(flag_t *flag, int *i);
char *is_extension_parce_time_big_r(int *i, int i_two, char *time,
    char *stockage);
char *parce_time_big_r(int *i, char *stockage, char *time);
char *is_extension_sort_time_big_r(flag_t *flag, int i);
int my_strcmp_time_big_r(flag_t *flag, int i_two, int i);
void sort_time_big_r(flag_t *flag);
void sort_time_rev_big_r(flag_t *flag);
void sort_alphabetically_big_r(flag_t *flag);
void sort_alphabetically_rev_big_r(flag_t *flag);
char *is_extension_link_directory(char *directory, char *result);
char *is_extension_link_directory_two(char *directory, flag_t *flag,
    char *result);
char *is_extension_link_directory_three(char *directory, flag_t *flag,
    char *result, int i_two);
char *is_extension_link_directory_four(char *directory, flag_t *flag,
    char *result, int i_two);
char *is_extension_link_directory_five(char *directory, flag_t *flag,
    char *result, int i_two);
char *link_directory(char *directory, int nbr, flag_t *flag);
void check_big_r_element(flag_t *flag);
void check_big_r_elemen_two(flag_t *flag);
void is_extension_is_ls_big_big_r(flag_t *flag);

#endif
