/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** loop_display.c
*/

#include "my_tetris.h"

int tetris_title(void)
{
    attrset(COLOR_PAIR(9));
    printw(" *** *** *** *** * *** \n");
    attrset(COLOR_PAIR(10));
    printw("  *  *    *  * * * *   \n");
    attrset(COLOR_PAIR(11));
    printw("  *  **   *  **  * *** \n");
    attrset(COLOR_PAIR(12));
    printw("  *  *    *  * * *   * \n");
    attrset(COLOR_PAIR(13));
    printw("  *  ***  *  * * * *** \n\n\n\n\n");
    attrset(COLOR_PAIR(14));
    return (EXIT_SUCCESS);
}

void is_extension_main_loop(info_t *inf, time_t stack)
{
    tetris_title();
    printw(" /---------------------\\\n | Hight Score    %s |",
        inf->hightscore);
    printw("\n | Score             %d |\n", inf->score);
    if (inf->lines < 10)
        printw(" | Lines            0%d |\n", inf->lines);
    else
        printw(" | Lines            %d |\n", inf->lines);
    if (inf->level < 10)
        printw(" | Level            0%d |\n", inf->level);
    else
        printw(" | Level            %d |\n", inf->level);
    if ((inf->min = (time(NULL) - stack) / 60) < 10)
        printw(" | Timer         0%d:", inf->min);
    else
        printw(" | Timer         %d:", inf->min);
    if ((inf->sec = (time(NULL) - stack) % 60) < 10)
        printw("0%d |\n \\---------------------/\n", inf->sec);
    else
        printw("%d |\n \\---------------------/\n", inf->sec);
}
