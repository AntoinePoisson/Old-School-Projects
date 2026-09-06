/*
** EPITECH PROJECT, 2018
** is_sokoban
** File description:
** core of sokoban
*/

#include "is_sokoban.h"

int game_is_finish(char **map, int nb_rows, char **save)
{
    int nb_cols = 0;
    int nb_o = 0;

    for (int i = 0; map[0][i] != '\n'; i++, nb_cols++);
    for (int i = 0; i <= nb_rows; i++)
        for (int i_two = 0; i_two <= nb_cols; i_two++)
            if (save[i][i_two] == 'O')
                if (map[i][i_two] != 'X') {
                    nb_o++;
                }
    return (nb_o);
}

int sokoban(char **map, int nb_rows, int nb_cols, char **save)
{
    int reset = 1;

    initscr();
    curs_set(0);
    keypad(stdscr, 1);
    while (reset) {
        my_popup(nb_rows, nb_cols);
        clear();
        display_sokoban(map, nb_rows, nb_cols);
        refresh();
        reset = gestion_move(map, nb_rows);
        if (reset == 0 || reset == 1)
            break;
        control_o(map, nb_rows, nb_cols, save);
        reset = game_is_finish(map, nb_rows, save);
        if (reset == 0)
            break;
        reset = control_x_check_block(map, nb_rows, nb_cols);
        if (reset == 5)
            break;
    }
    endwin();
    return (reset);
}
