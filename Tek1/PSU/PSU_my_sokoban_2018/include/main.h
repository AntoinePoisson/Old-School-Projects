/*
** EPITECH PROJECT, 2018
** main_h
** File description:
** main_h
*/

#ifndef MAIN_H
#define MAIN_H

int check_error(int ac, char *av[]);
char **load_map(char const *filepath, int *nb_rows, int *nb_cols);
int count_cols(char *map);
int count_rows(char *map);
int sokoban(char **map, int nb_rows, int nb_cols, char **save);
int check_error_two(char **map, int nb_rows, int nb_cols);
void my_strcpy_2d(char **map, char **save_map, int nb_rows, int nb_cols);
int my_putstr(char const *str);

#endif
