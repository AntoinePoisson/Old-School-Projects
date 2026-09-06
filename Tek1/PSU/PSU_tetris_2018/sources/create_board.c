/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** create_map.c
*/

#include "my_tetris.h"

info_t init_info(options_t opt)
{
    info_t info;

    info.hightscore = read_file("./config/hightscore");
    if (!info.hightscore)
        return (info);
    info.score = 0;
    info.lines = 0;
    info.min = 0;
    info.sec = 0;
    opt.obj = NULL;
    opt.plan = NULL;
    info.level = opt.level;
    return (info);
}

char **create_border(options_t *opt)
{
    char **map = my_malloc_two_d(opt->size.row + 3);

    if (!map)
        return (NULL);
    for (unsigned int i = 0; i < opt->size.row + 2; i++) {
        map[i] = my_malloc(opt->size.col + 2);
        if (!map[i])
            return (NULL);
        for (unsigned int j = 0; j < opt->size.col + 2; j++) {
            map[i][j] = (i == 0 || i == (opt->size.row + 1)) ? '-' : ' ';
            map[i][j] = (j == 0 || j == (opt->size.col + 1)) ? '|' : map[i][j];
            if ((i == 0 || (i == opt->size.row + 1)) &&
                (j == 0 || (j == opt->size.col + 1)))
                map[i][j] = '+';
        }
    }
    opt->level_one = 0;
    opt->obj = NULL;
    return (map);
}

char **init_map(options_t *opt)
{
    char **map = my_malloc_two_d(opt->size.row + 1);

    if (!map)
        return (NULL);
    for (unsigned int i = 0; i < opt->size.row; i++) {
        map[i] = my_malloc(opt->size.col + 1);
        if (!map[i])
            return (NULL);
        for (unsigned int j = 0; j < opt->size.col; j++) {
            map[i][j] = ' ';
        }
    }
    opt->obj = NULL;
    return (map);
}
