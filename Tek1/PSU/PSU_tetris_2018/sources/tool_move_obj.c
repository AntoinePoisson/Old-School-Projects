/*
** EPITECH PROJECT, 2019
** management_game.c
** File description:
** management game
*/

#include <stdbool.h>
#include "my_tetris.h"

int take_obj_random(options_t *opt)
{
    random_obj_t *node = malloc(sizeof(*node));
    tetrimino_t *save = opt->map;
    int choose = (rand() % ((opt->nbr_tetrimino + 1) - 1) + 1);

    if (node == NULL)
        return (my_puterror("Error Malloc.\n"));
    for (int i = 0; i < choose && save && save->next;
        save = save->next, i++);
    if (!save->tetrimino)
        return (take_obj_random(opt));
    node->tetri = save;
    calcul_row(&choose, save->tetrimino);
    node->posi_spawn = ((opt->size.col / 2) - (choose / 2));
    node->next = NULL;
    if (opt->obj != NULL)
        opt->obj->next = node;
    else
        opt->obj = node;
    opt->level_one += 1;
    return (0);
}

void fall_block(options_t *opt)
{
    while (check_move_down(opt, opt->plan) == true)
        move_down(opt);
}

int move_down(options_t *opt)
{
    for (int i = opt->size.row - 1; i >= 0; i--)
        for (int i_two = 0; opt->plan[i][i_two]; i_two++)
            if (opt->plan[i][i_two] == 'x') {
                opt->plan[i][i_two] = ' ';
                opt->plan[i + 1][i_two] = 'o';
            }
    for (int i = 0; opt->plan[i]; i++)
        for (int i_two = 0; opt->plan[i][i_two]; i_two++)
            if (opt->plan[i][i_two] == 'o')
                opt->plan[i][i_two] = 'x';
    return (0);
}

int move_right(options_t *opt)
{
    for (int i = opt->size.row - 1; i >= 0; i--)
        for (int i_two = opt->size.col - 1; i_two >= 0; i_two--)
            if (opt->plan[i][i_two] == 'x') {
                opt->plan[i][i_two] = ' ';
                opt->plan[i][i_two + 1] = 'o';
            }
    for (int i = 0; opt->plan[i]; i++)
        for (int i_two = 0; opt->plan[i][i_two]; i_two++)
            if (opt->plan[i][i_two] == 'o')
                opt->plan[i][i_two] = 'x';
    return (0);
}

int move_left(options_t *opt)
{
    for (int i = opt->size.row - 1; i >= 0; i--)
        for (int i_two = 0; opt->plan[i][i_two]; i_two++)
            if (opt->plan[i][i_two] == 'x') {
                opt->plan[i][i_two] = ' ';
                opt->plan[i][i_two - 1] = 'o';
            }
    for (int i = 0; opt->plan[i]; i++)
        for (int i_two = 0; opt->plan[i][i_two]; i_two++)
            if (opt->plan[i][i_two] == 'o')
                opt->plan[i][i_two] = 'x';
    return (0);
}
