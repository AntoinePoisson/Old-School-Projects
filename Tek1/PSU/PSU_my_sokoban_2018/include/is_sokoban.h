/*
** EPITECH PROJECT, 2018
** is_sokoban
** File description:
** is_sokoban
*/

#ifndef IS_SOKOBAN_H
#define IS_SOKOBAN_H

#include <ncurses.h>
#include <curses.h>

void display_sokoban(char **map, int nb_rows, int nb_cols);
int gestion_move(char **map, int nb_rows);
int my_popup(int nb_rows, int nb_cols);
int control_x_check_block(char **map, int nb_rows, int nb_cols);
void control_o(char **map, int nb_rows, int nb_cols, char **save);
int research_perso(char **map, int *x, int *y, int nb_rows);
int count_nbr_x(char **map, int nb_rows, int nb_cols);

#endif
