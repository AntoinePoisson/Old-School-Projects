/*
** EPITECH PROJECT, 2018
** LOAD_MAP_H
** File description:
** LOAD_MAP_H
*/

#ifndef LOAD_MAP_H
#define LOAD_MAP_H

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int count_rows(char *map);
int count_cols(char *map);
int count_cols_check(char *map);
void check_error_last_first_line(char **map, int *nb_cols, int *nb_rows);

#endif