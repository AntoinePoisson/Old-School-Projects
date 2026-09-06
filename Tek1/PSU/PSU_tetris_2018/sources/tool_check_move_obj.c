/*
** EPITECH PROJECT, 2019
** management_game.c
** File description:
** management game
*/

#include <stdbool.h>
#include "my_tetris.h"

bool check_move(options_t *opt, char **plan, int x, int y)
{

    if (x >= (int)opt->size.row || !plan
        || !plan[x] || x < 0 || y < 0)
        return (false);
    if (y >= (int)opt->size.col || !plan[x][y])
        return (false);
    if (plan[x][y] != ' ')
        return (false);
    return (true);
}

bool check_move_left(options_t *opt, char **plan)
{
    char **save = cp_two_d(plan);

    for (int i = opt->size.row - 1; i >= 0; i--)
        for (int i_two = 0; plan[i][i_two]; i_two++) {
            if (plan[i][i_two] == 'x' &&
                check_move(opt, plan, i, i_two - 1) != true) {
                plan = save;
                opt->plan = save;
                return (false);
            } else if (plan[i][i_two] == 'x')
                plan[i][i_two] = ' ';
        }
    plan = save;
    opt->plan = save;
    return (true);
}

bool check_move_right(options_t *opt, char **plan)
{
    char **save = cp_two_d(plan);

    for (int i = opt->size.row - 1; i >= 0; i--)
        for (int i_two = opt->size.col - 1; i_two > 0; i_two--) {
            if (plan[i][i_two] == 'x' &&
                check_move(opt, plan, i, i_two + 1) != true) {
                plan = save;
                opt->plan = save;
                return (false);
            } else if (plan[i][i_two] == 'x')
                plan[i][i_two] = ' ';
        }
    plan = save;
    opt->plan = save;
    return (true);
}

bool check_move_down(options_t *opt, char **plan)
{
    char **save = cp_two_d(plan);

    for (int i = opt->size.row - 1; i >= 0; i--)
        for (int i_two = 0; plan[i][i_two]; i_two++) {
            if (plan[i][i_two] == 'x' &&
                check_move(opt, plan, i + 1, i_two) != true) {
                plan = save;
                opt->plan = save;
                return (false);
            } else if (plan[i][i_two] == 'x')
                plan[i][i_two] = ' ';
        }
    plan = save;
    opt->plan = save;
    return (true);
}
