/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris.c
*/

#include <dirent.h>
#include "my_tetris.h"

int fall_tetrimino(options_t *opt)
{
    static unsigned int a = 0;

    if (a++ > opt->speed) {
        move_down(opt);
        a = 0;
    }
    return (0);
}

int main_loop(options_t *opt, info_t info)
{
    WINDOW *board = newwin(opt->size.row + 2, opt->size.col + 2, 0, 30);
    time_t stack = time(NULL);

    if (take_obj_random(opt) == 84 || take_obj_random(opt) == 84)
        return (84);
    for (opt->quit = false; opt->quit != true; ) {
        if (insert_obj(opt, opt->obj->tetri->tetrimino) == 84)
            return (0);
        while (check_move_down(opt, opt->plan) && opt->quit != true) {
            if (managemet_display_tetris(opt, &stack, board, info) == 1)
                return (0);
            fall_tetrimino(opt);
        }
        change_select_obj(opt);
        check_kill_line(opt);
        opt->obj = opt->obj->next;
        if (take_obj_random(opt) == 84)
            return (84);
    }
    return (0);
}

int tetris(char const **av)
{
    int res = 0;
    info_t info;
    options_t opt = init_opt();

    if (check_tetriminos() || !opt.level ||
        analyze_flags_opt(av, &opt) || debug_mode(&opt))
        return (EXIT_ERROR);
    info = init_info(opt);
    if (opt.map == NULL || !info.hightscore)
        return (EXIT_SUCCESS);
    opt.plan = init_map(&opt);
    init_screen();
    if (set_newterm())
        return (EXIT_FAILURE);
    opt.border = create_border(&opt);
    if (opt.border == NULL)
        return (84);
    res = main_loop(&opt, info);
    endwin();
    return (res);
}
