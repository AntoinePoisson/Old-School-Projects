/*
** EPITECH PROJECT, 2019
** management_game.c
** File description:
** management game
*/

#include <stdbool.h>
#include "my_tetris.h"

void change_select_obj(options_t *opt)
{
    for (int i = 0; opt->plan[i]; i++)
        for (int i_two = 0; opt->plan[i][i_two]; i_two++)
            if (opt->plan[i][i_two] == 'x')
                opt->plan[i][i_two] = (opt->obj->tetri->color + '0');
}

int insert_obj(options_t *opt, char **tetrimino)
{
    int y = opt->obj->posi_spawn;

    if (tetrimino == NULL)
        return (84);
    for (int i = 0; tetrimino[i]; i++)
        for (int i_two = 0; tetrimino[i][i_two]; i_two++)
            if (tetrimino[i][i_two] == '*') {
                if (check_move(opt, opt->plan, i, i_two + y) == false)
                    return (84);
                opt->plan[i][i_two + y] = 'x';
            }
    return (0);
}

int kill_line(options_t *opt, int line)
{
    for (int i = 0; opt->plan[line][i]; i++)
        opt->plan[line][i] = ' ';
    for (line -= 1; line <= 0; line--)
        for (int i = 0; opt->plan[line][i]; i++)
            opt->plan[line + 1][i] = opt->plan[line][i];
    return (0);
}

int check_kill_line(options_t *opt)
{
    int count = 0;

    for (int i = 0; opt->plan[i]; i++) {
        for (count = 0; opt->plan[i][count] &&
            opt->plan[i][count] != ' '; count++);
        if (opt->plan[i][count] == '\0') {
            kill_line(opt, i);
            i = 0;
        }
    }
    return (0);
}
