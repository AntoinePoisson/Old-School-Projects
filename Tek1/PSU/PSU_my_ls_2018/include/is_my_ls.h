/*
** EPITECH PROJECT, 2018
** is_my_ls.h
** File description:
** is_my_ls
*/

#ifndef IS_MY_LS_H
#define IS_MY_LS_H

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

char my_stat(char *av, int, flag_t *flag);
int normal_ls_big_r(flag_t *flag);
void display_flag_big_r(flag_t *flag, int *i);
char *link_directory(char *directory, int nbr, flag_t *flag);
void display_flag_l(flag_t *flag);
void display_flag_d(flag_t *flag, int *i);
int display_file(flag_t *flag, int *i);
int display_error_message(flag_t *flag);
int create_result(flag_t *flag, int first);
DIR *is_open_directory_two(flag_t *flag, int *nbr);
DIR *is_open_directory(flag_t *flag, int *i);
int close_directory(DIR *dirp);
void save_result(struct dirent *result, flag_t *flag, int count);
int directory_and_file(flag_t *flag, int *i);
int first_analyze(flag_t *flag, int *nbr, int *i);
void display_result(flag_t *flag, int first, int *i);
char *is_extension_month(char *time, int i_two);
char *month(char *time, int i_two);
char *is_extension_parce_time(int *i, char *stockage, char *time, int i_two);
char *parce_time(int *i, char *stockage, char *time);
char *is_extension_sort_time(flag_t *flag, int i);
int my_strcmp_time(flag_t *flag, int i_two, int i);
void sort_time(flag_t *flag);
void sort_time_rev(flag_t *flag);
void sort_alphabetically(flag_t *flag);
void sort_alphabetically_rev(flag_t *flag);
void is_extension_analyze(flag_t *flag);
int analyze(flag_t *flag, int *i, int first);

#endif
