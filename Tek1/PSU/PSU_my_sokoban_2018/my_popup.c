/*
** EPITECH PROJECT, 2018
** my_popup
** File description:
** my_popup
*/

#include "my_popup.h"

int my_popup(int nb_rows, int nb_cols)
{
    char *too_small_x = "The window is too small";
    int size = my_strlen(too_small_x);
    int a = 0;

    initscr();
    move(size, nb_cols);
    while ((COLS + 1 < nb_cols) || (LINES < nb_rows)) {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (size / 2), too_small_x);
        refresh();
        if (getch() == 'q') {
            a = 1;
            break;
        }
    }
    endwin();
    return (a);
}
