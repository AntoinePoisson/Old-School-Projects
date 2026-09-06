/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** init_screen.c
*/

#include "my_tetris.h"

int init_colors(void)
{
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);
    init_pair(9, COLOR_GREEN, COLOR_BLACK);
    init_pair(10, COLOR_BLUE, COLOR_BLACK);
    init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(12, COLOR_RED, COLOR_BLACK);
    init_pair(13, COLOR_YELLOW, COLOR_BLACK);
    init_pair(14, COLOR_WHITE, COLOR_BLACK);
    return (0);
}

int init_screen(void)
{
    initscr();
    noecho();
    cbreak();
    start_color();
    init_color(COLOR_WHITE, 1000, 1000, 1000);
    init_colors();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    return (0);
}
