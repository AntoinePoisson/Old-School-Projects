/*
** EPITECH PROJECT, 2019
** analyze_tetriminos.c
** File description:
** analyzation of tetriminos directory
*/

#include "my_tetris.h"

int calcul_row(int *col, char **str)
{
    int row = 0;
    int find_block = 0;
    int save_col = 0;

    for (int i = 1; str[i]; i++, find_block = 0, *col = 0) {
        *col = is_extension_calcul_row(str, &i, &find_block);
        if (save_col <= *col)
            save_col = *col;
        if (find_block == 0)
            break;
        row += 1;
    }
    *col = save_col;
    return (row);
}

int control_right_file(char **str, int cas)
{
    if (cas == 0) {
        for (int i_two = 0; str && str[0][i_two]; i_two++)
            if (str[0][i_two] != ' ' && !(str[0][i_two] >= '0' &&
                str[0][i_two] <= '9'))
                return (84);
        return (0);
    }
    for (int i = 1; str && str[i]; i++)
        for (int i_two = 0; str[i][i_two]; i_two++)
            if (str[i][i_two] != ' ' && str[i][i_two] != '*')
                return (84);
    return (0);
}

void control_right_data(options_t *opt, char **str)
{
    int col = 0;
    int row = calcul_row(&col, str);

    if (opt->map->col <= 0 || opt->map->row <= 0 ||
        control_right_file(opt->map->tetrimino, 1) == 84) {
        free(opt->map->tetrimino);
        opt->map->tetrimino = NULL;
    }
    if (row != opt->map->row || col != opt->map->col || opt->map->color > 7 ||
        opt->map->color == -1) {
        free(opt->map->tetrimino);
        opt->map->tetrimino = NULL;
        return;
    }
}

static void take_more_data(options_t *opt)
{
    char *str = NULL;
    int size = 0;

    if (opt->map == NULL || opt->map->tetrimino == NULL ||
        opt->map->tetrimino[0] == NULL)
        return;
    str = opt->map->tetrimino[0];
    for (; str[size] == ' ' && str[size]; size++);
    opt->map->col = my_getnbr(&str[size]);
    for (; str[size] != ' ' && str[size]; size++);
    for (; str[size] == ' ' && str[size]; size++);
    opt->map->row = my_getnbr(&str[size]);
    for (; str[size] != ' ' && str[size]; size++);
    for (; str[size] == ' ' && str[size]; size++);
    if (str[size] != ' ' && str[size])
        opt->map->color = my_getnbr(&str[size]);
}

int take_data(options_t *opt, char *name)
{
    int fd = open(my_strcat("./tetriminos/", name), O_RDONLY);
    int size = stat_size(my_strcat("./tetriminos/", name));
    char *buffer = my_malloc((size + 2));

    if (fd == -1 || buffer == NULL || size == 0)
        return (1);
    if (add_node(opt) == 84 || read(fd, buffer, size) < 1)
        return (84);
    if ((opt->map->tetrimino = my_str_to_word_array(buffer)) == NULL)
        return (84);
    opt->map->name = change_name_of_file(name);
    if (opt->map->tetrimino == NULL || opt->map->tetrimino[0]
        == NULL || control_right_file(opt->map->tetrimino, 0) == 84)
        return (1);
    take_more_data(opt);
    control_right_data(opt, opt->map->tetrimino);
    close(fd);
    free(buffer);
    return (0);
}