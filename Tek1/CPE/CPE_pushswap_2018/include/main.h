/*
** EPITECH PROJECT, 2018
** main
** File description:
** header of main
*/

#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include "my_list.h"
control_list_t *create_list_control_l_a(control_list_t *l_a, int ac,
    char *av[]);
control_list_t *create_list_control_l_b(control_list_t *l_b);
int check_error_two(int ac);
int check_error_three(int ac);
char *is_init(control_list_t **l_a, char *av[]);
int is_pushswap(control_list_t **l_a, control_list_t **l_b, char *max, int ac);

#endif