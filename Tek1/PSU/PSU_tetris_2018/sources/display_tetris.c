/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris.c
*/

#include <dirent.h>
#include "my_tetris.h"

int color_of_charac(options_t *opt, char charac)
{
    if (charac >= '0' && charac <= '9')
        return (charac - '0');
    if (charac == ' ')
        return (14);
    if (charac == 'x')
        return (opt->obj->tetri->color);
    return (14);
}

void management_input_action_tetris(options_t *opt)
{
    char buf[2] = {'\0'};
    char key[3] = {opt->keys.left[0], opt->keys.right[0], opt->keys.drop[0]};

    if (read(0, buf, 2) <= 0)
        return;
    if ((buf[0] == 'D' || buf[0] == key[0]) && check_move_left(opt, opt->plan))
        move_left(opt);
    if ((buf[0] == 'C' || buf[0] == key[1]) && check_move_right(opt, opt->plan))
        move_right(opt);
    if ((buf[0] == 'B' || buf[0] == key[2]) && check_move_down(opt, opt->plan))
        move_down(opt);
}

void display_tetris(options_t *opt, info_t info, WINDOW *board,
    time_t stack)
{
    wprintw(board, opt->border[0]);
    for (int a = 0; opt->plan[a]; a++) {
        if (opt->border[a + 1])
            wprintw(board, "%c", opt->border[a + 1][0]);
        for (int i = 0; opt->plan[a][i]; i++) {
            wattrset(board, COLOR_PAIR(color_of_charac(opt, opt->plan[a][i])));
            if (opt->plan[a][i] != ' ')
                wprintw(board, "%c", '*');
            else
                wprintw(board, "%c", ' ');
        }
        wattrset(board, COLOR_PAIR(14));
        if (opt->border[a + 1])
            wprintw(board, "%c", opt->border[a + 1][opt->size.col + 1]);
    }
    wprintw(board, opt->border[opt->size.row + 1]);
    wattrset(board, COLOR_PAIR(14));
    is_extension_main_loop(&info, stack);
}

int managemet_display_tetris(options_t *opt, time_t *stack,
    WINDOW *board, info_t info)
{
    management_input_action_tetris(opt);
    clear();
    wclear(board);
    display_tetris(opt, info, board, *stack);
    refresh();
    wrefresh(board);
    if (!check_usr_input(*opt, stack))
        return (1);
    return (0);
}
