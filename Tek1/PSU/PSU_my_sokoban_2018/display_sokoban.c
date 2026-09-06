/*
** EPITECH PROJECT, 2018
** display_sokoban
** File description:
** display the game
*/

#include <ncurses.h>

void display_sokoban(char **map, int nb_rows, int nb_cols)
{
    int i = nb_rows;

    nb_rows = (nb_rows / 2) * -1;
    for (; i >= 0; i--, nb_rows++)
        mvprintw((LINES / 2) - (nb_rows), (COLS / 2) - (nb_cols / 2), map[i]);
}
